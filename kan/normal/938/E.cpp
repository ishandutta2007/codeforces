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

inline int sum(int a, int b)
{
	a += b;
	if (a >= MOD) a -= MOD;
	return a;
}

inline int mul(int a, int b)
{
	return ((ll)a * b) % MOD;
}

inline int powmod(int a, int b)
{
	int tmp = a;
	int ans = 1;
	while (b)
	{
		if (b & 1) ans = mul(ans, tmp);
		tmp = mul(tmp, tmp);
		b >>= 1;
	}
	return ans;
}

inline int inv(int a)
{
	return powmod(a, MOD - 2);
}

const int maxn = 1000006;

int f[maxn], infv[maxn];
int a[maxn];

int main()
{
	f[0] = 1;
	for (int i = 1; i < maxn; i++) f[i] = mul(f[i - 1], i);
	infv[maxn - 1] = inv(f[maxn - 1]);
	for (int i = maxn - 2; i >= 0; i--) infv[i] = mul(infv[i + 1], i + 1);
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int answer = 0;
	for (int i = 0; i < n; i)
	{
		int j = i;
		while (j < n && a[j] == a[i]) j++;
		if (j == n) break;
		answer = sum(answer, mul(a[i], mul((j - i), mul(f[n], inv(n - i)))));
		//cout << i << ' ' << answer << endl;
		i = j;
	}
	cout << answer << endl;
    return 0;
}