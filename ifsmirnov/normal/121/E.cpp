#include <iostream>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <algorithm>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 100500;
const int k = 300;
const int maxnbl = maxn / k + 1;
const int maxnum = 10010;

int lucky[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777};
int nl = 30; //nlucky

bool islucky(int x)
{
	while (x)
	{
		if (x%10 != 4 && x%10 != 7)
			return false;
		x /= 10;
	}
	return true;
}

struct block
{
	int a[k];
	int cnt[maxnum];
	int add;
	int l, r;
	int nlucky;
	block()
	{
		memset(a, 0, sizeof a);
		memset(cnt, 0, sizeof cnt);
		add = nlucky = 0;
	}
	void reset()
	{
		forn(i, k)
			cnt[a[i]] = 0;
		forn(i, k)
			a[i] += add;
		add = 0;
	}
	void norm()
	{
		forn(i, k)
			cnt[a[i]]++;
	}
	int getLuck()
	{
		int s = 0;
		forn(i, nl)
			if (lucky[i] - add < 0)
				continue;
			else
				s += cnt[lucky[i] - add];
		return s;
	}
	void Add (int lq, int rq, int x)
	{
		if (lq <= l && rq >= r)
			add += x;
		else if (lq > r || rq < l)
			return;
		else
		{
			reset();
			fore(i, max(lq, l), min(rq, r))
				a[i-l] += x;
			norm();
		}
	}
	int query (int lq, int rq)
	{
		if (lq <= l && rq >= r)
			return getLuck();
		else if (lq > r || rq < l)
			return 0;
		else
		{
			int s = 0;
			fore(i, max(l, lq), min(r, rq))
				s += islucky(a[i-l] + add);
			return s;
		}
	}
	void pr()
	{
		forn(i, k)
			cout << a[i] + add << " ";
	}
};

block b[maxnbl];
int n, nbl, m;

void init()
{
	cin >> n >> m;
	int cbl = 0, pos = 0;
	forn(i, n)
	{
		if (pos == k)
			pos = 0, cbl++;
		cin >> b[cbl].a[pos++];
	}
	nbl = cbl + 1;
	forn(i, nbl)
	{
		b[i].l = i*k;
		b[i].r = i*k+k-1;
		b[i].norm();
	}
}

void add (int lq, int rq, int x)
{
	forn(i, nbl)
		b[i].Add(lq-1, rq-1, x);
}
int get (int lq, int rq)
{
	int s=0;
	forn(i, nbl)
		s += b[i].query(lq-1, rq-1);
	return s;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	init();
	char t[10];
	int a, q, c;
	forn(i, m)
	{
		//cerr << i << endl;
		cin >> t;
		if (t[0] == 'c')
		{
			cin >> a >> q;
			cout << get(a, q) << "\n";
		}
		else
		{
			cin >> a >> q >> c;
			add(a, q, c);
		}
	}
	//cerr << clock() / 1000 << endl;
	
	return 0;
}