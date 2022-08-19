#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 205;
const int mod = 1e9 + 7;

/*
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

int n, c[105], b[105];
int L[105];
mint dp[105][10005];

struct foo{
	int x, i, j;
	bool operator<(const foo &v)const{
		return make_tuple(-x, i, j) < make_tuple(-v.x, v.i, v.j);
	}
};

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> c[i];
	for(int i = 1; i <= n - 1; i++){
		cin >> b[i];
		b[i] += b[i-1];
	}
	for(int i = 1; i <= n - 1; i++) b[i] += b[i-1];
	int sum = 0;
	vector<foo> vect;
	for(int i = 1; i <= n; i++){
		int x = -b[i-1] / i - 10;
		sum += c[i];
		for(int j = 0; j <= sum; j++){
			while((x+1) * i + b[i-1] <= j) x++;
			vect.push_back({x, i, j});
		}
	}
	dp[0][0] = 1;
	sort(all(vect));
	mint ret = 0;
	auto proc = [&](int i, int j){
		dp[i][j] = 0;
		if(i == n){
		}
		for(int k = 0; k <= j && k <= c[i+1]; k++){
			if(i == n) ret -= dp[i][j];
			else dp[i+1][j+k] -= dp[i][j];
		}
	}
	{
		int sum = 0;
		for(int i = 1; i <= n; i++){
			sum += c[i];
			for(int j = L[i]; j <= sum; j++){
				for(int k = 0; k <= j && k <= c[i]; k++){
					dp[i][j] += dp[i-1][j-k];
				}
				if(i == n) ret += dp[i][j];
			}
		}
	}
	for(int i = 0; i < sz(vect); ){
		int e = i;
		while(e < sz(vect) && vect[i].x == vect[e].x) e++;
		for(int j = i; j < e; j++){
			proc(vect[j].i, vect[j].j);
		}
		i = e;
	}
	int q; cin >> q;
	for(int i = 0; i < q; i++){
		int x; cin >> x;
		int cursum = 0;
		for(int j = 1; j <= n; j++){
			L[j] = x * j + cursum;
			L[j] = max(L[j], 0);
			cursum += b[j];
		}
		dp[0][0] = 1;
		int sum = 0;
		mint ret = 0;
		for(int i = 1; i <= n; i++){
			sum += c[i];
			for(int j = L[i]; j <= sum; j++){
			}
		}
		cout << ret << endl;
		for(int j = 0; j < 105; j++){
			for(int k = 0; k < 10005; k++){
				dp[j][k] = 0;
			}
		}
	}
}*/

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")

// Fast IO ********************************************************************************************************
const int __BS = 4096;
static char __bur[__BS + 16], *__er = __bur + __BS, *__ir = __er;
template<class T = int> T _readInt() {
    auto c = [&]() { if (__ir == __er) std::fill(__bur, __bur + __BS, 0), cin.read(__bur, __BS), __ir = __bur; };
    c(); while (*__ir && (*__ir < '0' || *__ir > '9') && *__ir != '-') ++__ir; c();
    bool m = false; if (*__ir == '-') ++__ir, c(), m = true;
    T r = 0; while (*__ir >= '0' && *__ir <= '9') r = r * 10 + *__ir - '0', ++__ir, c();
    ++__ir; return m ? -r : r;
}
static char __buw[__BS + 20], *__iw = __buw, *__ew = __buw + __BS;
template<class T>
void writeInt(T x, char endc = '\n') {
    if (x < 0) *__iw++ = '-', x = -x; if (x == 0) *__iw++ = '0';
    char* s = __iw;
    while (x) { T t = x / 10; char c = x - 10 * t + '0'; *__iw++ = c; x = t; }
    char* f = __iw - 1; while (s < f) swap(*s, *f), ++s, --f;
    if (__iw > __ew) cout.write(__buw, __iw - __buw), __iw = __buw;
    *__iw++ = endc;
}
template<class T>
void writeStr(const T& str) {
    int i = 0; while (str[i]) { *__iw++ = str[i++]; if (__iw > __ew) cout.write(__buw, __iw - __buw), __iw = __buw; }
}
struct __FL__ { ~__FL__() { if (__iw != __buw) cout.write(__buw, __iw - __buw); } };
static __FL__ __flushVar__;

int n, q;
int a[101000];
int ts[101005], cache[101005], foo;

int main(){
	n = _readInt();
	for(int i = 1; i <= n; i++) a[i] = i - _readInt();
	q = _readInt();
	foo = 1;
	while(q--){
		int t = _readInt();
		int i = _readInt();
		if(t == 1){
			foo++;
			a[i] = i - _readInt();
		}
		else{
			if(ts[i] == foo){
				writeInt(cache[i]);
				continue;
			}
			int x = a[i];
			for(int j = i + 1; j <= n; j++){
			    x += (a[j] > x ? 0 : 1);
			}
			ts[i] = foo;
			cache[i] = x;
			writeInt(x);
		}
	}
}