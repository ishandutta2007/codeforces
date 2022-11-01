#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define se second
#define fi first
#define pb push_back
#define mp make_pair
const int maxn = 105;
const ll inf = (ll)1e17;

struct les
{
	ll a, b, c, i;
	bool operator< (const les& q) const
	{
		return c < q.c;
	}
	les(){};
};

ll d[55][55][110];
int anc[55][55][110];
int n, m;
ll u;
les a[maxn];

bool cmp(les a, les b)
{
	return a.i < b.i;
}
void scan()
{
	cin >> n >> m >> u;
	forn(i, m)
	{
		cin >> a[i].a >> a[i].b >> a[i].c;
		a[i].i = i;
	}
	sort(a, a+m);
}
void dp()
{
	forn(i, 55) forn(j, 55) forn(p, 110)
		d[i][j][p] = -1;
	forn(j, m) forn(k, a[j].b - a[j].a + 1)
	{
		//cout << 0 << " " << j << " " << k << endl;
		d[0][j][k] = a[j].a + k;
	}
	
	forn(i, n) forn(j, m) forn(k, a[j].b - a[j].a + 1)
	{
		if (d[i][j][k] == -1)
			continue;		
		ll curc = a[j].a + k, nxtc;
		//cout << i << " " << j << " " << k << "   " << d[i][j][k] << endl;
		
		forn(I, 2)
		{
			if (I == 0)
				nxtc = curc + u;
			else
				nxtc = curc * u;
			//cout << nxtc << endl;
			for (int p = j + 1; p < m; p++) if (a[j].c < a[p].c)
				if (nxtc >= a[p].a && nxtc <= a[p].b)
					if (d[i+1][p][nxtc - a[p].a] < d[i][j][k] + nxtc)
					{
						//cout << i+1 << " " << p << " " << nxtc - a[p].a << endl;
						d[i+1][p][nxtc - a[p].a] = d[i][j][k] + nxtc;
						anc[i+1][p][nxtc - a[p].a] = (p-j) * (I?1:(-1));
					}
		}
		//cout << endl;
	}
}
void getans()
{
	ll mx = -1, J=0, K=9;
	forn(j, m) forn(k, a[j].b - a[j].a + 1)
	{
		//cout << j << " " << k << endl;
		if (d[n-1][j][k] > mx)
			mx = max(mx, d[n-1][j][k]), J=j, K=k;
	}
			
	if (mx == -1)
	{
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	vector<pair<int, pair<int, ll> > > res; //i, num, amt
	for (int i = n-1; i >= 0; i--)
	{
		res.pb(mp(a[J].c, mp(a[J].i+1, K+a[J].a)));
		ll curc = K + a[J].a, nxtc;
		//cout << J << " " << K << " " << curc << endl;
		if (anc[i][J][K] > 0)
			nxtc = curc / u;
		else
			nxtc = curc - u;
		if (i)
		{
			J -= abs(anc[i][J][K]);
			K = nxtc - a[J].a;
		}
	}
	sort(res.begin(), res.end());
	forn(i, res.size())
		cout << res[i].se.fi << " " << res[i].se.se << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	scan();
	dp();
	getans();
	
	return 0;
}