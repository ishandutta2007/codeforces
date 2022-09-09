#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

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
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> inline T sqr (T x) { re x * x; }

#define filename ""

const int N = 200100;

int n;
int m;
int t[N];
ld sum[N];
ld rev[N];
ld res[51][N];
pair<int, ld> q[N];

ld calc (int i, ll x, int k) {
	re x * rev[k] + (res[i - 1][k] - sum[k] * rev[k]);
}

ld cross (ld a1, ld b1, ld a2, ld b2) {
	re (b2 - b1) / (a1 - a2);
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf ("%d", &t[i]);
	sum[n] = 0;
	rev[n] = 0;
	ld ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum[i] = sum[i + 1] + t[i];
		rev[i] = rev[i + 1] + (ld)1 / t[i];
		ans += t[i] * rev[i];
	}
	for (int i = 1; i <= m; i++) {
		int o = 1;
		q[0] = mp (n - i + 1, -1e100);
		for (int j = n - i; j >= 0; j--)
			if (i == 1)
				res[i][j] = 0;
			else {
//				for (int k = 0; k < o; k++) printf ("%d,%.3f ", q[k].fi, (double)q[k].se);
//				printf ("\n");
				int l = 0, r = o;
				while (r - l > 1) {
					int s = (l + r) / 2; 
					if (q[s].se < sum[j]) l = s; else r = s;
				}
//				printf ("%.10f %d %d -> %d\n", (double)sum[j], i, j, q[l].fi);
				res[i][j] = calc (i, sum[j], q[l].fi);
				while (o > 1) {
					ld x = q[o - 1].se;
					if (calc (i, x, q[o - 1].fi) < calc (i, x, j)) o--; else break;
				}
				int k = q[o - 1].fi;
                ld x = cross (rev[k], res[i - 1][k] - sum[k] * rev[k], rev[j], res[i - 1][j] - sum[j] * rev[j]);
                q[o++] = mp (j, x);
			}
	}
	printf ("%.10f\n", (double)(ans - res[m][0]));
	cerr << clock () << endl;
	return 0;
}