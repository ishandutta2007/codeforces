#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
const int N = 5005;
int dp[N][N];
const int INF = 1e9;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	for(int i = 0; i < N; i++){
		fill(dp[i], dp[i] + N, -INF);
	}
	dp[n][m] = 0;
	dp[n - 1][m] = dp[n][m - 1] = -1;
	int ans = 0;
	for(int i = n - 1; i >= 0; i--){
		for(int j = m - 1; j >= 0; j--){
			if(s[i] == t[j]){
				dp[i][j] = max(2, 2 + dp[i + 1][j + 1]);
			} else{
				dp[i][j] = max(-2, max(dp[i + 1][j] - 1, dp[i][j + 1] - 1));
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}