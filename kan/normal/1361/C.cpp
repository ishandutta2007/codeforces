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

const int maxn = 2000006;

int a[maxn];
vector<pair2<int>> gr[maxn];
bool used[maxn];
vector<int> order;
int n;

void go(int cur)
{
	//cout << "go " << cur << endl;
	while (!gr[cur].empty())
	{
		auto e = gr[cur].back();
		gr[cur].pop_back();
		if (used[e.se]) continue;
		used[e.se] = used[e.se ^ 1] = true;
		go(e.fi);
		order.pb(e.se ^ 1);
		order.pb(e.se);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &a[2 * i], &a[2 * i + 1]);
	for (int k = 20; k >= 0; k--)
	{
		//cout << "k = " << k << endl;
		int mod = (1 << k);
		for (int i = 0; i < mod; i++) gr[i].clear();
		for (int i = 0; i < n; i++)
		{
			int x = a[2 * i] % mod;
			int y = a[2 * i + 1] % mod;
			gr[x].pb({y, 2 * i});
			gr[y].pb({x, 2 * i + 1});
		}
		//cout << "dsf" << endl;
		order.clear();
		bool ok = true;
		for (int i = 0; i < mod; i++) if (gr[i].size() % 2 != 0) ok = false;
		if (!ok) continue;
		memset(used, 0, sizeof used);
		for (int i = 0; i < mod; i++) if (!gr[i].empty())
		{
			go(i);
			break;
		}
		if ((int)order.size() == 2 * n)
		{
			printf("%d\n", k);
			for (auto t : order) printf("%d ", t + 1);
			printf("\n");
			return 0;
		}
	}
	assert(false);
    return 0;
}