// Coding on my mac
// My mac doesn't have bits/stdc++.h
// http://codeforces.com/blog/entry/47152 looks helpful
// If only I could be bothered setting things up

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

void fail()
{
	cout << "NO\n";
	exit(0);
}

struct edge
{
	int a, b; ll d;
	edge(int A, int B, ll D) : a(A), b(B), d(D) { }
};

vector<int> ch[1005];
vector<edge> edg;
ll dst[1005];
int n, m; ll l; int s, t;

ll djk()
{
	for (int i = 0;i < n;i++) dst[i] = 1ll<<59;
	priority_queue<pair<ll, int> > pq;
	pq.emplace(dst[s] = 0, s);
	while (!pq.empty())
	{
		auto u(pq.top()); pq.pop();
		if (dst[u.second]+u.first) continue;
		for (int i: ch[u.second])
		{
			int v = edg[i].a;
			if (v == u.second) v = edg[i].b;
			ll d = edg[i].d;
			if (d == 1ll<<59) continue;
			if (d-u.first < dst[v])
				pq.emplace(-(dst[v]=d-u.first), v);
		}
	}
	return dst[t];
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> l >> s >> t;
	for (int i = 0;i < m;i++)
	{
		int a, b; ll d; cin >> a >> b >> d;
		ch[a].push_back(edg.size());
		ch[b].push_back(edg.size());
		if (d == 0) d = 1ll<<59;
		edg.emplace_back(a, b, d);
	}
	ll res = djk();
	if (res < l) fail();
	for (auto& E : edg) if (E.d == 1ll<<59)
	{
		E.d = 1;
		res = djk();
		if (res > l) continue;
		cout << "YES\n";
		E.d += l - res;
		for (auto& i : edg)
			cout << i.a << ' ' << i.b << ' ' << i.d << '\n';
		return 0;
	}
	res = djk();
	if (res == l)
	{
		cout << "YES\n";
		for (auto& i : edg)
			cout << i.a << ' ' << i.b << ' ' << i.d << '\n';
		return 0;
	}
	fail();
	return 0;
}