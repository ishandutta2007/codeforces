#include <bits/stdc++.h>
#define maxn 200086
using namespace std;

const int p = 998244353;

int n;
vector<pair<int, int> > v[maxn];
int x, y;
int f[maxn][4];
int a[maxn], b[maxn]; 

void dfs(int i, int fa, int x){
	f[i][1] = f[i][3] = 1;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first;
		if(to == fa) continue;
		dfs(to, i, v[i][j].second);
	}
	int cnt = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first;
		if(to == fa) continue;
		a[++cnt] = (f[to][0] + f[to][1]) % p;
		b[cnt] = (1ll * f[to][0] + f[to][2] + f[to][3]) % p;
		if(v[i][j].second < x) f[i][1] = 1ll * f[i][1] * a[cnt] % p;
		else f[i][1] = 1ll * f[i][1] * b[cnt] % p;
		f[i][3] = 1ll * f[i][3] * a[cnt] % p;
	}
	a[0] = b[cnt + 1] = 1;
	for(int j = 1;j <= cnt;j++) a[j] = 1ll * a[j] * a[j - 1] % p;
	for(int j = cnt;j;j--) b[j] = 1ll * b[j] * b[j + 1] % p;
	cnt = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j].first;
		if(to == fa) continue;
		++cnt;
		if(v[i][j].second < x){
			f[i][0] += 1ll * (f[to][2] + f[to][3]) * a[cnt - 1] % p * b[cnt + 1] % p;
			if(f[i][0] >= p) f[i][0] -= p;
		}else{
			f[i][2] += 1ll * (f[to][2] + f[to][3]) * a[cnt - 1] % p * b[cnt + 1] % p;
			if(f[i][2] >= p) f[i][2] -= p;
		}
	}
	//printf("%d %d %d %d %d--\n", i, f[i][0], f[i][1], f[i][2], f[i][3]);
}

int main(){
	scanf("%d", &n);
	for(int i = 1;i < n;i++){
		scanf("%d%d", &x, &y);
		v[x].push_back({y, i});
		v[y].push_back({x, i});
	}
	dfs(1, 0, 0);
	printf("%d", (f[1][2] + f[1][3]) % p);
}