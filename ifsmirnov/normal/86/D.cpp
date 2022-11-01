#include <ctime>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, b, e) for (int i = b; i <= e; i++)
#define in(a,b,c) ((a)<=(c)&&(a)>=(b))
const int maxn = 200500;
typedef pair<int, int> pii;
#define se second
#define fi first
#define mp make_pair

ll a[maxn];
ll c[1000500];
int n, t;
int p; //=sqrt(n)
pair<pii, int> q[maxn];
ll res[maxn];
bool cmp(pair<pii,int> a, pair<pii,int> b);

void scan();
void solve();

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	ios :: sync_with_stdio(false);
	scan();
	solve();
	cerr << clock()/1000;
	return 0;
};
void scan()
{
	cin >> n >> t;
	forn(i, n) cin >> a[i];
	forn(i, t)
	{
		cin >> q[i].fi.fi >> q[i].fi.se;
		q[i].se = i;
		q[i].fi.fi--,q[i].fi.se--;
	}
};
void solve()
{
	//p=(int)(sqrt((double)n));
	p=950;
	//cout << "p=" << p << endl;
	sort(q, q+t, cmp);
	
	ll cur=a[0];
	c[a[0]]=1;
	int l=0, r=0;
	//int ml, xl, mr, xr;
	forn(j, t)
	{
		int nl = q[j].fi.fi, nr = q[j].fi.se;
		//cout << nl << " " << nr << endl;
		int ml=min(l, nl), xl=max(l, nl), mr=min(r, nr), xr=max(r, nr);
		bool add = in(l, nl, nr);
		fore(i, ml, xl)
		{
			if (in(i, l, r) && !in(i, nl, nr))
			//if (add)
			{
				c[a[i]]--;
				cur -= a[i] * (c[a[i]] * 2 + 1);
			}
			else if (!in(i, l, r) && in(i, nl, nr))
			//else
			{
				cur += a[i] * (c[a[i]] * 2 + 1);
				c[a[i]]++;
			}
		}
		add = in(r, mr, xr);
		fore(i, mr, xr)
		{
			if (in(i, ml, xl)) continue;
			if (in(i, l, r) && !in(i, nl, nr))
			//if (!add)
			{
				c[a[i]]--;
				cur -= a[i] * (c[a[i]] * 2 + 1);
			}
			else if (!in(i, l, r) && in(i, nl, nr))
			//else
			{
				cur += a[i] * (c[a[i]] * 2 + 1);
				c[a[i]]++;
			}
		}
		l=nl, r=nr;
		res[q[j].se] = cur;
	}
	forn(i, t) cout << res[i] << "\n";
};
inline bool cmp (pair<pii, int> a, pair<pii, int> b)
{
	int l1 = a.fi.fi, r1 = a.fi.se, l2 = b.fi.fi, r2 = b.fi.se;
	l1 /= p, l2 /= p;
	return l1 < l2 || (l1 == l2 && r1 < r2);
};