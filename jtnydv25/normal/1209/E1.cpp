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

template<class T,class U>
ostream& operator<<(ostream& os,const map<T, U> & mp){
	os << "{";
	int i = 0;
	for(auto it : mp){
		if(i) os<<", ";
		os << it;
		i++;
	}
	os << "}";	
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
const int N = 2005;
int a[20][N];
int dp[N][16], dp2[N][16];
// const int INF
int main(){
	int t; sd(t);
	while(t--){
		int n, m;
		sd(n); sd(m);
		for(int i = 0; i < n; i++)
			for(int j = 1; j <= m; j++) sd(a[i][j]);

		for(int i = 0; i <= m; i++)
		for(int j = 0; j < 16; j++) dp[i][j] = -1e9;

		dp[0][0] = 0;
		
		for(int j = 1; j <= m; j++){
			for(int shift = 0; shift < n; shift++){
				vector<int> vec(n);
				for(int k = 0; k < n; k++) vec[k] = a[(k + shift) % n][j];
				for(int oldmask = 0; oldmask < (1<<n); oldmask++)
					for(int now = 0; now < (1<<n); now++) if((now & oldmask) == 0){
						int val = 0;
						for(int k = 0; k < n; k++) if(now >> k & 1) val += vec[k];
						dp[j][now ^ oldmask] = max(dp[j][now ^ oldmask], dp[j - 1][oldmask] + val);
					}
			}
		}
		printf("%d\n", dp[m][(1<<n)-1]);
	}
}