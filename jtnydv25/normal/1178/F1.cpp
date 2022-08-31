#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())


template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<",";
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
const int N = 505;
const int mod = 998244353;
int c[N], pos[N];
int dp[N][N], dp2[N][N];
int done[N][N], done2[N][N];
int mn[N][N];

inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}

int getDP2(int i, int j);

int getDP(int i, int j){
	if(done[i][j]) return dp[i][j];
	if(i == j) return 1;
	int minv = mn[i][j];
	int p = pos[minv];
	
	int ret = mul(getDP2(i, p - 1), getDP2(p + 1, j));
	done[i][j] = 1;
	// trace(i, j, p, ret);
	return dp[i][j] = ret;
}
int getDP2(int i, int j){
	if(i > j) return 1;
	if(i == j) return 2;
	if(done2[i][j]) return dp2[i][j];
	int ret = mul(2, getDP(i, j));
	for(int k = i; k < j; k++) ret = add(ret, mul(getDP(i, k), getDP(k + 1, j)));
	done2[i][j] = true;
	return dp2[i][j] = ret;
}
int main(){
	int n, m;
	sd(n); sd(m);
	for(int i = 1; i <= n; i++){
		sd(c[i]);
		pos[c[i]] = i;
		for(int j = 1; j <= i; j++){
			mn[j][i] = (j == i) ? c[i] : min(c[i], mn[j][i - 1]);
		}
	}

	printf("%d\n", getDP(1, n));	
}