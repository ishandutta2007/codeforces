#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 100005;

const int mod = 998244353; //1e9 + 7;//998244353;

template<typename T>
T gcd(const T &a, const T &b) {
    return b == T(0) ? a : gcd(b, a % b);
}

struct mint {
    int val;
    mint() { val = 0; }
    mint(const lint& v) {
        val = (-mod <= v && v < mod) ? v : v % mod;
        if (val < 0) val += mod;
    }

    friend ostream& operator<<(ostream& os, const mint& a) { return os << a.val; }
    friend bool operator==(const mint& a, const mint& b) { return a.val == b.val; }
    friend bool operator!=(const mint& a, const mint& b) { return !(a == b); }
    friend bool operator<(const mint& a, const mint& b) { return a.val < b.val; }

    mint operator-() const { return mint(-val); }
    mint& operator+=(const mint& m) { if ((val += m.val) >= mod) val -= mod; return *this; }
    mint& operator-=(const mint& m) { if ((val -= m.val) < 0) val += mod; return *this; }
    mint& operator*=(const mint& m) { val = (lint)val*m.val%mod; return *this; }
    friend mint ipow(mint a, lint p) {
        mint ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans;
    }
    friend mint inv(const mint& a) { assert(a.val); return ipow(a, mod - 2); }
    mint& operator/=(const mint& m) { return (*this) *= inv(m); }

    friend mint operator+(mint a, const mint& b) { return a += b; }
    friend mint operator-(mint a, const mint& b) { return a -= b; }
    friend mint operator*(mint a, const mint& b) { return a *= b; }
    friend mint operator/(mint a, const mint& b) { return a /= b; }
    operator int64_t() const {return val; }
};

vector<int> gph[MAXN];
int mex[MAXN], vis[MAXN];

void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	set<int> s;
	for(auto &i : gph[x]){
		dfs(i);
		s.insert(mex[i]);
	}
	while(s.find(mex[x]) != s.end()) mex[x]++;
}

int n, m;
int cnt[512];
mint adj[512][512];


vector<mint> basis[512];
mint sol[512];
void solve(){
	for(int i=n-1; i>=0; i--){
		if(basis[i].empty()) continue;
		for(int j=i+1; j<n; j++){
			sol[i] -= sol[j] * basis[i][j];
		}
		sol[i] /= basis[i][i];
	}
	cout << mint(1) - sol[0] << endl;
}

void insert(vector<mint> v, mint x){
	bool ok = 0;
	for(int i=0; i<n; i++){
		if(v[i]){
			if(basis[i].empty()){
				basis[i] = v;
				sol[i] = x;
				ok = 1;
				break;
			}
			else{
				mint w = v[i] / basis[i][i];
				for(int j=0; j<n; j++){
					v[j] -= w * basis[i][j];
				}
				x -= w * sol[i];
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		int s, e; scanf("%d %d",&s,&e);
		gph[s].push_back(e);
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			dfs(i);
		}
		assert(mex[i] < 512);
		cnt[mex[i]]++;
	}
	mint inv = mint(1) / mint(n + 1);
	n = 512;
	for(int i=0; i<512; i++){
		for(int j=0; j<512; j++){
			adj[i][j] = mint(-cnt[i^j]) * inv;
		}
		adj[i][i] += mint(1);
		vector<mint> foo(adj[i], adj[i] + 512);
		insert(foo, i == 0 ? inv : mint(0));
	}
	solve();
}