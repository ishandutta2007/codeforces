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

const int mod =  998244353;

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
const int N = 200005;
int dp[N], dp2[N];
vector<int> con[N];
void dfs(int s = 1, int p = 0){
	dp[s] = 1;
	dp2[s] = 1;
	int P = 1;
	int c = 0;
	int num = 0;
	for(int v : con[s]) if(v != p){
		dfs(v, s);
		dp[s] = mul(dp[s], add(dp[v], dp2[v]));
		if(dp[v] == 0) num++;
		P = mul(P, dp[v]);
		c++;
	}
	if(!c){
		dp[s] = 1;
		dp2[s] = 1;
		return;
	}
	dp2[s] = sub(dp[s], P);
	int sm = 0;
	if(num < 2){
		for(int v : con[s]){
			if(v != p){
				if(dp[v] != 0)
					sm = add(sm, mul(dp2[v], mul(P, inv(dp[v]))));
				else{
					int prod = 1;
					for(int j : con[s]) if(j != v && j != p){
						prod = mul(prod, dp[j]);
					}
					sm = add(sm, mul(prod, dp2[v]));
				}
			}
		}
	}
	dp[s] = sub(dp[s], sm);
}

int main(){
	int n; sd(n);
	for(int i = 1; i < n; i++){
		int p; sd(p);
		con[i + 1].push_back(p);
		con[p].push_back(i + 1);
	}
	dfs();
	
	printf("%d\n", dp[1]);
}