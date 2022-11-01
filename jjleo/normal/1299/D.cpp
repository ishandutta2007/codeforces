#include <bits/stdc++.h>
#define maxn 100086
using namespace std;

const int p = 1e9 + 7;

struct Basis{
	int a[5], siz;
	bool fail;
	
	inline void insert(int x){
		if(!x) fail = true;//debug:0  
		//if(fail) return;// debug:  
		int i = 4;
		for(int j = 1 << i;j;j >>= 1, i--){
			if(x & j){
				if(!a[i]){
					a[i] = x, siz++;
					return;
				}else{
					x ^= a[i];
				}
			}
		}
		fail = true;
	}
	
	inline Basis(){
		memset(a, 0, sizeof(a)), siz = 0, fail = false;
	}
	
	inline int & operator [] (int i){
		return a[i];
	}

}; 

inline Basis merge(Basis x, Basis y){
	for(int i = 0;i < 5;i++) if(x[i]) y.insert(x[i]);//debug0 
	return y;
}

Basis bas[400];
int cnt;
int h[400][400];

int newBasis(Basis b){
	for(int i = 0;i <= cnt;i++){
		if(bas[i].siz == b.siz && merge(bas[i], b).siz == b.siz) return i;
	}
	bas[++cnt] = b;
	return cnt;
}

struct Edge{
	int x, y;
};

vector<Edge> v[maxn];
int f[maxn], dep[maxn], val;
int g[maxn][4], tot;
int dp[2][400];
Basis b;

void dfs(int i, int fa){
	dep[i] = dep[fa] + 1;
	for(int j = 0;j < v[i].size();j++){
		if(v[i][j].x == fa) continue;
		if(i == 1){
			val = -1;
			b = Basis(); 
		}
		if(f[v[i][j].x] == -1){
			f[v[i][j].x] = f[i] ^ v[i][j].y;
			dfs(v[i][j].x, i);
		}else{
			if(dep[v[i][j].x] > dep[i]) continue;//debug:  
			if(v[i][j].x ^ 1) b.insert(f[i] ^ f[v[i][j].x] ^ v[i][j].y);
			else val = f[i] ^ f[v[i][j].x] ^ v[i][j].y;
		}
		if(i == 1){
			++tot;
			if(val == -1){
				if(b.fail) g[tot][0] = -1;
				else g[tot][0] = newBasis(b);
				g[tot][1] = g[tot][2] = -1;
			}else{
				if(b.fail) g[tot][0] = g[tot][1] = -1;
				else g[tot][0] = g[tot][1] = newBasis(b);
				
				//debug: 
				b.insert(val);
				if(b.fail) g[tot][2] = -1;
				else g[tot][2] = newBasis(b);
			}
		}
	}
}

int n, m;
int x, y, z;
int ans;

int main(){
	memset(f, -1, sizeof(f));
	memset(h, -1, sizeof(h));
	scanf("%d%d", &n, &m);
	while(m--){
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back((Edge){y, z}), v[y].push_back((Edge){x, z});
	}
	f[1] = 0;//debug: 
	dfs(1, 0);
	dp[0][0] = 1;
	for(int i = 1;i <= tot;i++){
		for(int j = 0;j <= cnt;j++){
			if(!dp[0][j]) continue;
			for(int k = 0;k < 4;k++){
				if(g[i][k] == -1) continue;
				if(h[j][g[i][k]] == -1){
					Basis a = bas[j], b = bas[g[i][k]], c = merge(a, b);
					if(c.fail) h[j][g[i][k]] = h[g[i][k]][j] = -2;
					else h[j][g[i][k]] = h[g[i][k]][j] = newBasis(c); 
				}
				//printf("%d %d %d--\n", i, k, g[i][k]);
				if(h[j][g[i][k]] != -2){
					//printf("%d---\n", k);
					dp[1][h[j][g[i][k]]] += dp[0][j];
					//printf("%d %d %d--\n", h[j][g[i][k]], j, dp[1][h[j][g[i][k]]]);
					if(dp[1][h[j][g[i][k]]] >= p) dp[1][h[j][g[i][k]]] -= p;
				}
			}
		}
		memcpy(dp[0], dp[1], sizeof(dp[1]));
		memset(dp[1], 0, sizeof(dp[1]));//debug:0 
	}
	for(int i = 0;i <= cnt;i++){
		ans += dp[0][i];
		if(ans >= p) ans -= p;
	}
	printf("%d", ans);
}