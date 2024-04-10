#include <bits/stdc++.h>
#define maxn 205

using namespace std;

const int p = 1e9 + 7, inv2 = p + 1 >> 1;

inline int fpow(int x, int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

int n;
vector<int> v[maxn];
int x, y;
int d[maxn], f[maxn][maxn], ans;

vector<int> dfs(int i, int fa){
	d[i] = d[fa] + 1;
	vector<int> a = {i};
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		vector<int> b = dfs(to, i);
		for(int k = 0;k < a.size();k++){
			for(int l = 0;l < b.size();l++){
				ans = (ans + (a[k] > b[l] ? f[d[a[k]] - d[i]][d[b[l]] - d[i]] : f[d[b[l]] - d[i]][d[a[k]] - d[i]])) % p;
			}
		}
		a.insert(a.end(), b.begin(), b.end());
	}
	return a;
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x); 
	}
	for(int i = 1;i <= n;i++) f[0][i] = 1;
	for(int i = 1;i <= n;i++) for(int j = 1;j <= n;j++) f[i][j] = 1ll * (f[i - 1][j] + f[i][j - 1]) * inv2 % p;
	for(int i = 1;i <= n;i++) dfs(i, 0);
	printf("%d", 1ll * ans * fpow(n, p - 2) % p);
}