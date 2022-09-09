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

const int maxn = 100005;

int l[maxn], wh[maxn];
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) scanf("%d", &l[i]);
	int last = n;
	for (int i = m - 1; i >= 0; i--)
	{
		wh[i] = max(last - l[i], i);
		if (wh[i] + l[i] - 1 >= n)
		{
			cout << -1 << endl;
			return 0;
		}
		last = wh[i];
	}
	if (last != 0)
	{
			cout << -1 << endl;
			return 0;
	}
	for (int i = 0; i < m; i++) printf("%d ", wh[i] + 1);
	printf("\n");
    return 0;
}