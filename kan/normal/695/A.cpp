#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x.size()))

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

double p[20];
double res[1 << 20];
double q[20];

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf ("%lf", &p[i]);
	for (int i = 0; i < n; i++) res[1 << i] = p[i];
	for (int i = 0; i < n; i++) q[i] = 0;
	for (int i = 1; i < (1 << n); i++) {
		vi v, w;
		double sum = 0;
		for (int j = 0; j < n; j++)
			if ((i >> j) & 1)
				v.pb (j);
			else {
				w.pb (j);
				sum += p[j];
			}
		if (sz (v) == m || (sz (v) < m && sum < 1e-5)) {
			for (auto x : v) q[x] += res[i];
		} else
		if (sz (v) < m) {
			for (auto x : w) res[i | (1 << x)] += res[i] * p[x] / sum;
		}
	}
	for (int i = 0; i < n; i++) printf ("%.15f ", q[i]);
	printf ("\n");
	return 0;
}