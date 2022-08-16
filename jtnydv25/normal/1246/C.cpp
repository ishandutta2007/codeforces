#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

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
const int mod = 1e9 + 7;
const int N = 2005;
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
char s[N][N];
int dp[2][N][N], dp2[2][N][N];
int num[2][N][N];
int main(){
	int n = 2000, m = 2000;
	sd(n), sd(m);
	for(int i = 1; i <= n; i++){
		// for(int j = 1; j <= m; j++) s[i][j] = (rand() % 1000) ? '.' : 'R';
		scanf("%s", s[i] + 1);
	}
	for(int i = n; i >= 1; i--){
		for(int j = m; j >= 1; j--){
			num[0][i][j] = num[0][i][j + 1] + (s[i][j] == 'R');
			num[1][i][j] = num[1][i + 1][j] + (s[i][j] == 'R');
			if(i == n) dp[0][i][j] = (num[0][i][j] == 0);
			if(j == m) dp[1][i][j] = (num[1][i][j] == 0);
			int mxj = m - num[0][i][j];
			int mxi = n - num[1][i][j];
			if(i != n) dp[0][i][j] = sub(dp2[1][i + 1][j], dp2[1][i + 1][mxj + 1]);
			if(j != m) dp[1][i][j] = sub(dp2[0][i][j + 1], dp2[0][mxi + 1][j + 1]);

			dp2[0][i][j] = add(dp[0][i][j], dp2[0][i + 1][j]);
			dp2[1][i][j] = add(dp[1][i][j], dp2[1][i][j + 1]);
		}
	}
	// trace(dp[0][1][1], dp[1][1][1]);
	assert(dp[0][1][1] == dp[1][1][1]);
	printf("%d\n", dp[0][1][1]);
}