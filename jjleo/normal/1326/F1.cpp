#include <bits/stdc++.h>
#define maxn 19

using namespace std;

typedef long long ll;

void OR(ll *a, int lim, int type){
	for(int mid = 1;mid * 2 <= lim;mid <<= 1){
		for(int i = mid << 1, j = 0;j < lim;j += i){
			for(int k = 0;k < mid;k++){
				a[j + k + mid] += type * a[j + k];
			}
		}
	}
}

void AND(ll *a, int lim, int type){
	for(int mid = 1;mid < lim;mid <<= 1){
		for(int i = mid << 1, j = 0;j < lim;j += i){
			for(int k = 0;k < mid;k++){
				a[j + k] += type * a[j + k + mid];
			}
		}
	}
}

int n;
char s[maxn][maxn];
vector<vector<int> > v;
map<vector<int>, int> mp;
vector<int> w;
vector<ll> V;

void dfs(int i, int sum){
	if(sum == n){
		v.push_back(w);
		mp[w] = v.size() - 1;
		return;
	}
	for(int j = i;sum + j <= n;j++){
		w.push_back(j);
		dfs(j, sum + j);
		w.pop_back();
	}
}

ll f[maxn][1 << maxn], g[maxn][1 << maxn], h[1 << maxn], H[1 << maxn];

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++) scanf("%s", s[i]);
	dfs(1, 0);
	for(int i = 0;i < n;i++) f[i][1 << i] = 1;
	for(int j = 0;j < (1 << n);j++){
		for(int i = 0;i < n;i++){
			for(int k = 0;k < n;k++){
				if(s[i][k] == '0' || (j & (1 << k))) continue;
				f[k][j | (1 << k)] += f[i][j];
			}
			g[__builtin_popcount(j)][j] += f[i][j];
		}
	}
	int lim = 1 << n;
	for(int i = 1;i <= n;i++) OR(g[i], lim, 1);
	/*for(int i = 1;i <= n;i++){
		for(int j = 0;j < lim;j++) printf("%d ", g[i][j]);
		puts("");
	}*/
	H[0] = 1;OR(H, lim, 1);
	for(int i = 0;i < v.size();i++){
		for(int j = 0;j < lim;j++) h[j] = H[j];
		vector<int> w = v[i];
		for(int j = 0;j < w.size();j++) for(int k = 0;k < lim;k++) h[k] *= g[w[j]][k];
		OR(h, lim, -1);
		V.push_back(h[lim - 1]);
	}
	lim >>= 1;
	for(int i = 0;i < lim;i++){
		int x = 1;
		vector<int> w;
		for(int j = 0;j < n - 1;j++){
			if(i & (1 << j)) x++;
			else w.push_back(x), x = 1;
		}
		w.push_back(x);
		sort(w.begin(), w.end());
		h[i] = V[mp[w]];
	}
	AND(h, lim, -1);
	for(int i = 0; i < lim;i++) printf("%lld ", h[i]);
}