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

const int N = 200005;
int nxt[N], a[N];


#define ull unsigned ll
ull MAX = 3e18;


bool ok(ull curr, int val){
	return curr <= MAX / val;
}
ull p[N];

int main(){
	int n, k;
	sd(n); sd(k);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		p[i] = p[i - 1] + a[i];
	}
	nxt[n + 1] = n + 1;
	int ans = 0;
	for(int i = n; i >= 1; i--){

		unsigned long long prod = a[i];
		nxt[i] = (a[i + 1] == 1) ? nxt[i + 1] : i + 1;

		int l = i;

		while(l <= n){
			int nxt_l = nxt[l];
			if(prod % k == 0){
				ull to_find = prod / k;
				int ind = upper_bound(p + 1, p + n + 1, p[i - 1] + to_find - 1) - p;
				if(ind >= l && ind < nxt_l && p[ind] == p[i - 1] + to_find){
					// trace(i, ind);
					ans++;
				}
			}
			l = nxt_l;
			if(l <= n && !ok(prod, a[l])) break;
			prod *= a[l];
		}
	}
	printf("%d\n", ans);
}