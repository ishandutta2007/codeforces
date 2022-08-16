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

multiset<int> xl, xr, yl, yr;
const int N = 200005;
int a[N], b[N], c[N], d[N];
int main(){
	int n; sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]); sd(b[i]); sd(c[i]); sd(d[i]);
		xr.insert(c[i]); xl.insert(a[i]);
		yr.insert(d[i]); yl.insert(b[i]);
	}

	for(int i = 1; i <= n; i++){
		xl.erase(xl.find(a[i]));
		yl.erase(yl.find(b[i]));
		xr.erase(xr.find(c[i]));
		yr.erase(yr.find(d[i]));

		if(*xr.begin() >= *xl.rbegin() && *yr.begin() >= *yl.rbegin()){
			printf("%d %d\n", *xr.begin(), *yr.begin());
			return 0;
		}

		xr.insert(c[i]); xl.insert(a[i]);
		yr.insert(d[i]); yl.insert(b[i]);
	}
}