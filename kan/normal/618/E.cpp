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

const ld pi = acos((ld)-1);

const int treesize = 1 << 19;

ld x[2 * treesize], y[2 * treesize];
ld angle[2 * treesize];
int n, m;


inline void update(int cur)
{
	int l = cur * 2;
	int r = cur * 2 + 1;
	angle[cur] = angle[l] + angle[r];
	ld xn = x[r] * cos(angle[l]) - y[r] * sin(angle[l]);
	ld yn = x[r] * sin(angle[l]) + y[r] * cos(angle[l]);
	x[cur] = x[l] + xn;
	y[cur] = y[l] + yn;
//	cout << "update " << cur << ' ' << (D)x[cur] << ' ' << (D)y[cur] << ' ' << (D)angle[cur] << endl;
}

void addlength(int cur, int cl, int cr, int p, int t)
{
	if (cl > p || cr < p) return;
	if (cl == cr)
	{
		x[cur] += (ld)t;
		return;
	}
	int cm = (cl + cr) / 2;
	addlength(cur * 2, cl, cm, p, t);
	addlength(cur * 2 + 1, cm + 1, cr, p, t);
	update(cur);
}

void addangle(int cur, int cl, int cr, int x, ld t)
{
	if (cl > x || cr < x) return;
	if (cl == cr)
	{
		angle[cur] -= t;
		return;
	}
	int cm = (cl + cr) / 2;
	addangle(cur * 2, cl, cm, x, t);
	addangle(cur * 2 + 1, cm + 1, cr, x, t);
	update(cur);
}

int main () {
//  freopen (filename".in", "r", stdin);
//  freopen (filename".out", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		angle[treesize + i] = 0;
		x[treesize + i] = 1;
		y[treesize + i] = 0;
	}	
	for (int i = treesize - 1; i > 0; i--) update(i);
//	printf("%.20lf %.20lf\n", (D)x[1], (D)y[1]);
	for (int i = 0; i < m; i++)
	{
		int t, l, amount;
		scanf("%d%d%d", &t, &l, &amount);
		if (t == 1) // length
		{
			addlength(1, 0, treesize - 1, l, amount);
		} else // angle
		{
			addangle(1, 0, treesize - 1, l - 1, (ld)amount / 180 * pi);
		}
		printf("%.20lf %.20lf\n", (D)x[1], (D)y[1]);
	}
	return 0;
}