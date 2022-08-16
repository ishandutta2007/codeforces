#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))

const int mod = 998244353;
inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}

const int K = 80;
const int N = 4005;
int C[K][K];
int down[N][K], sumdown[N][K], up[N][K], dp[K];

struct tree{
	int n;
	vector<vector<int> > con;
	vector<int> cycles;
	tree(int n) : n(n), con(n + 1), cycles(K){
		memset(down, 0, sizeof down);
		memset(up, 0, sizeof up);
		memset(sumdown, 0, sizeof sumdown);
	}

	void add_edge(int a, int b){
		con[a].push_back(b);
		con[b].push_back(a); 		
	}	

	void dfs(int s = 1, int p = -1){
		down[s][0] = 1;
		for(int v : con[s]) if(v != p) {
			dfs(v, s);	
			for(int t = 0; t < K; t += 2) sumdown[s][t] = add(sumdown[s][t], down[v][t]);
		}

		for(int t = 2; t < K; t += 2){
			for(int r = 0; r <= t - 2; r += 2){
				down[s][t] = add(down[s][t], mul(sumdown[s][r], down[s][t - r - 2]));
			}
		}
	}

	void dfs2(int s = 1, int p = -1){
		if(s != 1){
			up[s][0] = 1;
			for(int t = 2; t < K; t += 2){
				for(int r = 0; r <= t - 2; r += 2){
					up[s][t] = add(up[s][t], mul(up[s][t - r - 2], add(up[p][r], sub(sumdown[p][r], down[s][r]))));
				}
			}
		}

		memset(dp, 0, sizeof dp);

		dp[0] = 1;
		cycles[0] ++;
		for(int t = 2; t < K; t += 2){
			for(int r = 0; r <= t - 2; r += 2){
				int sm = 0;
				dp[t] = add(dp[t], mul(add(sumdown[s][r], up[s][r]), dp[t - r - 2]));
			}
			cycles[t] = add(cycles[t], dp[t]);
		}

		for(int v : con[s]){
			if(v != p){
				dfs2(v, s);
			}
		}
	}

	vector<int> getCycles(int k){
		dfs();
		dfs2();
		cycles.resize(k + 1);
		return cycles;
	}
};


int main(){
	for(int i = 0; i < K; i++){
		C[i][0] = 1;
		for(int j = 1; j <= i; j++) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	}

	int n1, n2, k;
    sd(n1); sd(n2); sd(k);
    tree T1(n1);
    for(int i = 1; i < n1; i++){
        int u, v;
        sd(u); sd(v);
        T1.add_edge(u, v);
    }
    vector<int> cycles1 = T1.getCycles(k);
    tree T2(n2);
    
    for(int i = 1; i < n2; i++){
        int u, v;
        sd(u); sd(v);
        T2.add_edge(u, v);
    }

    vector<int> cycles2 = T2.getCycles(k);
    int ans = 0;
    for(int i = 0; i <= k; i++) ans = add(ans, mul(C[k][i], mul(cycles2[i], cycles1[k - i])));
    printf("%d\n", ans);
}