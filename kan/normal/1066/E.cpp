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

const int MOD = 998244353;

inline int mul(int a, int b)
{
	return ((ll)a * b) % MOD;
}

const int maxn = 200005;

char sa[maxn], sb[maxn];
int sumb[maxn];
int n, m;
int p2[maxn];

int main()
{
	p2[0] =1;
	for (int i = 1; i < maxn; i++) p2[i] = mul(p2[i - 1], 2);
	scanf("%d%d", &n, &m);
	scanf("%s%s", sa, sb);
	for (int i = 0; i < m; i++) sumb[i + 1] = sumb[i] + sb[i] - '0';
	int answer = 0;
	for (int i = 0; i < n; i++) if (sa[i] == '1')
	{
		int pos = m - (n - i);
		//cout << n - i - 1 << ' ' << sumb[pos + 1] << endl;
		if (pos >= 0) answer = (answer + mul(p2[n - i - 1], sumb[pos + 1])) % MOD;
	}
	cout << answer << endl;
    return 0;
}