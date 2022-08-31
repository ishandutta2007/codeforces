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

const int N = 105;
int dp[N][N][2];
int a[N];
const int INF = 1 << 30;
int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i ++){
		sd(a[i]);
		for(int j = 0; j < N; j++)
			for(int k = 0; k < 2; k++) dp[i][j][k] = dp[i - 1][j][k] = INF;
	}
	
	dp[0][n / 2][0] = dp[0][n / 2][1] = 0;
	for(int i = 0; i < n; i++){
		for(int even = 0; (even <= n / 2) && even <= n - i; even++){
			int j = even;
			int odd = n - i - even;
			for(int now = 0; now < 2; now++){
				for(int val = 0; val < 2; val++){
					if(val == 0 && even == 0) continue;
					if(val == 1 && odd == 0) continue;
					if(a[i + 1] != 0 && val != (a[i + 1] % 2)){
						continue;
					}
					dp[i + 1][j - (val == 0)][val] = min(dp[i + 1][j - (val == 0)][val], dp[i][j][now] + (i != 0) * (val != now));
					// trace(i + 1, j, val);
				}
			}
		}
	}
	printf("%d\n", min(dp[n][0][0], dp[n][0][1]));
}