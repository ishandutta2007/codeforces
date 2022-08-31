#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#ifdef LOCAL
#define cerr cout
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
const int N = 100005;
int a[N];
void solve(){
	int n;
	sd(n);
	int num0 = 0;
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		num0 += a[i] == 0;
	}
	sort(a + 1, a + n + 1);
	int c = 0;
	for(int i = n; i >= 1; i--){
		a[i] = a[i] - a[i - 1];
		if(i > 1 && a[i] == 0) c++;
	}
	if(c >= 2 || num0 >= 2){
		printf("cslnb\n");
		return;
	}
	int x = 0;
	if(c == 1){
		for(int j = 2; j <= n; j++) if(a[j] == 0){
			if(j - 1 > 1 && a[j - 1] == 1){
				printf("cslnb\n");
				return;
			}
			a[j - 1] --;
			a[j]++;
			x ^= 1;
		}
	}
	// cerr << x << " "  << a[1] << " " << a[2] << endl;
	x ^= (a[1] & n & 1);

	for(int i = 2; i <= n; i++){
		x ^= (a[i] - 1) & (n - i + 1) & 1;
	}

	printf(x == 0 ? "cslnb\n" : "sjfnb\n");
}

int main(){
	int t = 1;
	// sd(t);
	for(int tt = 1; tt <= t; tt++){
		// printf("Case #%d: ", tt);
		solve();
	}
}