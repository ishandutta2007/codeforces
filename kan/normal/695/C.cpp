#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

int n;
int m;
vi v[7][1000];
int nx[7];
int ny[7];
int mx[1000];
int my[1000];
int cnt[1000];
int was[7];
int r;
int q[100];

ll vect (ll x1, ll y1, ll x2, ll y2) {
	re x1 * y2 - x2 * y1;
}

ll scal (ll x1, ll y1, ll x2, ll y2) {
	re x1 * x2 + y1 * y2;
}

int go (int l) {
	if (r > n) re 0;
	if (l == r) re 1;
	int i = q[l];
	for (int j = 0; j < n; j++)
		if (!was[j] && sz (v[j][i]) <= n) {
			int oldr = r;
			for (int k = 0; k < sz (v[j][i]); k++) {
				int t = v[j][i][k];
				cnt[t]++;
				if (cnt[t] == 1) q[r++] = t;
			}
			was[j] = 1;
			if (go (l + 1)) re 1;
			was[j] = 0;
			for (int k = 0; k < sz (v[j][i]); k++) {
				int t = v[j][i][k];
				cnt[t]--;
			}
			r = oldr;
		}
	re 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf ("%d%d", &nx[i], &ny[i]);
	for (int i = 0; i < m; i++) scanf ("%d%d", &mx[i], &my[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < m; k++)
				if (vect (nx[i] - mx[k], ny[i] - my[k], mx[j] - mx[k], my[j] - my[k]) == 0 && scal (nx[i] - mx[k], ny[i] - my[k], mx[j] - mx[k], my[j] - my[k]) < 0) {
					v[i][j].pb (k);
					if (sz (v[i][j]) > n) break;
				}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		r = 0;
		q[r++] = i;
		memset (cnt, 0, sizeof (cnt));
		memset (was, 0, sizeof (was));
		cnt[i] = 1;
		if (go (0)) ans++;
	}
	printf ("%d\n", ans);
	return 0;
}