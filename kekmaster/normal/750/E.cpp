#pragma region Template
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <complex>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#define mp make_pair
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define print_var(x) cout << #x << " : " << (x) << endl
#define print_array(arr, len) {cout << #arr << " : "; for(int i = 0; i < len; ++i) cout << arr[i] << ' '; cout << endl;}
#define print_2d_array(arr, len1, len2) {cout << #arr << endl; for(int i = 0; i < len1; ++i, cout << endl) for(int j = 0; j < len2; ++j) cout << arr[i][j] << ' ';}
#define print_iterable(i) {cout << #i << " : "; for(auto e : i) cout << e << ' '; cout << endl;}
#define print_new_line() cout << endl
#else
#define eprintf(...) (void)0
#define print_var(x) (void)0
#define print_array(arr, len) {}
#define print_2d_array(arr, len1, len2) {}
#define print_iterable(i) {}
#define print_new_line() (void)0
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-7;
const ld EPS = 1e-11;

#pragma endregion

const int b = 10;
const int N = 2e5 + 10;
string YEAR = "2016";
string BAD[b];
vector<int> prefs[b], suffs[b];

struct Item
{
	int dp[b];
	Item(): dp() {}
	Item operator+ (const Item& it) const
	{
		Item res;
		for (int i = 0; i < b; ++i)
		{
			int val = INF;
			for (int j = 0; j < prefs[i].size(); ++j)
				val = min(val, dp[prefs[i][j]] + it.dp[suffs[i][j]]);
			res.dp[i] = val;
		}
		return res;
	}
	void print()
	{
		print_array(dp, b);
	}
};

int n, q;
char seq[N];
Item tree[4 * N];

struct Segt
{
	void build(int n)
	{
		build(1, 0, n - 1);
	}
	void build(int ind, int l, int r)
	{
		if (l == r)
		{
			for (int i = 0; i < 4; ++i)
				if (BAD[i][0] == seq[l])
					tree[ind].dp[i] = 1;
			return;
		}
		int m = (l + r) / 2;
		build(ind * 2, l, m);
		build(ind * 2 + 1, m + 1, r);
		tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
	}
	Item get(int l, int r)
	{
		return get(1, 0, n - 1, l, r);
	}
	Item get(int ind, int l, int r, int L, int R)
	{
		if (L <= l && r <= R)
			return tree[ind];
		if (r < L || R < l)
			return Item();
		int m = (l + r) / 2;
		return get(ind * 2, l, m, L, R) +
			get(ind * 2 + 1, m + 1, r, L, R);
	}
} segt;

bool startswith(string a, string b)
{
	if (b.size() > a.size())
		return false;
	for (int i = 0; i < b.size(); ++i)
		if (b[i] != a[i])
			return false;
	return true;
}

bool endswith(string a, string b)
{
	if (b.size() > a.size())
		return false;
	for (int i = 0; i < b.size(); ++i)
		if (b[i] != a[a.size() - b.size() + i])
			return false;
	return true;
}

vector<int> poses[b];

int get_prev(vector<int>& v, int pos)
{
	auto it = upper_bound(v.begin(), v.end(), pos);
	if (it == v.begin())
		return -1;
	return *prev(it);
}

const int POS2 = 0;
const int POS20 = 4;
const int POS201 = 7;


void solve()
{
	for (auto &c : YEAR)
		c -= '0';
	int sz = 0;
	for (int len = 1; len <= YEAR.size(); ++len)
		for (int i = 0; i + len <= YEAR.size(); ++i)
		{
			BAD[sz] = YEAR.substr(i, len);
			for (int j = 0; j <= sz; ++j)
			{
				if (startswith(BAD[sz], BAD[j]))
					prefs[sz].push_back(j);
				if (endswith(BAD[sz], BAD[j]))
					suffs[sz].push_back(j);
			}
			reverse(suffs[sz].begin(), suffs[sz].end());
			++sz;
		}
	scanf("%d%d", &n, &q);
	scanf("%s", seq);
	for (int i = 0; i < n; ++i)
	{
		seq[i] -= '0';
		poses[seq[i]].push_back(i);
	}
	segt.build(n);
	//segt.get(0, 3).print();
	while(q--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		--l, --r;
		int pos7, pos1, pos0, pos2;
		pos7 = get_prev(poses[7], r);
		pos1 = get_prev(poses[1], pos7);
		pos0 = get_prev(poses[0], pos1);
		pos2 = get_prev(poses[2], pos0);
		if (pos2 == -1 || pos2 < l)
		{
			puts("-1");
			continue;
		}
		auto item = segt.get(l, pos2);
		item.dp[POS2] = INF;
		item = item + segt.get(pos2 + 1, pos0);
		item.dp[POS20] = INF;
		item = item + segt.get(pos0 + 1, pos1);
		item.dp[POS201] = INF;
		item = item + segt.get(pos1 + 1, r);
		printf("%d\n", item.dp[b - 1]);
	}
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("alter.in", "r", stdin);
	//freopen("alter.out", "w", stdout);
#endif

#ifdef ST
	while (true)
	{
		solve();
	}
#endif
#ifdef MULTITEST
	int t;
	scanf("%d", &t);
	while (t--)
#endif
		solve();

	eprintf("\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
}