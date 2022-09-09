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
const int maxk = 30;

int n;
int a[maxn], b[maxn];
int cnt[maxk];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		for (int k = 0; k < maxk; k++) if (a[i] & (1 << k)) cnt[k]++;
	}
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
		for (int k = 0; k < maxk; k++) if ((a[i] & (1 << k)) && cnt[k] == 1)
		{
			b[i] |= (1 << k);
		}
	}
	int wh = max_element(b, b + n) - b;
	rotate(a, a + wh, a + n);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
    return 0;
}