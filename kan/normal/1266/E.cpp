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

const int maxn = 200005;

int a[maxn];
int have[maxn];
int n, nq;
map<pair2<int>, int> bonuses;
ll answer;

void add(int x, int t)
{
	answer -= max(0, a[x] - have[x]);
	have[x] += t;
	answer += max(0, a[x] - have[x]);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	answer = accumulate(a, a + n, 0LL);
	scanf("%d", &nq);
	for (int q = 0; q < nq; q++)
	{
		int s, t, u;
		scanf("%d%d%d", &s, &t, &u);
		s--, u--;
		if (bonuses.count({s, t}))
		{
			add(bonuses[{s, t}], -1);
			bonuses.erase({s, t});
		}
		if (u != -1)
		{
			bonuses[{s, t}] = u;
			add(u, 1);
		}
		printf("%lld\n", answer);
	}
    return 0;
}