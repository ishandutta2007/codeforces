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

vector<int> gr[maxn];
bool was[maxn];
vector<int> order, answer;
int len[maxn];
int n, m;

void go(int cur)
{
	if (was[cur]) return;
	was[cur] = true;
	for (auto t : gr[cur]) go(t);
	order.pb(cur);
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		gr[i].clear();
		was[i] = 0;
	}
	order.clear();
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].pb(b);
	}
	for (int i = 0; i < n; i++) if (!was[i]) go(i);
	reverse(all(order));
	for (int i = 0; i < n; i++) len[i] = 0;
	answer.clear();
	for (auto t : order)
	{
		if (len[t] == 2) answer.pb(t);
		else
		{
			for (auto z : gr[t]) len[z] = max(len[z], len[t] + 1);
		}
	}
	assert(7 * (int)answer.size() <= 4 * n);
	printf("%d\n", (int)answer.size());
	for (auto t : answer) printf("%d ", t + 1);
	printf("\n");
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		solve();
	}
    return 0;
}