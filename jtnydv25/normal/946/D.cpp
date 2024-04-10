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
const int N = 505;
vector<int> beg[N], en[N];
char s[N][N];
int mn[N][N], dp[N][N];
const int INF = 1e9;
int main(){
	int n, m, k;
	sd(n); sd(m); sd(k);
	for(int i = 1; i <= n; i++){
		scanf("%s", s[i] + 1);
		s[i][0] = s[i][m + 1] = '0';
		mn[i][0] = INF;
		for(int j = 1; j <= m; j++){
			mn[i][j] = INF;
			if(s[i][j] == '1') beg[i].push_back(j);
			if(s[i][j] == '1') en[i].push_back(j);
		}
		int sz = beg[i].size();
		mn[i][sz] = 0;
		for(int _i = 0; _i < sz; _i++){
			for(int j = _i; j < sz; j++){
				int missed = _i + sz - 1 - j;
				assert(en[i][j] >= beg[i][_i]);
				mn[i][missed] = min(mn[i][missed], en[i][j] - beg[i][_i] + 1);
			}
		}
	}

	for(int i = n; i >= 1; i--){
		for(int j = 0; j <= k; j++){
			dp[i][j] = INF;
			for(int missed = 0; missed <= j; missed ++){
				dp[i][j] = min(dp[i][j], dp[i + 1][j - missed] + mn[i][missed]);
			}
		}
	}
	printf("%d\n", dp[1][k]);
}