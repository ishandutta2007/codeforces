#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace MQ // mosquitoes
{
	multiset<pair<int, ll> > mq;
	void add(int p, ll b)
	{ mq.emplace(p, b); }
	ll getnext(ll LO, ll HI)
	{
		int lo = LO, hi = min(HI, 1073741824ll);
		auto it = mq.lower_bound(make_pair(lo, -1ll));
		if (it == mq.end()) return -1ll;
		if ((*it).first >= hi) return -1ll;
		ll res = (*it).second;
		mq.erase(it);
		return res;
	}
};

namespace FR // frogs
{
	struct node
	{
		node *l, *r;
		int lo, hi, va;
		node(int L, int H) : l(NULL), r(NULL), lo(L), hi(H), va(1073741824) { }
		void fix()
		{
			if (lo+1 < hi)
			{
				int mid = (lo+hi) >> 1;
				if (!l) l = new node(lo, mid);
				if (!r) r = new node(mid, hi);
				l->va = min(l->va, va);
				r->va = min(r->va, va);
			}
		}
		void upd(int rlo, int rhi, int val)
		{
			if (lo == rlo && hi == rhi)
			{
				va = min(va, val);
				return;
			}
			fix();
			int mid = (lo+hi) >> 1;
			if (rhi <= mid)
				l->upd(rlo, rhi, val);
			else if (rlo >= mid)
				r->upd(rlo, rhi, val);
			else
			{
				l->upd(rlo, mid, val);
				r->upd(mid, rhi, val);
			}
		}
		int qu(int wh)
		{
			if (lo+1 == hi) return va;
			fix();
			int mid = (lo+hi) >> 1;
			if (wh < mid) return (l->qu(wh));
			return (r->qu(wh));
		}
	} *rt;
	void init()
	{ rt = new node(0, 1073741824); }
	void upd(ll lo, ll hi, ll val)
	{ lo = min(lo, 1073741824ll); hi = min(hi, 1073741824ll); if (lo != hi) rt->upd(lo, hi, val); }
	int qu(ll wh)
	{ return rt->qu(wh); }
};

map<ll, pair<int, ll> > ans;
ll x[200005], t[200005];
int n, m;

int main()
{
	FR::init();
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++)
	{
		scanf("%lld%lld", x+i, t+i);
		FR::upd(x[i], x[i]+t[i]+1, x[i]);
		ans[x[i]] = make_pair(0, t[i]);
	}
	for (int i = 0;i < m;i++)
	{
		ll p, b; scanf("%lld%lld", &p, &b);
		int what = FR::qu(p);
		if (what == 1073741824)
		{
			MQ::add(p, b);
			continue;
		}
		FR::upd(what+ans[what].second+1, what+ans[what].second+b+1, what);
		ans[what].first++; ans[what].second += b;
		while (true)
		{
			ll nxt = MQ::getnext(what, what+ans[what].second+1);
			if (nxt == -1ll) break;
			FR::upd(what+ans[what].second+1, what+ans[what].second+nxt+1, what);
			ans[what].first++; ans[what].second += nxt;
		}
	}
	for (int i = 0;i < n;i++)
		printf("%d %lld\n", ans[x[i]].first, ans[x[i]].second);
	return 0;
}