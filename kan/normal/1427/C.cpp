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
const int inf = maxn;

int t[maxn], x[maxn], y[maxn], ans[maxn];
int sz, n;

int main()
{
	scanf("%d%d", &sz, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d%d", &t[i], &x[i], &y[i]);
	}
	int ans0 = -inf;
	ans[0] = 0;
	t[0] = 0;
	x[0] = 1;
	y[0] = 1;
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i - 2 * sz >= 0) ans0 = max(ans0, ans[i - 2 * sz]);
		ans[i] = ans0 + 1;
		for (int j = max(0, i - 2 * sz + 1); j < i; j++) if (t[i] - t[j] >= abs(x[i] - x[j]) + abs(y[i] - y[j]))
		{
			//cout << "here " << endl;
			ans[i] = max(ans[i], ans[j] + 1);
		}
		answer = max(answer, ans[i]);
	}
	printf("%d\n", answer);
    return 0;
}