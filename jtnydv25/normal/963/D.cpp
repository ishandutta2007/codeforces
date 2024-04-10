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

const int mod = 1e9 + 7;
const int base = 97;
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

const int N = 100005;
vector<pair<int, int> > queries[N];
int H[N], pw[N];
int getHash(int i, int j){
	return sub(H[j], mul(pw[j - i + 1], H[i - 1]));
}
char s[N];
char m[N];
int ans[N];
vector<int> vec[N];
map<int, int> mp;
bool got[N];
int lengths[N];
int K[N];
int main(){
	memset(ans, -1, sizeof ans);
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	pw[0] = 1;
	for(int i = 1; i < N; i++) pw[i] = mul(base, pw[i - 1]);
	for(int i = 1; i <= len; i++) H[i] = (H[i - 1] * 1ll * base + s[i] - 'a' + 1) % mod;
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(K[i]);
		scanf("%s", m);
		int hsh = 0, L = strlen(m);
		for(int i = 0; i < L; i++) hsh = (hsh * 1ll * base + m[i] - 'a' + 1) % mod;
		queries[L].push_back({hsh, i});
		got[L] = 1;
		lengths[i] = L;
	}

	for(int i = 1; i <= len; i++){
		if(!got[i]) continue;
		mp.clear();
		for(auto it : queries[i]){
			mp[it.F] = it.S;
		}

		for(int j = 1; j + i - 1 <= len; j++){
			int hsh = getHash(j, j + i - 1);
			if(mp.find(hsh) != mp.end()){
				vec[mp[hsh]].push_back(j);
			}
		}

		for(auto it : queries[i]){
			int ind = it.S;
			if((int)vec[ind].size() < K[ind]){
				vec[ind].clear();
				continue;
			} else{
				int k = K[ind];
				int answ = 1e9;
				for(int j = 0; j + k - 1 < (int) vec[ind].size(); j++)
					answ = min(answ, vec[ind][j + k - 1] - vec[ind][j] + i);
				ans[ind] = answ;
				vec[ind].clear();
			}
		}
	}
	for(int i = 1; i <= n; i++) printf("%d\n", ans[i]);
}