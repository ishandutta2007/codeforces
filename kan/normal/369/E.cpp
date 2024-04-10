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

const int maxn = 300005;

const int treesize = 1<< 20;

const int OPEN =0 ;
const int QUERY = 1;

struct tev
{
	int x, t, y, id;
};

int tree[2 * treesize];
vector<tev> evs;
int answer[maxn];

void add(int cur, int cl, int cr, int x, int t)
{
	if (cl > x || cr < x) return;
	if (cl == cr)
	{
		tree[cur] += t;
		return;
	}
	tree[cur] += t;
	int cm = (cl + cr) / 2;
	add(cur * 2, cl, cm, x, t);
	add(cur * 2 + 1, cm + 1, cr, x, t);
}

int get(int cur, int cl, int cr, int l, int r)
{
	if (cl > r || cr < l) return 0;
	if (cl >= l && cr <= r) return tree[cur];
	int cm = (cl + cr) / 2;
	return get(cur * 2, cl, cm, l, r) + 
	get(cur * 2 + 1, cm + 1, cr, l, r);
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		evs.pb({l, OPEN, l, 1});
		evs.pb({r + 1, OPEN, l, -1});
	}
	for (int i = 0; i < m; i++)
	{
		int k;
		scanf("%d", &k);
		int last = -1;
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			evs.pb({x, QUERY, last + 1, i});
			last = x;
		}
	}
	sort(all(evs), [](const tev &a, const tev &b)
	{
		if (a.x != b.x) return a.x < b.x;
		return a.t == OPEN && b.t == QUERY;
	});
	for (auto t : evs)
	{
		//cout << t.x << ' ' << t.t << ' ' << t.y << ' ' << t.id << endl;
		if (t.t == OPEN) add(1, 0, treesize - 1, t.y, t.id);
		else answer[t.id] += get(1, 0, treesize - 1, t.y, t.x);
	}
	for (int i =0; i < m; i++) printf("%d ", answer[i]);
    return 0;
}