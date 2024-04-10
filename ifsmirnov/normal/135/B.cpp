#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 200500;
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double ld;
const int inf = 1e9+100500;
const ld eps = 1e-9;
typedef long long i64;
#define op operator

struct pt
{
	int x,y;
	pt(int X=0,int Y=0):x(X),y(Y){};
	
	bool op< (pt a){return x < a.x || (x == a.x && y < a.y);}
};

i64 dist (pt a, pt b)
{
	return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

pii rect (pt a, pt b, pt c, pt d)
{
	i64 w = dist(a, b);
	i64 h = dist(b, c);
	i64 g = dist(a, c);
	if (dist(c, d) != w || dist(a, d) != h || dist(d, b) != g || g != w + h)
		return mp(-1, -1);
	else
		return mp(w, h);
}

pt p[10];
int a[10];

int main()
{
	//freopen("input.txt", "r", stdin);
	forn(i, 8) cin >> p[i].x >> p[i].y;
	forn(i, 8) a[i] = i;
	do
	{
		pii t1 = rect(p[a[0]], p[a[1]], p[a[2]], p[a[3]]);
		pii t2 = rect(p[a[4]], p[a[5]], p[a[6]], p[a[7]]);
		if (t1.fi == -1 || t2.fi == -1 || t1.se != t1.fi)
			continue;
		else
		{
			cout << "YES\n";
			cout << a[0]+1 << " " << a[1] + 1 << " " << a[2] + 1 << " " << a[3] + 1 << endl;
			cout << a[4]+1 << " " << a[5] + 1 << " " << a[6] + 1 << " " << a[7] + 1 << endl;
			return 0;
		}
	}
	while (next_permutation(a, a+8));
	cout << "NO\n";
	
	return 0;
}