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
const int N = 1e6 + 10;
int l, r, A[N], perm[N];
set<int> added;
int gc(int n, int m){return max(0, (n - 1) /m + 1);}
const int mod = 1e9 + 7;

inline int add(int x, int y){ x += y; if(x >= mod) x -= mod; return x;}
inline int sub(int x, int y){ x -= y; if(x < 0) x += mod; return x;}
inline int mul(int x, int y){ return (x * 1ll * y) % mod;}
inline int powr(int a, ll b){
	int x = 1 % mod;
	while(b){
		if(b & 1) x = mul(x, a);
		a = mul(a, a);
		b >>= 1;
	}
	return x;
}
inline int inv(int a){ return powr(a, mod - 2);}

int main(){
	int n, k; sd(n); sd(k);
	for(int i = 1; i <= n; i++) sd(A[i]), perm[i] = i;
	sort(perm + 1, perm + n + 1, [](int i, int j){return A[i] > A[j];});
	added = {0, n + 1};
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int ind = perm[i];
		auto it = added.upper_bound(ind);
		auto it2 = it;
		it--;
		l = (*it) + 1;
		r = (*it2) - 1;
		added.insert(ind);
		long long cnt = 0;
		if(ind - l < r - ind){
			for(int j = l; j <= ind; j++){
				int mx = (r - j) / (k - 1);
				int mn = max(1, gc(ind - j, k - 1));
				cnt = add(cnt, max(0, mx - mn + 1));
			}
		} else{
			for(int j = ind; j <= r; j++){
				int mx = (j - l) / (k - 1);
				int mn = max(1, gc(j - ind, k - 1));
				cnt = add(cnt, max(0, mx - mn + 1));
			}
		}
		ans = add(ans, mul(cnt, A[ind]));
	}
	printf("%d\n", ans);
}