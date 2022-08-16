#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define sd(x) scanf("%d", &x)
const int mod = 1e9 + 7;

inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

const int N = 1e5 + 10;

int dp[3][11][N];
int dp2[2][2][11], dp3[2][2][11];

vi con[N];

int n, m, k, x;

void ADD(int &a, int b){
	a += b;
	if(a >= mod) a -= mod;
}

void dfs(int s, int p){
	for(int v : con[s]){
		if(v != p){
			dfs(v, s);
		}
	}

	memset(dp2, 0, sizeof dp2);

	dp2[0][0][0] = 1;
	int cnt = 0;
	for(int v : con[s]){
		if(v != p){
			memcpy(dp3, dp2, sizeof dp3);
			memset(dp2, 0, sizeof dp2);
			cnt++;
			for(int i = 0; i < 2; i++){
				for(int j = 0; j < 2; j++){
					for(int l = 0; l <= x; l++){
						int val = dp3[i][j][l];
						for(int num = 0; num + l <= x; num++){
							int total = num + l;
							// take < k
							ADD(dp2[i][j][total], mul(val, dp[0][num][v]));
							// take k
							ADD(dp2[i | 1][j][total], mul(val, dp[1][num][v]));
							// take > k
							ADD(dp2[i][j | 1][total], mul(val, dp[2][num][v]));
						}
					}
				}
			}
		}
	}
	// if(s == 4){
	// 	cerr << cnt << " " << dp2[0][0][0] << endl;
	// }
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int l = 0; l <= x; l++){
				int val = dp2[i][j][l];
				// color k

				if(!j && !i && l + 1 <= x){
					ADD(dp[1][l + 1][s], val);
				}

				// color < k. Can always do that
				ADD(dp[0][l][s], mul(k - 1, val));

				// color > k

				if(!i)
					ADD(dp[2][l][s], mul(m - k, val));
			}
		}
	}

}

int main(){
	sd(n); sd(m);
	for(int i = 1; i < n; i++){
		int u, v;
		sd(u); sd(v);
		con[u].pb(v);
		con[v].pb(u);
	}
	sd(k);
	sd(x);
	dfs(1, 0);
	int ans = 0;
	for(int j = 0; j < 3; j++)
		for(int i = 0; i <= x; i++)
			ans = add(ans, dp[j][i][1]);
	
	// cerr << dp[0][0][4] << " " << dp[1][1][4] << " " << dp[2][0][4] << endl;		
	printf("%d", ans);
}