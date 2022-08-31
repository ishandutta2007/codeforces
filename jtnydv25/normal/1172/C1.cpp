#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

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
const int mod = 998244353;
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
const int N = 200005;
int a[N], w[N];
const int M = 3005;
int dp[M][M];
int main(){
	int n, m;
	sd(n);
	sd(m);
	int total_like = 0, total_dislike = 0;
	for(int i = 1; i <= n; i++){
		int k; sd(k);
		a[i] = k;
	}
	for(int i = 1; i <= n; i++){
		sd(w[i]);
		if(a[i]) total_like = add(total_like, w[i]);
		else total_dislike = add(total_dislike, w[i]);
	}
	int W = add(total_like, total_dislike);
	dp[0][0] = 1;
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < i && j <= total_dislike; j++){
			// j dislikes
			// _j likes
			int _j = i - 1 - j;
			int now = W - j + _j;
			int invnow = inv(now);
			dp[i][j + 1] = add(dp[i][j + 1], mul(dp[i - 1][j], mul(total_dislike - j, invnow)));
			dp[i][j] = add(dp[i][j], mul(dp[i - 1][j], mul(total_like + _j, invnow)));
		}
	}

	int E_dislike = 0;
	for(int i = 0; i <= total_dislike && i <= m; i++)
		E_dislike = add(E_dislike, mul(i, dp[m][i]));
	
	int E_like = sub(m, E_dislike);
	// trace(E_like, E_dislike);
	for(int i = 1; i <= n; i++){
		if(a[i]) printf("%d ", add(w[i], mul(E_like, mul(w[i], inv(total_like)))));
		else printf("%d\n", sub(w[i], mul(E_dislike, mul(w[i], inv(total_dislike)))));
	}
}