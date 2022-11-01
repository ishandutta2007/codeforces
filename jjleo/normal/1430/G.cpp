#include <bits/stdc++.h>
#define maxn 18

using namespace std;

typedef long long ll;

int n, m;
ll val[maxn];
int x, y, z;
int b[maxn];
vector<int> v[maxn], w;

int deg[maxn];
queue<int> q;

ll f[maxn][maxn + 1][1 << maxn];
bool g[maxn][maxn + 1][1 << maxn];
int ans[maxn];


int main(){
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		val[--x] += z, val[--y] -= z;
		v[x].push_back(y), deg[y]++;
		b[x] |= (1 << y);
	}
	for(int i = 0;i < n;i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int x = q.front();q.pop();
		w.push_back(x);
		for(int i = 0;i < v[x].size();i++){
			int to = v[x][i];
			if(!(--deg[to])) q.push(to);
		}
	}
	memset(f, 0x3f, sizeof(f)), f[0][0][0] = 0;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			int x = w[j];
			for(int k = 0;k < (1 << n);k++) f[i][j + 1][k] = f[i][j][k];
			for(int k = 0;k < (1 << n);k++){
				if((k & b[x]) != b[x] || (k & (1 << x))) continue;
				int kk = k | (1 << x);
				if(f[i][j + 1][kk] > f[i][j][k] + i * val[x]){
					f[i][j + 1][kk] = f[i][j][k] + i * val[x];
					g[i][j + 1][kk] = true;
				}
			} 
		}
		if(i + 1 < n) for(int k = 0;k < (1 << n);k++) f[i + 1][0][k] = f[i][n][k];
	}
	//for(int i = 0;i < n;i++) for(int j = 0;j <= n;j++) for(int k = 0;k < (1 << n);k++) printf("%d %d %d %lld %d--\n", i, j, k, f[i][j][k], g[i][j][k]);
	int i = n - 1, j = n, k = (1 << n) - 1;
	while(k){
		if(!j) j = n, i--;
		if(g[i][j][k]) ans[w[j - 1]] = i, k ^= 1 << w[j - 1];
		j--;
	}
	for(int i = 0;i < n;i++) printf("%d ", ans[i]);
}