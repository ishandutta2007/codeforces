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

const int N = 20005;
int a[N], b[N], f[N];
int arr[N], sz;
int n, m; 
inline int nxt(int i){
	i++;
	if(i >= n) i = 0;
	return i;
}

inline int prv(int i){
	i--;
	if(i < 0) i = n - 1;
	return i;
}

inline int sub(int a, int b){
	a -= b;
	if( a < 0) a += n;
	return a;
}

inline int add(int a, int b){
	a += b;
	if( a >= n) a -= n;
	return a;
}


inline int dist(int x, int y, int d){
	// assert(x <= y);
	if(d < x) return d + sub(0, y);
	if(d <= y) return 0;
	return d - y;
}

inline int get2(int a, int b){
	return a < b ? 0 : b;
}
int now[N], ans[N];
vector<int> all[N];
int main(){
	sd(n); sd(m);
	int mx = 0;
	for(int i = 0; i < m; i++){
		sd(a[i]); sd(b[i]); 
		a[i]--;
		b[i]--;
		f[a[i]]++;
		mx = max(mx, f[a[i]]);
		all[a[i]].push_back(b[i]);
	}

	for(int i = 0; i < n; i++){
		now[i] = i;
	}

	int fix = (mx - 1) * n;
	
	for(int i = 0; i < n; i++){
		int y = prv(i);
		for(; y != i; y = prv(y)) if(f[y] == mx){
			break;
		}
		int go = 0;
		int go2 = 0;
		for(int j = 0; j < n; j++){
			if(f[j] == mx){
				int here = 1e9;
				for(int v : all[j]){
					here = min(here, dist(now[j], now[y], now[v])); 
				}
				go = max(go, here);
			}
			if(f[j] == mx - 1 && f[j]!=0){
				int here2 = 1e9;
				for(int v : all[j]) here2 = min(here2, get2(now[j], now[v]));
				go2 = max(go2, here2);
			}
		}
		printf("%d ", max(fix + now[y] + go, go2 + fix));
		for(int j = 0; j < n; j++) now[j] = prv(now[j]);
	}
}