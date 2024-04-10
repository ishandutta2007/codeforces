#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 100500;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
typedef pair<int, int> pii;
typedef long long i64;
const int mod = 1e9+7;
inline int madd (int x, int y) {return (x+y)%mod;}

struct pt
{
	i64 x, y;
	pt(){}
	pt(i64 X, i64 Y):x(X), y(Y) {}
	i64 operator* (const pt& p) {return x*p.y-y*p.x;}
	pt operator- (const pt& p) {return pt(x-p.x, y-p.y);}
	bool operator< (const pt& p) const {return mp(x, y) < mp(p.x, p.y);}
	bool operator== (const pt& p) const {return mp(x, y) == mp(p.x, p.y);}
};

typedef vector<pt> poly;

int nxt(int x, int n) {return (x+1)%n;}
int prv(int x, int n) {return (x-1+n)%n;}
void split(const poly& p, poly& u, poly& d)
{
	int mn = 0, mx = 0;
	forn(i, p.size())
	{
		if (p[i] < p[mn]) mn = i;
		if (p[mx] < p[i]) mx = i;
	}
	
	for (int i = mn; i != mx; i = nxt(i, p.size()))
		u.pb(p[i]);
	for (int i = mn; i != mx; i = prv(i, p.size()))
		d.pb(p[i]);
	u.pb(p[mx]);
	d.pb(p[mx]);
}

int sgn(i64 x) {return (x>0) - (x<0);}
int relpos(pt a, pt b, pt p)
{
	return sgn((b-a)*(p-a));
}
int relpos(const poly& a, pt p)
{
	if (p.x < a[0].x || p.x > a.back().x) return 2;
	if (p < a[0]) return -1;
	int pos = lower_bound(a.begin(), a.end(), p) - a.begin();
	if (a[pos] == p) return 0;
	return relpos(a[pos-1], a[pos], p);
}

poly a, u, d, b;

void get(poly& p)
{
	int n;
	cin >> n;
	p.resize(n);
	forn(i, n) cin >> p[i].x >> p[i].y;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	
	get(a);get(b);
	
	split(a, u, d);
	//forn(i, u.size()) cout << u[i].x << " " << u[i].y << ", ";cout << endl;
	//forn(i, d.size()) cout << d[i].x << " " << d[i].y << ", ";cout << endl;
	forn(i, b.size())
	{
		//cout << relpos(u, b[i]) << endl;
		if (relpos(u, b[i]) != -1 || relpos(d, b[i]) != 1)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	
	return 0;
}