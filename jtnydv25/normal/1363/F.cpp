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

const int N = 2005;
const int SIGMA = 26;
int freqs[N][SIGMA], freqt[N][SIGMA];
int dp[N][N];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int T; cin >> T;
	while(T--){
		string s, t;
		int n; cin >> n; cin >> s >> t;
		for(int i = 1; i <= n; i++){
			memcpy(freqs[i], freqs[i - 1], sizeof freqs[i]);
			freqs[i][s[i - 1] - 'a']++;
		}

		for(int i = 1; i <= n; i++){
			memcpy(freqt[i], freqt[i - 1], sizeof freqt[i]);
			freqt[i][t[i - 1] - 'a']++;
		}
		bool possible = true;

		for(int c = 0; c < SIGMA; c++) if(freqs[n][c] != freqt[n][c]){
			possible = false;
		}

		if(!possible){
			cout << -1 << endl;
			continue;
		}

		for(int i = 0; i <= n; i++) memset(dp[i], 0, sizeof dp[i]);
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
				possible = s[i - 1] == t[j - 1];
				for(int c = 0; c < SIGMA; c++) if(freqs[i][c] > freqt[j][c]) possible = false;
				if(possible) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}

		cout << n - dp[n][n] << endl;
	}
}