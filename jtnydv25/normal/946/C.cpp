#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

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
int dp[30][100005];
bool ch[30][100005];
const int INF = 1e9;
int minconv(int a, int b){
	if(b >= a) return b - a;
	return INF;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string s;
	cin >> s;
	
	int n = s.length();
	for(int i = 0; i <= n + 1; i++)
		for(int j = 0; j < 30; j++) dp[j][i] = INF;
	dp[26][n] = 0;
	for(int i = n - 1; i >= 0; i--){
		int x = s[i] - 'a';
		dp[26][i] = 0;
		for(int j = 25; j >= 0; j--){
			dp[j][i] = min(dp[j][i + 1], dp[j + 1][i + 1] + minconv(x, j));
			if(dp[j][i + 1] > dp[j + 1][i + 1] + minconv(x, j)) ch[j][i] = 1;
		}
	}
	int ans = dp[0][0];
	if(ans >= INF) ans = -1;
	if(ans == -1){cout << ans; return 0;}
	int curr = 0;
	int pos = 0;
	while(pos < n){
		if(ch[curr][pos]){
			s[pos] = curr + 'a';
			curr ++;
		}
		pos++;
	}
	cout << s;
}