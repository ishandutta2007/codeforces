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

const int maxn = 500005;

vector<int> gr[maxn];
int cnt[maxn];
int n, m;
int req[maxn];
vector<pair2<int>> all;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	for (int i =0 ; i < n; i++)
	{
		scanf("%d", &req[i]);
		req[i]--;
		all.pb({req[i], i});
	}
	sort(all(all));
	bool ok = true;
	for (auto t : all)
	{
		int id = t.se;
		for (auto t : gr[id]) cnt[req[t]]++;
		int curc = 0;
		while (cnt[curc] > 0) curc++;
		if (req[id] != curc) ok = false;
		for (auto t : gr[id]) cnt[req[t]]--;
	}
	if (ok)
	{
		for (auto t : all) printf("%d ", t.se + 1);
		printf("\n");
	} else printf("-1\n");
    return 0;
}