#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second


const int MOD = 998244353 ;
 
inline int sum(int a, int b, int mod = MOD)
{
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

inline int sub(int a, int b, int mod = MOD)
{
	a -= b;
	if (a < 0) a += mod;
	return a;
}

inline int mul(int a, int b, int mod = MOD)
{
	return ((long long)a * b) % mod;
}
 
inline int powmod(int a, int b, int mod = MOD)
{
	int tmp = a;
	int ans = 1;
	while (b)
	{
		if (b & 1) ans = mul(ans, tmp, mod);
		tmp = mul(tmp, tmp, mod);
		b >>= 1;
	}
	return ans;
}
 
inline int inv(int a, int mod = MOD)
{
	return powmod(a, mod - 2, mod);
}

const int maxn = 1000006;

int f[maxn], invf[maxn];
int n;

int cnk(int n, int k)
{
	return mul(f[n], mul(invf[k], invf[n - k]));
}

int main()
{
	f[0] = 1;
	for (int i = 1; i < maxn; i++) f[i] = mul(i, f[i - 1]);
	invf[maxn - 1] = inv(f[maxn - 1]);
	for (int i = maxn - 2; i >= 0; i--) invf[i] = mul(invf[i + 1], i + 1);
	
	scanf("%d", &n);
	int answer = f[n];
	for (int i = 1; i < n; i++)
	{
		answer = sum(answer, mul(mul(f[i], sub(f[n - i], 1)), cnk(n, i)));
	}
	cout << answer << endl;
    return 0;
}