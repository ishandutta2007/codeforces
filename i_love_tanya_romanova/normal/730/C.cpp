#pragma comment(linker, "/STACK:36777216")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>

#include <unordered_map>

using namespace std;

#ifdef LOCAL
#define debug_flag 1
#else
#define debug_flag 0
#endif

template <class T1, class T2 >
std::ostream& operator << (std::ostream& os, const pair<T1, T2> &p)
{
	os << "[" << p.first << ", " << p.second << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	os << "[";
	bool first = true;
	for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		if (!first)
			os << ", ";
		first = false;
		os << *it;
	}
	os << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<vector<T>>& v)
{

	os << "[" << endl;
	bool first = true;
	for (typename std::vector<vector<T>>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		os << *it << endl;
	}
	os << "]" << endl;
	return os;
}

const int N = 200000;

int tests;
int loc, need, money;
int n, m;
vector<int> g[N];
int w;
int c[N], k[N], p[N];

vector<int> at_dist[5050];
int used[N];
queue<int> qu;

void trace_dist(int V)
{
	for (int i = 1; i <= n; i++)
	{
		used[i] = 0;
	}
	for (int i = 0; i <= n; i++)
	{
		at_dist[i].clear();
	}

	used[V] = 1;
	qu.push(V);
	while (qu.size())
	{
		int v = qu.front();
		qu.pop();
		for (int i = 0; i < g[v].size(); i++)
		{
			int to = g[v][i];
			if (used[to])
				continue;
			used[to] = used[v]+1;
			qu.push(to);
		}
	}
}

vector<pair<int, int> > store_order;

bool valid(int bound)
{
	int cur_used = 0;
	long long cur_money = 0;

	for (int i = 0; i < store_order.size(); i++)
	{
		int id = store_order[i].second;
		int whr = c[id];
		if (used[whr] == 0 || used[whr]>bound + 1)
			continue;
		int can_take = min(need - cur_used, k[id]);
		cur_money += 1ll*can_take*p[id];
		cur_used += can_take;
	}
	if (cur_used<need || cur_money>money)
		return false;
	return true;
}

int main()
{
#ifdef LOCAL
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(0);

	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cin >> w;
	for (int i = 1; i <= w; i++)
	{
		cin >> c[i] >> k[i] >> p[i];
		store_order.push_back(make_pair(p[i], i));
	}

	sort(store_order.begin(), store_order.end());

	cin >> tests;

	for (; tests; --tests)
	{
		cin >> loc >> need >> money;
		trace_dist(loc);
//		cout << "@" << endl;
		int l, r;
		l = 0;
		r = n;
		
		if (!valid(n))
		{
			cout << -1 << endl;
			continue;
		}

		while (l < r)
		{
			int mid = l + r;
			mid /= 2;
//			cout << l << "%" << r << " " << mid << endl;
			if (valid(mid))
				r = mid;
			else
				l = mid + 1;
		}
		cout << l << endl;
	}

	return 0;
}