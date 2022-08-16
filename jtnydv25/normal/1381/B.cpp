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

const int N = 5005;
bool dp[N][N][2];
int p[N];
bool isPM[N];
int main(){
	int t; sd(t);
	while(t--){
		int n; sd(n);
		int mx = 0;
		
		for(int i = 1; i <= 2 * n; i++){
			sd(p[i]);
			isPM[i] = p[i] > mx;
			mx = max(mx, p[i]);
			for(int j = 1; j <= n; j++) dp[i][j][0] = dp[i][j][1] = 0;
		}

		dp[0][0][0] = 1;

		for(int i = 0; i < 2 * n; i++){
			for(int sm = 0; sm <= n; sm++) for(int type = 0; type < 2; type++) if(dp[i][sm][type]){
				dp[i + 1][sm + (type == 0)][type] = 1;
				if(isPM[i + 1]){
					dp[i + 1][sm + (type == 1)][type ^ 1] = 1;
				}
			}
		}

		printf(dp[2 * n][n][0] || dp[2 * n][n][1] ? "YES\n" : "NO\n");
	}
}