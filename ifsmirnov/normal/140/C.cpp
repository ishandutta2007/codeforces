#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define tr(c, it) for (typeof (c).begin() it = (c).begin(); it != (c).end(); it++)
const int maxn = 200500;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double ld;
const int inf = 1e9+100500;
#define all(x) (x).begin(), (x).end()
typedef long long i64;
const ld eps = 1e-9;

void out (int a, int b, int c)
{
	vector<int> t;
	t.pb(a);
	t.pb(b);
	t.pb(c);
	sort(all(t), greater<int>());
	forn(i, 3) cout << t[i] << " ";
	cout << "\n";
}

int n;
set<pii, greater<pii> > a;
map<int,int> cnt;

int main()
{
	ios :: sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	int x;
	cin >> n;
	forn(i, n)
	{
		cin >> x;
		cnt[x]++;
	}
	vector<pair<int, pii> > res;
	for (map<int, int> :: iterator it = cnt.begin(); it != cnt.end(); it++)
		a.insert(mp(it->se, it->fi));
	while ((int)a.size() >= 3)
	{
		//tr(a, it) cout << it->fi << " " << it->se << "; ";cout<<endl;
		
		pii t1 = *a.begin();
		a.erase(t1);
			
		pii t2 = *a.begin();
		a.erase(t2);
			
		pii t3 = *a.begin();
		a.erase(t3);

		if (t1.fi != 1)
			a.insert(mp(t1.fi-1, t1.se));
		if (t2.fi != 1)
			a.insert(mp(t2.fi-1, t2.se));
		if (t3.fi != 1)
			a.insert(mp(t3.fi-1, t3.se));
		
		//tr(a, it) cout << it->fi << " " << it->se << "; ";cout<<endl;cout<<endl;
			
		res.pb(mp(t1.se, mp(t2.se, t3.se)));
	}
	cout << res.size() << endl;
	forn(i, res.size())
		out(res[i].fi, res[i].se.fi, res[i].se.se);
		
	return 0;
}