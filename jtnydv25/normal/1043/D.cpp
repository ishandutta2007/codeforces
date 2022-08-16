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

const int N = 1100006;
int where[11][N / 5];
int a[11][N / 5];
int lcp[11][N / 5];
int main()
{
  int n = 100000, m=10;
  sd(n); sd(m);
  for(int i = 1; i <= m; i++){
  	for(int j = 1;j <= n; j++){
  		sd(a[i][j]);
  		where[i][a[i][j]] = j;
  	}
  }
  long long ans = 0;
  for(int i = n; i >= 1; i--){
  	int val = a[1][i];
  	int mn = n - i + 1;
  	for(int j = 2; j <= m; j++){
		int pos1 = where[j][val];
		if(i == n || pos1 == n){
			lcp[j][i] = 1;
			mn = 1;
		} else{
			lcp[j][i] = (a[j][pos1 + 1] == a[1][i + 1]) ? lcp[j][i + 1] + 1 : 1;
			mn = min(mn, lcp[j][i]);
		}
  	}
  	ans += mn;
  }
  printf("%lld\n", ans);
}