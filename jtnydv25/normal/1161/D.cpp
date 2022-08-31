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

const int mod = 998244353;
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

const int N = 1005;
int vis[2 * N];
int parity[2 * N];
vector<pii> con[2 * N];
bool error;

void clear(){
	memset(vis, 0, sizeof vis);
	memset(parity, 0, sizeof parity);
	for(int i = 0; i < 2 * N; i++) con[i].clear();
	error = 0;
}
int m;
void dfs(int s){
	vis[s] = 1;
	for(auto it : con[s]){
		int v = it.F;
		if(!vis[v]){
			parity[v] = parity[s] ^ it.S;
			dfs(v);
		} else if(parity[v] != (parity[s] ^ it.S)){
			error = 1;
		}
	}
}
char str[N];
int main(){
	string s;
	scanf("%s", str);
	s = (string)str;
	reverse(s.begin(), s.end());
	int n = s.length();
	int all = 0;
	for(m = 1; m < n; m++){
		clear();
		for(int i = 1; n - i + 1 > i; i++){
			con[i].push_back({n - i + 1, 0});
			con[n - i + 1].push_back({i, 0});
			// con[n + i].push_back({n + n - i, 0});
			// con[n + n - i].push_back({n + i, 0});
		}

		for(int i = 1; m - i + 1 > i; i++){
			con[n + i].push_back({n + m - i + 1, 0});
			con[n + m - i + 1].push_back({n + i, 0});	
		}

		for(int i = 1; i <= n; i++){
			if(s[i - 1] != '?'){
				int p = s[i - 1] - '0';
				con[i].push_back({n + i, p});
				con[n + i].push_back({i, p});
			}
		}

		for(int i = m + 1; i <= n; i++){
			con[0].push_back({n + i, 0});
			con[n + i].push_back({0, 0});
		}

		con[n + m].push_back({0, 1});
		con[0].push_back({n + m, 1});
		int ans = 1;
		for(int i = 0; i <= 2 * n; i++){
			if(!vis[i]){
				dfs(i);
				if(i) ans = mul(ans, 2);
			}
		}
		if(error) ans = 0;
		all = add(all, ans);
	}
	printf("%d\n", all);
}