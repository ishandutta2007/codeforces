#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())


#ifdef LOCAL
#define cerr cout
#else
#endif

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int mod =1e9 + 7;
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

const int N = 55;
struct dt{
	vector<int> vals;
	vector<vector<int>> dp, dp_prefix;
	int n, m;
	dt(){}
	dt(vector<int> v) : n(v.size()), m(N * v.size()), vals(v), dp(v.size() + 1, vector<int>(v.size() * N + 10, 0)){
		dp[0][0] = 1;
		for(auto it : vals){
			for(int i = n; i >= 1; i--)
			for(int j = m; j >= it; j--)
				dp[i][j] = add(dp[i][j], dp[i - 1][j - it]);
		}
		// dp_prefix[0][0] = 1;
		// for(int i = 1; i <= n; i++)
		// 	for(int j = 0; j <= m; j++)
		// 		dp_prefix[i][j] = add(dp_prefix[i - 1][j], dp[i][j]);
	}
} D[3];
vector<int> v[3];
int num[N + 1][N + 1][N + 1][3], total[N][N][N], fact[N];
int main(){
	num[0][0][1][2] = num[0][1][0][1] = num[1][0][0][0] = 1;

	for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)
	for(int k = 0; k < N; k++) if(i + j + k >= 1){
		int x[3] = {i, j, k};
		int y[3] = {i, j, k};
		for(int l = 0; l < 3; l++)
			for(int newl = 0; newl < 3; newl++){
				if(l != newl){
					x[newl]++;
					num[x[0]][x[1]][x[2]][newl] = add(num[x[0]][x[1]][x[2]][newl], num[y[0]][y[1]][y[2]][l]);
					x[newl]--;
				}
			}
	}
	fact[0] = 1;
	for(int i = 1; i < N; i++) fact[i] = mul(fact[i - 1], i);
	for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)
	for(int k = 0; k < N; k++){
		total[i][j][k] = add(num[i][j][k][0], add(num[i][j][k][1], num[i][j][k][2]));
		total[i][j][k] = mul(total[i][j][k], mul(fact[i], mul(fact[j], fact[k])));
	}
	int n, T;
	sd(n); sd(T);
	for(int i = 1; i <= n; i++){
		int t, x;
		sd(x); sd(t); t--;
		v[t].push_back(x);
	}
	for(int i = 0; i < 3; i++)
		D[i] = dt(v[i]);

	int ans = 0;
	for(int i = 0; i <= (int)v[0].size(); i++)
		for(int j = 0; j <= (int)v[1].size(); j++){
			int mx = max(i, j), mn = i + j - mx;
			// mx <= k + mn + 1
			// k <= i + j + 1
			int mn_k = max(0, mx - mn - 1);
			int mx_k = min((int)v[2].size(),  i + j + 1);
			for(int s1 = 0; s1 <= i * N; s1++)
				for(int s2 = 0; s2 <= j * N && s1 + s2 <= T; s2++){
					int s3 = T - s1 - s2;
					int ways = mul(D[0].dp[i][s1], D[1].dp[j][s2]);
					if(!ways || s3 > N * D[2].n) continue;
					int sm = 0;
					for(int k = mn_k; k <= mx_k; k++){
						sm = add(sm, mul(total[i][j][k], D[2].dp[k][s3]));
					}
					ans = add(ans, mul(ways, sm));
				}
		}
	printf("%d\n", ans);
}