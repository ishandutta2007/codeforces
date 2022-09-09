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

const int maxn = 55;

int a[maxn];
int n;

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	int ss = accumulate(a, a + n, 0);
	if (ss > 0) reverse(a, a + n);
	bool ok = true;
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		s += a[i];
		if (s == 0) ok = false;
	}
	if (!ok) printf("NO\n");
	else
	{
		printf("YES\n");
		for (int i =0; i < n; i++) printf("%d ", a[i]);
		printf("\n");
	}
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T =0 ; T < NT; T++) solve();
    return 0;
}