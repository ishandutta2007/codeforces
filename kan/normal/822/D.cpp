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

const int MOD = 1000000007;
 
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

const int maxn = 5000006;

int sm[maxn];
int ans[maxn];
int t, l, r;


int main()
{
	scanf("%d%d%d", &t, &l, &r);
	for (int i = 1; i < maxn; i++) sm[i] = -1;
	for (int i = 2; i < maxn; i++)
	{
		for (int j = i; j < maxn; j += i) if (sm[j] == -1)
		{
			sm[j] = i;
		}
	}
	ans[1] = 0;
	for (int i = 2; i < maxn; i++)
	{
		int d = sm[i];
		int g = i / d;
		ans[i] = sum(ans[i / d], mul(g, ((ll)d * (d - 1) / 2) % MOD));
	}
	int ml = 1;
	int answer = 0;
	for (int i = l; i <= r; i++)
	{
		answer = sum(answer, mul(ml, ans[i]));
		ml = mul(ml, t);
	}
	printf("%d\n", answer);
    return 0;
}