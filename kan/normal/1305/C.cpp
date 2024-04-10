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

int n, m;

inline int mul(int a, int b)
{
	return (a * b) % m;
}

inline int powmod(int a, ll b)
{
	int ans = 1;
	int tmp = a;
	while (b)
	{
		if (b & 1) ans = mul(ans, tmp);
		tmp = mul(tmp, tmp);
		b >>= 1;
	}
	return ans;
}

const int maxn = 200005;

int a[maxn], cnt[maxn];
ll pows[maxn];


int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		cnt[a[i] % m]++;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		cnt[a[i] % m]--;
		for (int j = 0; j < m; j++)
		{
			int t = (a[i] + j) % m;
			pows[j] += cnt[t];
		}
	}
	int answer = 1;
	for (int i = 0; i < m; i++) answer = mul(answer, powmod(i, pows[i]));
	cout << answer << endl;
    return 0;
}