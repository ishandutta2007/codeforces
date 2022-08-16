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

int dp[200005];
int main(){
	cin.tie(0);
	string s; cin >> s;
	int n = s.length();
	s += s;
	dp[2 * n - 1] = 1;
	int ans = 1;
	for(int i = 2 * n - 2; i >= 0; i--){
		dp[i] = (s[i] == s[i + 1]) ? 1 : dp[i + 1] + 1;
		ans = max(ans, dp[i]);
	}
	cout << min(ans, n)<<endl;
}