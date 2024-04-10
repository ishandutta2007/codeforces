//#pragma GCC optimize("O3") 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx") 

#include <unordered_map>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>
 
#pragma comment(linker, "/STACK:64000000")
typedef long long ll;
 
using namespace std;
 
const int MAXK = -1;
const int MAXN = -1;
const int MOD = 998244353;
 
namespace FFT
{
	typedef double dbl;
#define forn(i, n) for (int i = 0; i < (n); i++) 
#define pw(n) (1LL << (n))
 
	const int maxBase = 17;
	const int maxN = 1 << maxBase;
 
	struct num
	{
		dbl x, y;
		num() {}
		num(dbl xx, dbl yy) : x(xx), y(yy) {}
		num(dbl alp) : x(cos(alp)), y(sin(alp)) {}
	};
 
	inline num operator + (num a, num b) { return num(a.x + b.x, a.y + b.y); }
	inline num operator - (num a, num b) { return num(a.x - b.x, a.y - b.y); }
	inline num operator * (num a, num b) { return num(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
	inline num conj(num a) { return num(a.x, -a.y); }
 
	const dbl PI = acos(-1);
 
	num root[maxN];
	int rev[maxN];
	bool rootsPrepared = false;
 
	void prepRoots()
	{
		if (rootsPrepared) return;
		rootsPrepared = true;
		root[1] = num(1, 0);
		for (int k = 1; k < maxBase; ++k)
		{
			num x(2 * PI / pw(k + 1));
			for (int i = pw(k - 1); i < pw(k); ++i)
			{
				root[2 * i] = root[i];
				root[2 * i + 1] = root[i] * x;
			}
		}
	}
 
	int base, N;
 
	int lastRevN = -1;
	void prepRev()
	{
		if (lastRevN == N) return;
		lastRevN = N;
		forn(i, N) rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (base - 1));
	}
 
	void fft(num *a, num *f)
	{
		forn(i, N) f[i] = a[rev[i]];
		for (int k = 1; k < N; k <<= 1) for (int i = 0; i < N; i += 2 * k) forn(j, k)
		{
			num z = f[i + j + k] * root[j + k];
			f[i + j + k] = f[i + j] - z;
			f[i + j] = f[i + j] + z;
		}
	}
 
	num a[maxN], b[maxN], f[maxN], g[maxN];
	ll A[maxN], B[maxN], C[maxN];
 
	void _multMod(int mod)
	{
		forn(i, N)
		{
			int x = A[i] % mod;
			a[i] = num(x & (pw(15) - 1), x >> 15);
		}
        bool eq = 1;
		forn(i, N)
		{
			int x = B[i] % mod;
			b[i] = num(x & (pw(15) - 1), x >> 15);
            eq &= B[i] == A[i];
		}
		fft(a, f);
		if (!eq) fft(b, g);
        else forn(i, N) g[i] = f[i];
 
		forn(i, N)
		{
			int j = (N - i) & (N - 1);
			num a1 = (f[i] + conj(f[j])) * num(0.5, 0);
			num a2 = (f[i] - conj(f[j])) * num(0, -0.5);
			num b1 = (g[i] + conj(g[j])) * num(0.5 / N, 0);
			num b2 = (g[i] - conj(g[j])) * num(0, -0.5 / N);
			a[j] = a1 * b1 + a2 * b2 * num(0, 1);
			b[j] = a1 * b2 + a2 * b1;
		}
 
		fft(a, f);
		fft(b, g);
 
		forn(i, N)
		{
			ll aa = f[i].x + 0.5;
			ll bb = g[i].x + 0.5;
			ll cc = f[i].y + 0.5;
			C[i] = (aa + bb % mod * pw(15) + cc % mod * pw(30)) % mod;
		}
	}
 
	void prepAB(int n1, int n2)
	{
		base = 1;
		N = 2;
		while (N < n1 + n2) base++, N <<= 1;
 
		for (int i = n1; i < N; ++i) A[i] = 0;
		for (int i = n2; i < N; ++i) B[i] = 0;
 
		prepRoots();
		prepRev();
	}
 
	void mult(int n1, int n2)
	{
		prepAB(n1, n2);
		forn(i, N) a[i] = num(A[i], B[i]);
		fft(a, f);
		forn(i, N)
		{
			int j = (N - i)  & (N - 1);
			a[i] = (f[j] * f[j] - conj(f[i] * f[i])) * num(0, -0.25 / N);
		}
		fft(a, f);
		forn(i, N) C[i] = (ll)round(f[i].x);
	}
 
    ll oldA[maxN], oldB[maxN];
 
	void multMod(int n1, int n2, int mod)
	{
        assert(A[0] == 1);
        assert(B[0] == 1);
        assert(n1 == n2);
        assert(n1 > 1 && n2 > 1);
        for (int i = 0; i <= n1; i++) oldA[i] = A[i];
        for (int i = 0; i <= n2; i++) oldB[i] = B[i];
        for (int i = 0; i < n1; i++) A[i] = A[i + 1];
        for (int i = 0; i < n2; i++) B[i] = B[i + 1];
 
        n1--; n2--;
		prepAB(n1, n2);
		_multMod(mod);
        n1++; n2++;
        for (int i = n1 - 1; i >= 2; i--) C[i] = C[i - 2];
        C[0] = C[1] = 0;
        
        for (int i = 1; i < n1; i++) {
            C[i] = (C[i] + 0LL + oldA[i] + oldB[i]) % mod;
        }
        C[0] = 1;
	}
 
	int D[maxN];
 
	void multLL(int n1, int n2)
	{
		prepAB(n1, n2);
 
		int mod1 = 1.5e9;
		int mod2 = mod1 + 1;
 
		_multMod(mod1);
 
		forn(i, N) D[i] = C[i];
 
		_multMod(mod2);
 
		forn(i, N)
		{
			C[i] = D[i] + (C[i] - D[i] + (ll)mod2) * (ll)mod1 % mod2 * mod1;
		}
	}
}
 
unordered_map<ll, vector<int> > mp;
unordered_map<ll, vector<int> > sq;
 
vector<int> solve(ll n, int k) {
	if (mp.count(n)) return mp[n];
    int oldK = k;
    k = min((ll)k, max(2 * n, 2LL));
 
    vector<int> res(k + 1, 0);
    auto fff = [&] {
        for (int i = 0; i <= k; i++) {
            FFT::B[i] = FFT::A[i] = res[i];
        }
        FFT::multMod(k + 1, k + 1, MOD);
        //vector<int> ss(k + 1);
        vector<int> ss(oldK + 1, 0);
        for (int i = 0; i <= min(oldK, FFT::N - 1); i++) ss[i] = FFT::C[i];
        while (res.size() <= oldK) res.push_back(0);
        sq[n] = ss;
    };

	if (n == 0) {
		res[0] = 1;
        fff();
		return mp[n] = res;
	}
	if (n == 1) {
		res[0] = 1;
		res[1] = 1;
        fff();
		return mp[n] = res;
	}
	vector<int> o1 = solve(n / 2, oldK);
	vector<int> res1(k + 1);
    res1 = sq[n / 2];
 
	vector<int> res2(k + 1);
    if (n % 2 == 1) {
        for (int i = 1; i <= k; i++) res2[i] = res1[i - 1]; 
    } else {
        solve(n / 2 - (n % 2 == 0), oldK);
        res2 = sq[n / 2 - (n % 2 == 0)];
        for (int i = k - 1; i >= 0; i--) res2[i + 1] = res2[i];
        res2[0] = 0;
    }
 
	for (int i = 0; i <= k; i++) res[i] = (res1[i] + res2[i]) % MOD;
 
	if (n % 2 == 1) {
		vector<int> o1 = solve(n / 2, oldK);
		vector<int> o2 = solve(n / 2 - 1, oldK);
		for (int i = 0; i < k; i++) {
			FFT::A[i] = o1[i];
			FFT::B[i] = o2[i];
		}
		FFT::multMod(k + 1, k + 1, MOD);
		vector<int> res3(k + 1);
		for (int i = 1; i <= k; i++) res3[i] = FFT::C[i - 1];
		for (int i = 0; i <= k; i++) res[i] = (res[i] + 2LL * res3[i]) % MOD;
	}
 
    fff();
	return mp[n] = res;
}
 
int main() {
#ifdef HOME
	freopen("in", "r", stdin);
#endif
 
    ll n;
    int k;
	if (cin >> n >> k) {
    //n = 1LL << 33;
    //k = 1 << 15; {
		mp.clear();
		vector<int> ans = solve(n, max(k, 2));
		for (int i = 1; i <= k; i++) printf("%d%c", ans[i], " \n"[i == k]);
	}
    //cerr << clock() / (double)CLOCKS_PER_SEC << endl;
 
	return 0;
}