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

ll balance[maxn];
int n, m;
vector<array<ll, 3>> answer;
vector<pair2<ll>> neg, pos;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		balance[a] -= c;
		balance[b] += c;
	}
	for (int i = 0; i < n; i++)
	{
		if (balance[i] < 0) neg.pb({i, -balance[i]});
		if (balance[i] > 0) pos.pb({i, balance[i]});
	}
	while (!neg.empty())
	{
		assert(!pos.empty());
		ll give = min(pos.back().se, neg.back().se);
		pos.back().se -= give;
		neg.back().se -= give;
		answer.pb({neg.back().fi, pos.back().fi, give});
		if (pos.back().se == 0) pos.pop_back();
		if (neg.back().se == 0) neg.pop_back();
	}
	printf("%d\n", (int)answer.size());
	for (auto &t : answer) printf("%lld %lld %lld\n", t[0] + 1, t[1] + 1, t[2]);
    return 0;
}