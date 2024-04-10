#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 17080198121677825ll;

void reset(set<int>& x)
{
	set<int> tmp;
	for (int u: x) printf("%d ", u); printf("\n");
	for (int u: x) tmp.insert(u);
	x.clear();
	for (int u: tmp) x.insert(u);
}

struct node
{
	int lo, hi;
	ll mi, lz;
} tr[262144];

set<int> alive;
ll nx[100005];
int n, q;

void gnx(ll va, ll& x)
{
	while (x < va) x *= 42;
}

void prop(int at)
{
	tr[at*2].lz += tr[at].lz; tr[at*2].mi += tr[at].lz;
	tr[at*2+1].lz += tr[at].lz; tr[at*2+1].mi += tr[at].lz;
	tr[at].lz = 0;
}

void upd(int at, int lo, int hi, ll val)
{
	if (tr[at].lo == lo && tr[at].hi == hi)
	{
		tr[at].mi -= val;
		tr[at].lz -= val;
		return;
	}
	prop(at);
	int mid = (tr[at].lo+tr[at].hi) >> 1;
	if (hi <= mid) upd(at*2, lo, hi, val);
	else if (lo >= mid) upd(at*2+1, lo, hi, val);
	else
	{
		upd(at*2, lo, mid, val);
		upd(at*2+1, mid, hi, val);
	}
	tr[at].mi = min(tr[at*2].mi, tr[at*2+1].mi);
}

ll qu(int at, int lo, int hi)
{
	if (tr[at].lo == lo && tr[at].hi == hi)
		return tr[at].mi;
	prop(at);
	int mid = (tr[at].lo+tr[at].hi) >> 1;
	if (hi <= mid) return qu(at*2, lo, hi);
	if (lo >= mid) return qu(at*2+1, lo, hi);
	return min(qu(at*2, lo, mid), qu(at*2+1, mid, hi));
}

void setva(int idx, ll va)
{
	nx[idx] = 1; gnx(va, nx[idx]);
	int at = 1;
	while (tr[at].lo+1 < tr[at].hi)
	{
		prop(at);
		at <<= 1;
		if (idx >= tr[at].hi) at++;
	}
	tr[at].mi = nx[idx]-va; tr[at].lz = 0;
	for (at>>=1;at;at>>=1)
		tr[at].mi = min(tr[at*2].mi, tr[at*2+1].mi);
	if (va != INF)
		alive.insert(idx);
}

ll getva(int idx)
{
	return nx[idx]-qu(1, idx, idx+1);
}

void destroy(int idx)
{
	setva(idx, INF);
}

void fix(int idx)
{
	int wh = *alive.lower_bound(idx);
	setva(idx, getva(wh));
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0;i < n;i++)
		nx[i] = 1, alive.insert(i);
	for (int i = 0;i < 131072;i++)
		tr[i+131072].lo = i, tr[i+131072].hi = i+1, tr[i+131072].mi = INF;
	for (int i = 0;i < n;i++)
	{
		ll val; cin >> val;
		gnx(val, nx[i]);
		tr[i+131072].mi = nx[i] - val;
	}
	for (int i = 131071;i;i--)
	{
		tr[i].lo = tr[i*2].lo, tr[i].hi = tr[i*2+1].hi;
		tr[i].mi = min(tr[i*2].mi, tr[i*2+1].mi);
		tr[i].lz = 0;
	}
	while (q--)
	{
		int c; cin >> c;
		if (c == 1)
		{
			int idx; cin >> idx; idx--;
			if (alive.find(idx) == alive.end())
				fix(idx);
			cout << getva(idx) << "\n";
		} else if (c == 2)
		{
			int lo, hi; ll val; cin >> lo >> hi >> val; lo--, hi--;
			if (lo && alive.find(lo-1) == alive.end()) fix(lo-1);
			for (auto it = alive.lower_bound(lo);it != alive.end();)
				if (*it < hi)
				{
					destroy(*it);
					it = alive.erase(it);
				} else break;
			setva(hi, val);
		} else if (c == 3)
		{
			int lo, hi; ll val; cin >> lo >> hi >> val; lo--, hi--;
			if (lo && alive.find(lo-1) == alive.end()) fix(lo-1);
			if (alive.find(hi) == alive.end()) fix(hi);
			while (true)
			{
				upd(1, lo, hi+1, val);
				bool done = true;
				while (true)
				{
					int at = 1;
					while (at < 131072)
					{
						prop(at);
						at <<= 1;
						if (tr[at].mi > tr[at+1].mi) at++;
					}
					if (tr[at].mi < 0)
					{
						at -= 131072;
						ll diff = nx[at]; nx[at] *= 42;
						diff -= nx[at];
						upd(1, at, at+1, diff);
					} else if (tr[at].mi == 0)
					{
						done = false;
						break;
					} else break;
				}
				if (done)
					break;
			}
		}
	}
	return 0;
}