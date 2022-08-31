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


const int N = 5005;
int f[N][N], g[N][N], a[N];
int main(){
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		f[i][i] = a[i];
		g[i][i] = a[i];
		for(int j = i - 1; j >= 1; j--){
			f[j][i] = f[j][i - 1] ^ f[j + 1][i];
			g[j][i] = max(f[j][i], max(g[j + 1][i], g[j][i - 1]));
		}
	}
	int q;
	sd(q);
	while(q--){
		int l, r;
		sd(l); sd(r);
		printf("%d\n", g[l][r]);
	}
}