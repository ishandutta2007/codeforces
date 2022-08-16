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

const int N = 705;
bool dp[N][N];
int a[N];
bool f[N][N];

bool done[N][N];

bool get(int i, int j){
	if(done[i][j]) return dp[i][j];
	if(i == j){
		done[i][j] = 1;
		return dp[i][j] = 1;
	}

	if(i < j){
		for(int k = i + 1; k <= j; k++) if(f[i][k] && get(k, i + 1) && get(k, j)){
			done[i][j] = 1;
			return dp[i][j] = 1;
		}
		done[i][j] = 1;
		return dp[i][j] = 0;
	} else{
		for(int k = i - 1; k >= j; k--) if(f[i][k] && get(k, i - 1) && get(k, j)){
			done[i][j] = 1;
			return dp[i][j] = 1;
		}
		done[i][j] = 1;
		return dp[i][j] = 0;
	}
}

int main(){
	int n = 700;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) f[i][j] = __gcd(a[i], a[j]) > 1;
	bool ok = 1;
	for(int i = 1; i <= n; i++) if(get(i, 1) && get(i, n)){
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
}