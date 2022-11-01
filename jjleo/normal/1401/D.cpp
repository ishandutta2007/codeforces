#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

const int p = 1e9 + 7;

int t;
int n, m;
vector<int> v[maxn];
int x, y;
int siz[maxn];
vector<ll> a; 
int b[maxn];

void dfs(int i, int fa){
	siz[i] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		dfs(to, i);
		a.push_back(1ll * siz[to] * (n - siz[to]));
		siz[i] += siz[to];
	}
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear();
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		a.clear();
		dfs(1, 0);
		sort(a.begin(), a.end(), greater<ll>());
		scanf("%d", &m);
		for(int i = 1;i <= m;i++) scanf("%d", &b[i]);
		sort(b + 1, b + 1 + m, greater<int>());
		int j = 1, ans = 0;
		for(int i = 0;i < a.size();i++){
			if(j == m + 1){
				ans = (ans + a[i]) % p;
				continue;
			}else if(i == 0){
				int x = b[j++];
				while(m - j >= n - 2 && j <= m) x = 1ll * x * b[j++] % p;
				ans = (ans + a[i] % p * x) % p;
			}else{
				ans = (ans + a[i] % p * b[j++]) % p;
			}
		}
		printf("%d\n", ans);
	}
}