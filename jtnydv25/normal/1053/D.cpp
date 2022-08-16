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

const int N = 2000006;
int freq[N];
int g[N];
map<int, int> ms[N];
int mx[N];
int factor[N];
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
vector<pii> changes;
int ans = 1;
int getChange(int x){
	int ret = 1;
	changes.clear();
	while(x != 1){
		int p = factor[x];
		int k = 0;
		while(x % p == 0){
			x /= p;
			k++;
		}
		if(mx[p] < k){
			changes.push_back({p, mx[p]});
			ret = mul(ret, powr(p, k - mx[p]));
			mx[p] = k;
		}
	}

	reverse(changes.begin(), changes.end());
	for(auto it : changes) mx[it.F] = it.S;
	return ret;
}

void add(int x){
	// trace(x);
	while(x != 1){
		int p = factor[x];
		int k = 0;
		while(x % p == 0){
			x /= p;
			k++;
		}
		if(mx[p] < k){
			ans = mul(ans, powr(p, k - mx[p]));
			// trace(p, k - mx[p], ans);
			mx[p] = k;
		}
		ms[p][k]++;
	}
}

bool canRemove(int x){
	while(x != 1){
		int p = factor[x];
		int k = 0;
		while(x % p == 0){
			x /= p;
			k++;
		}
		if(mx[p] == k){
			if(ms[p][k] == 1) return 0;
		}
	}
	return 1;
}

bool P[N], Q[N];
bool R[N];

int main(){
	int n; sd(n);
	for(int i = 2; i < N; i++){
		if(!factor[i])
			for(int j = i; j < N; j += i) factor[j] = i;
	}

	for(int i = 1; i <= n; i++){
		int x;
		sd(x);
		freq[x]++;
	}

	for(int i = N - 1; i >= 2; i--){
		if(freq[i] >= 2){
			add(i);
			add(i - 1);
			P[i] =Q[i] = 1;
		} else if(freq[i] == 1){
			int x1 = getChange(i), x2 = getChange(i - 1);
			if(x1 > x2){
				add(i);
				P[i] = 1;
			}
			else{
				add(i - 1);
				Q[i] = 1;
			}
		}
		if(freq[i] > 2) R[i] = 1;
	}

	for(int i = 2; i < N; i++){
		if(R[i]){
			ans = add(ans, 1);
			printf("%d\n", ans);
			return 0;
		}
		if(P[i]){
			if(canRemove(i)){
				ans = add(ans, 1);
				printf("%d\n", ans);
				return 0;
			}
		}
		if(Q[i]){
			if(canRemove(i - 1)){
				ans = add(ans, 1);
				printf("%d\n", ans);
				return 0;
			}
		}
	}
	printf("%d\n", ans);
}