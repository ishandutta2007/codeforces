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

const int maxn = 55;

int n;
int m;

int a[maxn][maxn];
int p[maxn];
bool was[maxn];

int main () {
//  freopen (filename".in", "r", stdin);
//  freopen (filename".out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) scanf("%d", &a[i][j]), a[i][j]--;
	}
	for (int i = 0; i < n; i++) p[i] = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) if (!was[j])
		{
			bool ok = true;
			for (int t = 0; t < n; t++) if (t != j)
			{
				ok &= a[j][t] <= i;
			}	
			if (ok)
			{
				p[j] = i;
				was[j] = true;
				break;
			}	
		}
	}
	for (int i = 0; i < n; i++) printf("%d ", p[i] + 1);
	printf("\n");
	return 0;
}