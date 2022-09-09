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

const ll inf9 = 2e9;
const ll inf18 = 2e18;

const int maxn = 300005;

ll last[3];
ll lft[maxn][3];
ll rgh[maxn][3];
vector<pair2<int>> all;
int na, nb, nc;
ll answer;

inline void upd(ll a, ll b, ll c)
{
	if (abs(a) >= inf9 || abs(b) >= inf9 || abs(c) >= inf9) return;
	answer = min(answer, (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c));
}

void solve()
{
	scanf("%d%d%d", &na, &nb, &nc);
	all.clear();
	for (int i =0 ; i < na; i++)
	{
		int x;
		scanf("%d", &x);
		all.pb({x, 0});
	}
	for (int i =0 ; i < nb; i++)
	{
		int x;
		scanf("%d", &x);
		all.pb({x, 1});
	}
	for (int i =0 ; i < nc; i++)
	{
		int x;
		scanf("%d", &x);
		all.pb({x, 2});
	}
	sort(all(all));
	last[0] = last[1] = last[2] = -inf9;
	for (int i =0; i < (int)all.size(); i++)
	{
		for (int t = 0; t < 3; t++) lft[i][t] = last[t];
		last[all[i].se] = all[i].fi;
	}
	last[0] = last[1] = last[2] = +inf9;
	for (int i = (int)all.size() - 1; i >= 0; i--)
	{
		for (int t = 0; t < 3; t++) rgh[i][t] = last[t];
		last[all[i].se] = all[i].fi;
	}
	answer = inf18;
	for (int i = 0; i < (int)all.size(); i++)
	{
		int me = all[i].se;
		int o1 = (me + 1) % 3;
		int o2 = (me + 2) % 3;
		upd(lft[i][o1], all[i].fi, rgh[i][o2]);
		upd(lft[i][o2], all[i].fi, rgh[i][o1]);
	}
	printf("%lld\n", answer);
	
}

int main()
{
	int NT;
	scanf("%d", &NT);
	for (int T =0 ; T < NT; T++)
	{
		solve();
	}
    return 0;
}