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

const int maxn = 60;

int a[maxn];
int n;
int b[maxn];
vector<int> parts;
int wh[maxn];
vector<vector<int>> ops;

int main()
{
	scanf("%d", &n);
	for (int i =0 ; i < n; i++)
	{
		scanf("%d", &a[i]);
		a[i]--;
	}
	while (true)
	{
		for (int i = 0; i < n; i++) wh[a[i]] = i;
		int x = -1;
		for (int i = 0; i < n - 1; i++) if (wh[i + 1] < wh[i]) x = i;
		if (x == -1) break;
		int l = wh[x + 1];
		int r = wh[x];
		int m = -1;
		for (int i = l; i < r; i++) if (a[i + 1] != a[i] + 1) m = i;
		assert(m != -1);
		parts.clear();
		if (l > 0) parts.pb(l);
		parts.pb(m - l + 1);
		parts.pb(r - m);
		if (r != n - 1) parts.pb(n - 1 - r);
		ops.pb(parts);
		
		int cura = n;
		int curb = 0;
		for (int i = (int)parts.size() - 1; i >= 0; i--)
		{
			int t = parts[i];
			for (int j = cura - t; j < cura; j++)
			{
				b[curb++] = a[j];
			}
			cura -= t;
		}
		for (int i = 0; i < n; i++) a[i] = b[i];
	}
	printf("%d\n", (int)ops.size());
	for (auto z : ops)
	{
		printf("%d ", (int)z.size());
		for (auto t : z) printf("%d ", t);
		printf("\n");
	}
	fflush(stdout);
	for (int i = 0; i < n; i++) assert(a[i] == i);
    return 0;
}