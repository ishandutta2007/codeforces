// Nizhny Novgorod SU
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define next next_sdf
#define prev prev_sdf
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;


template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> int sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

struct pt
{
	int x, y;
};

inline pt operator-(const pt &a, const pt &b)
{
	return {a.x - b.x, a.y - b.y};
}

inline ll operator*(const pt &a, const pt &b)
{
	return (ll)a.x * b.y - (ll)a.y * b.x;
}

inline bool in(pt a, pt b, pt c, pt d)
{
	if ((b - a) * (c - a) < 0) swap(b, c);
	return (b - a) * (d - a) >= 0 && (c - b) * (d - b) >= 0 && (a - c) * (d - c) >= 0;
}

inline bool ok(pt a, pt b, pt c)
{
	return (b - a) * (c - a) != 0;
}

const int maxn = 100005;

pt p[maxn];
int n;

int main () {
//  freopen (filename".in", "r", stdin);
//  freopen (filename".out", "w", stdout);
	scanf("%d", &n);	
	for (int i = 0; i < n; i++) scanf("%d%d", &p[i].x, &p[i].y);
	int i1 = 0;
	int i2 = 1;
	int i3 = 2;
	while (!ok(p[i1], p[i2], p[i3])) i3++;
	for (int i = 0; i < n; i++) if (i1 != i && i2 != i && i3 != i && in(p[i1], p[i2], p[i3], p[i]))
	{
		if (ok(p[i1], p[i2], p[i])) i3 = i;
		else if (ok(p[i1], p[i], p[i3])) i2 = i;
		else if (ok(p[i], p[i2], p[i3])) i1 = i;
	}
	printf("%d %d %d\n", i1 + 1, i2 + 1, i3 + 1);
	return 0;
}