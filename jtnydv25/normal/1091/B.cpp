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

set<ll> st;
const int N = 1005;
int x[N], y[N], a[N], b[N];
const ll X = 1e9;
const ll Y = 1e8;
int main(){
	int n; sd(n);
	for(int i= 1; i <= n; i++) sd(x[i]), sd(y[i]);
	for(int i= 1; i <= n; i++){
		sd(a[i]), sd(b[i]);
		st.insert((a[i] + Y) * X + b[i]);
	}

	for(int i = 1; i <= n; i++){
		int px = x[1] + a[i], py = y[1] + b[i];
		// st.erase((a[i] + Y) * X + b[i]);
		bool ok = 1;
		for(int j = 1; j <= n; j++){
			int _x = px - x[j], _y = py - y[j];
			if(!st.count((_x + Y) * X + _y)){
				ok = 0;
				break;
			}
		}
		if(ok){
			printf("%d %d\n", px, py);
			return 0;
		}
	}
}