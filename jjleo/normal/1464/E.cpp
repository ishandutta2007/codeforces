#include <bits/stdc++.h>
#define maxn 100086
#define maxm 555

using namespace std;

const int p = 998244353;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

int n, m;
int x, y;
vector<int> v[maxn];
int sg[maxn], cnt[maxm];

void dfs(int i){
	if(~sg[i]) return;
	for(int j = 0;j < v[i].size();j++) dfs(v[i][j]);
	bool a[600] = {0};
	for(int j = 0;j < v[i].size();j++) a[sg[v[i][j]]] = 1;
	for(int j = 0;;j++){
		if(!a[j]){
			++cnt[sg[i] = j];
			return;
		}
	}
}

int a[maxm][maxm];

int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}
	memset(sg, -1, sizeof(sg));
	for(int i = 1;i <= n;i++) dfs(i);
	int inv = fpow(n + 1, p - 2);
	n = 512;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			a[i][j] = 1ll * cnt[i ^ j] * inv % p;
		}
		a[i][i] = (a[i][i] + p - 1) % p;
		if(i) a[i][n] = (p - inv) % p;
	}
	for(int i = 0;i < n;i++){
		if(!a[i][i]){
			for(int j = i + 1;j < n;j++){
				if(a[j][i]){
					for(int k = 0;k <= n;k++) swap(a[i][k], a[j][k]);
					break;
				}
			}
		}
		int inv = fpow(a[i][i], p - 2);
		for(int j = 0;j <= n;j++) a[i][j] = 1ll * a[i][j] * inv % p;
		for(int j = 0;j < n;j++){
			if(i == j) continue;
			for(int k = 0;k <= n;k++){
				if(k == i) continue;
				a[j][k] = (a[j][k] + p - 1ll * a[j][i] * a[i][k] % p) % p;
			}
			a[j][i] = 0;
		}
	}
	printf("%d", a[0][n]);
}