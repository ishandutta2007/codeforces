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

const int maxn = 17;
const int maxtsz = 1 << maxn;
const int inf = 1e9;

int tree[2 * maxtsz];

pair2<int> calc(int cur, int len)
{
	if (len == 2)
	{
		if (tree[cur] == 0) return {-inf, 0};
		return {1, 1};
	}
	if (tree[cur] == 0) return {-inf, 0};
	auto rl = calc(cur * 2, len / 2);
	auto rr = calc(cur * 2 + 1, len / 2);
	if (tree[cur] == 1) return {max(rl.fi, rr.fi) + 1, max(rl.se, rr.se) + 2};
	//cout << rl.fi << ' ' << rl.se << ' ' << rr.fi << ' ' << rr.se << endl;
	auto res = mp(0, 0);
	res.fi = max(rl.fi + max(rr.fi, rr.se), max(rl.fi, rl.se) + rr.fi) + 3;
	res.se = rr.se + rl.se + 2;
	//cout << cur << ' ' << len << ' ' << res.fi << ' ' << res.se << endl;
	return res;
}

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	if (k == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	int treesize = 1 << n;
	for (int i = 0; i < k; i++)
	{
		int x;
		scanf("%d", &x);
		x--;
		tree[treesize + x] = 1;
	}
	for (int i = treesize - 1; i > 0; i--)
	{
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
	auto answer = calc(1, (1 << n));
	int res = max(answer.fi, answer.se) + 1;
	cout << res << endl;
    return 0;
}