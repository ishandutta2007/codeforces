#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#include<x86intrin.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<18, mod = 1e9 + 7 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using reg = __m256i;
struct mat {
	reg a[303];
};
int n, m;
alignas(int) int buff[305*8];
alignas(int) int b2[305*8];
void load(mat &c, int inmul = 0) {
    if(inmul)
	for(int i = 0; i < 16*n; i+=8) c.a[i>>3] = _mm256_loadu_si256((reg*) &buff[i]);
	else
	for(int i = 0; i < 16*n; i+=8) c.a[i>>3] = _mm256_loadu_si256((reg*) &b2[i]);
}
mat mul(const mat &a, const mat &b) {
    memset(buff, 0, sizeof buff);
	mat c;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
            buff[(i<<3)|(j>>5)] |= (!_mm256_testz_si256(a.a[i], b.a[n+j]))<<(j&31);
            buff[((n + j)<<3)|(i>>5)] |= (!_mm256_testz_si256(a.a[i], b.a[n+j]))<<(i&31);
		}
	}
	load(c, 1);
	return c;
}
void add(int t, int f) {
    b2[(t<<3)|(f>>5)] |= 1<<(f&31);
    b2[((n + f)<<3)|(t>>5)] |= 1<<(t&31);
}
void print(const mat& a) {
    int t[16];
    cout << "===\n";
    for(int i = 0; i < 2*n; i++) {
        _mm256_storeu_si256((reg*)&t[0],a.a[i]);
        for(int j = 0; j < n; j++) {
            cout << (1&(t[j>>5]>>(j&31)));
        }
        cout << '\n';
    }
    cout << "===\n";
}
map<int, vpi> a;
mat s, cr;
mat pws[31];
ll x = 0;
int kir[16];
void calc(ll r) {
    pws[0] = cr;
    for(int i = 1; i < 31; i++) pws[i] = mul(pws[i-1], pws[i-1]);
    for(int i = 31; i--;) {
        if(x+(1<<i) > r) continue;
        mat t = mul(s, pws[i]);
        _mm256_storeu_si256((reg*)&kir[0],t.a[0]);
        if(!(1&(kir[(n-1)>>5]>>((n-1)&31)))) {
            s = t;
            x += 1<<i;
        }
    }
   if(x!=r) cout << x+1, exit(0);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int f, t, d, i = 0; i < m; i++) {
	    cin >> f >> t >> d, f--, t--;
	    a[d].pb({f, t});
	}
	a[0].pb({n-1, n-1});
	for(int i = 0; i < n; i++) add(i, i);
	load(s);
	memset(b2, 0, sizeof b2);
	ll l = 0;
	for(auto cur = a.begin(); cur != a.end(); cur++) {
	    auto nxt = cur;
	    ll r;
	    if(++nxt == a.end()) r = INT_MAX;
	    else r = nxt->first;
	    for(auto i : cur->second) add(i.first, i.second);
	    load(cr);
	    calc(r);
	}
	cout << "Impossible";
}