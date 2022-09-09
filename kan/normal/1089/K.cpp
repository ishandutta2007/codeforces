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

const int treesize = 1 << 20;
const int maxn = 300005;

const ll inf = 1e18;

struct tnode
{
	ll sum, exit;
};

tnode tree[2 * treesize];
int at[maxn];

inline tnode merge(tnode a, tnode b)
{
	tnode ans;
	ans.sum = a.sum + b.sum;
	ans.exit = max(a.exit + b.sum, b.exit);
	return ans;
}

inline void pull(int cur)
{
	tree[cur] = merge(tree[cur * 2], tree[cur * 2 + 1]);
}

inline tnode get(int cur, int cl, int cr, int l, int r)
{
	if (cl > r || cr < l) return {0, -inf};
	if (cl >= l && cr <= r)
	{
		//cout << cur << ' ' << cl << ' ' << cr << ' ' << tree[cur].exit << endl;
		return tree[cur];
	}
	int cm = (cl + cr) / 2;
	return merge(get(cur * 2, cl, cm, l, r), get(cur * 2 + 1, cm + 1, cr, l, r));
}

void add(int cur, int cl, int cr, int x, int d)
{
	if (cl > x || cr < x) return;
	if (cl == cr)
	{
		tree[cur].sum = d;
		tree[cur].exit = x + d;
		return;
	}
	int cm = (cl + cr) / 2;
	add(cur * 2, cl, cm, x, d);
	add(cur * 2 + 1, cm + 1, cr, x, d);
	pull(cur);
}

ll query(int t)
{
	//cout << "q " << t << endl;
	ll ext = get(1, 0, treesize - 1, 1, t).exit;
	return ext - t;
}

char s[5];

int main()
{
	for (int i = 0; i < treesize; i++) tree[treesize + i] = {0, i};
	for (int i = treesize - 1; i > 0; i--) tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
	int NQ;
	scanf("%d", &NQ);
	for (int Q = 0; Q < NQ; Q++)
	{
		scanf("%s", s);
		if (s[0] == '?')
		{
			int t;
			scanf("%d", &t);
			printf("%lld\n", query(t));
		} else if (s[0] == '+')
		{
			int t, d;
			scanf("%d%d", &t, &d);
			at[Q] = t;
			add(1, 0, treesize - 1, t, d);
		} else
		{
			int id;
			scanf("%d", &id);
			id--;
			add(1, 0, treesize - 1, at[id], 0);
		}
	}
    return 0;
}