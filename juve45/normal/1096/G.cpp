#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

// const long long N = ;
long long n;


const long long MOD = (119 << 23) + 1, gen = 62;
 
long long mpow(long long b, long long e) {
    long long res = 1;
    for(long long k = 1; k <= e; k <<= 1) {
        if(k & e) res = (res * b)%MOD;
        b = (b * b)%MOD;
    }
    return res;
}
 
void ntt(vector <long long> &f, vector <long long> &root, vector<long long> &rev) {
    long long n = f.size();
    for(long long i = 0; i < n; i++)
        if(i < rev[i]) swap(f[i], f[rev[i]]);
    for(long long k = 1; k < n; k *= 2) {
        for(long long i = 0; i < n; i += 2*k) {
            for(long long j = 0; j < k; j++) {
                long long z = (root[j + k] * f[i + j + k]) % MOD;
                f[i + j + k] = (f[i + j] < z ? f[i + j] - z + MOD : f[i + j] - z);
                f[i + j] = (f[i + j] + z >= MOD ? f[i + j] + z - MOD : f[i + j] + z);
            }
        }
    }
}
 
vector <long long> conv(vector <long long> A, vector <long long> B) {
    long long sz = A.size() + B.size() - 1, L = 32 - __builtin_clz(sz), n = 1 << L;
    vector <long long> f(A), g(B), res(n), root(n, 1);
    f.resize(n), g.resize(n);
    long long pr = mpow(gen, (MOD - 1)/n), inv = mpow(n, MOD - 2);
    for(long long i = n/2 + 1; i < n; i++)
        root[i] = (pr * root[i - 1])%MOD;
    for(long long i = n/2 - 1; i >= 0; i--)
        root[i] = root[2*i];
    vector<long long> rev(n);
    for(long long i = 1; i < n; i++)
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (L - 1));
    ntt(f, root, rev), ntt(g, root, rev);
    for(long long i = 0; i < n; i++)
        res[i] = (f[i] * g[i])%MOD;
    reverse(res.begin() + 1, res.end());
    ntt(res, root, rev);
    for(long long i = 0; i < sz; i++)
        res[i] = (res[i] * inv) % MOD;
    return {res.begin(), res.begin() + sz};
}
 

vector <long long> power(vector <long long> v, long long exp) {
	// dbg(exp	);
	if(exp == 1) return v;
	auto w = power(v, exp / 2);
	w = conv(w, w);
	if(exp % 2) w = conv(w, v);
	return w;
}

long long k, a[234], ans;

int main() {
	ios_base::sync_with_stdio(false);

	vector<long long> v = vector <long long> (10, 0);

	cin >> n >> k;
	for(long long i = 1; i <= k; i++) cin >> a[i], v[a[i]] = 1;

	v = power(v, n / 2);
	
	for(auto i : v)
		ans += (i * i) % MOD, ans %= MOD;
	cout << ans << '\n';
}