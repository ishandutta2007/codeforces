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

int was[maxn];
pair2<int> up1[maxn], up2[maxn];
int d[maxn];
vector<int> gr[maxn];
vector<pair2<int>> all;
bool good[maxn];
vector<int> answer;
bool ok;
int n, m;
int ord[maxn];

void go(int cur, int curd)
{
	was[cur] = 1;
	for (auto t : gr[cur])
	{
		if (was[t] == 1)
		{
			continue;
		}
		if (was[t] == 2)
		{
			ok = false;
			continue;
		}
		go(t, curd + 1);
	}
	was[cur] = 2;
}

inline void upd(pair2<int> &m1, pair2<int> &m2, pair2<int> u)
{
	if (u < m1)
	{
		m2 = m1;
		m1 = u;
	} else if (u < m2)
	{
		m2 = u;
	}
}

void go2(int cur, int curd)
{
	was[cur] = 1;
	d[cur] = curd;
	up1[cur] = {d[cur], cur};
	up2[cur] = {d[cur], cur};
	for (auto t : gr[cur])
	{
		if (was[t] == 1)
		{
			upd(up1[cur], up2[cur], {d[t], t});
			continue;
		}
		if (was[t] == 2)
		{
			ok = false;
			continue;
		}
		go2(t, curd + 1);
		upd(up1[cur], up2[cur], up1[t]);
		upd(up1[cur], up2[cur], up2[t]);
	}
	was[cur] = 2;
}

bool build(int start)
{
	for (int i =0 ; i < n; i++) was[i] = 0;
	ok = true;
	go(start, 0);
	return ok;
}

void calc(int start)
{
	//cout << "calc " << start << endl;
	for (int i =0 ; i < n; i++) was[i] = 0;
	ok = true;
	go2(start, 0);
	assert(ok);
	all.clear();
	for (int i = 0; i < n; i++) all.pb({d[i], i});
	//for (int i =0 ; i < n; i++) cout << i << ' ' << d[i] << ' ' << up1[i].fi << ' ' << up2[i].fi << endl;
	for (int i = 0; i < n; i++) good[i] = false;
	sort(all(all));
	for (auto t : all)
	{
		int id = t.se;
		if (d[id] == 0)
		{
			good[id] = true;
			answer.pb(id);
			continue;
		}
		if (up1[id].fi >= d[id]) continue;
		if (up2[id].fi < d[id]) continue;
		if (good[up1[id].se])
		{
			good[id] = true;
			answer.pb(id);
		}
	}
}

void solve()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) gr[i].clear();
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].pb(b);
	}
	iota(ord, ord + n, 0);
	shuffle(ord, ord + n, rng);
	answer.clear();
	for (int IT = 0; IT < min(n, 40); IT++)
	{
		bool good = build(ord[IT]);
		if (good)
		{
			calc(ord[IT]);
			break;
		}
	}
	if (answer.empty() || (int)answer.size() * 5 < n) printf("-1\n");
	else
	{
		sort(all(answer));
		for (auto t : answer) printf("%d ", t + 1);
		printf("\n");
	}
}

int main()
{
	string shash = "asdgkh 		 	 	 	 sdglkjdfhgvf3894foief 	 	 		 	 	 sdgniidfgb sfg ";
	unsigned long long hash = 0;
	for (auto c : shash) hash = hash * 239 + c;
	rng.seed(hash);
	int NT;
	scanf("%d", &NT);
	for (int T = 0; T < NT; T++)
	{
		solve();
	}
    return 0;
}