#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct line
{
	int m, c; // y = mx + c
	line(int M, int C) : m(M), c(C) { }
	int calc(int x) const
	{ // find the y coordinate at x
		return m*x+c;
	}
};

struct ant
{
	int s;
	int d; // 0 for L, 1 for R
	int id;
	line makeline() const
	{ // make the suitable line for this ant (in the first period)
		if (d == 0)
			return line(-1, s);
		else
			return line(1, s);
	}
	bool operator< (const ant& oth) const
	{
		return (s < oth.s);
	}
};

vector<line> l;
int ans[300005];
ant a[300005];
int shift;
int n, m;
ll t;

int fix(int loc)
{ // things go out of range so lets fix them
	if (loc <= 0) loc += m;
	if (loc <= 0) loc += m;
	if (loc <= 0) loc += m;
	if (loc > m) loc -= m;
	if (loc > m) loc -= m;
	if (loc > m) loc -= m;
	return loc;
}

int travel(int loc, int per)
{
	// makes the ant at _loc_ walk, for _per_ time units
	// original locations
	vector<int> ycors;
	for (const line& u: l) ycors.push_back(u.calc(0));
	sort(ycors.begin(), ycors.end());
	int index = lower_bound(ycors.begin(), ycors.end(), loc) - ycors.begin();
	// final locations
	ycors.clear();
	for (const line& u: l) ycors.push_back(u.calc(per));
	sort(ycors.begin(), ycors.end());
	return fix(ycors[index]);
}

bool relevant(int val)
{ // will this value ever be reached
	return (val >= -m && val <= m);
}

int main()
{
	cin.sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> t;
	for (int i = 0;i < n;i++)
	{
		char tmp;
		cin >> a[i].s >> tmp;
		a[i].d = (tmp == 'R');
		a[i].id = i;
		// make the lines
		// we add all lines that could ever possibly be useful
		line me = a[i].makeline();
		while (true)
		{
			me.c -= m;
			if (!relevant(me.calc(0)) && !relevant(me.calc(m)))
				break;
		}
		for (me.c += m;relevant(me.calc(0)) || relevant(me.calc(m));me.c += m)
			l.push_back(me);
	}
	sort(a, a+n);
	// get cyclic shift per period
	int oloc = a[0].s;            // original location
	int nloc = travel(a[0].s, m); // new location after a period
	while (a[shift].s != nloc) shift++;
	// overall cyclic shift for all complete periods
	ll numperiods = t / m;
	shift = (shift * numperiods) % n;
	t %= m; // remaining time, which is the final incomplete period
	// note that a[0] is now located at a[shift]
	nloc = travel(a[shift].s, t); // this is the final location of a[0]
	// ambiguity? find the final location of a[1] as well
	int nloc2 = travel(a[(shift+1)%n].s, t);
	// set of all final locations
	vector<int> ycors;
	for (int i = 0;i < n;i++) ycors.push_back(fix(a[i].makeline().calc(t)));
	sort(ycors.begin(), ycors.end());
	// use nloc and nloc2 to find the amount by which this is offset
	shift = 0;
	while (ycors[shift] != nloc || ycors[(shift+1)%n] != nloc2) shift++;
	// find final locations of everyone
	for (int i = 0;i < n;i++)
		ans[a[i].id] = ycors[(i+shift)%n];
	for (int i = 0;i < n;i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}