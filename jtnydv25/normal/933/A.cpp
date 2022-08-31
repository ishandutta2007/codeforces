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

const int N = 2005;
int dp[3], p[N], p2[N], a[N];
int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		p[i] = p[i - 1];
		p2[i] = p2[i - 1];
		if(a[i] == 1) p[i]++;
		else p2[i]++;
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		ans = max(ans, p[i] + p2[n] - p2[i]);
	}

	for(int l = 1; l <= n; l++){
		memset(dp, 0, sizeof dp);
		dp[a[l]] = 1;
		for(int r = l + 1; r <= n; r++){
			if(a[r] == 1) dp[1] = max(dp[1], dp[2]) + 1;
			else dp[2]++;
			ans = max(ans, max(dp[1], dp[2]) + p[l - 1] + p2[n] - p2[r]);
		}
	}
	printf("%d\n", ans);
}