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

vector<int> gr[maxn];
vector<pair2<int>> ans;
int n;
int maxd;

void go(int cur, int pr, int curt)
{
	ans.pb({cur, curt});
	vector<int> sons;
	for (auto t : gr[cur]) if (t != pr) sons.pb(t);
	
	int wast = curt;
	int curd = (int)sons.size();
	for (int i = 0; i < curd; i++)
	{
		if (curt == maxd)
		{
			int remains = curd - i;
			int needt = wast - 1 - remains;
			ans.pb({cur, needt});
			curt = needt;
		}
		go(sons[i], cur, curt + 1);
		curt++;
		ans.pb({cur, curt});
	}
	if (curt > wast - 1)
	{
		ans.pb({cur, wast - 1});
		curt = wast - 1;
	}
	assert(curt == wast - 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].pb(b);
		gr[b].pb(a);
	}
	maxd = 0;
	for (int i = 0; i < n; i++) maxd = max(maxd, (int)gr[i].size());
	go(0, -1, 0);
	ans.pop_back();
	printf("%d\n", (int)ans.size());
	for (auto t : ans) printf("%d %d\n", t.fi + 1, t.se);
    return 0;
}