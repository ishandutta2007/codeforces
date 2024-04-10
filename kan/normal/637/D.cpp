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

int n;
int m;
int s, d;
vii res;
int x[200100];

int main () {
	scanf ("%d%d%d%d", &n, &m, &s, &d);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	sort (x, x + n);
	if (x[n - 1] + 1 < m) res.pb (mp (0, m - x[n - 1] - 1));
	int last = x[n - 1] + 1;
	for (int i = n - 2; i >= 0; i--)
		if (x[i + 1] - x[i] - 2 >= s && x[i + 1] - 1 + d >= last) {
			res.pb (mp (1, last - (x[i + 1] - 1)));
			res.pb (mp (0, x[i + 1] - x[i] - 2));
			last = x[i] + 1;
		}
	if (x[0] - 1 >= s && x[0] - 1 + d >= last) {
		res.pb (mp (1, last - (x[0] - 1)));
		res.pb (mp (0, x[0] - 1));
	} else {
		printf ("IMPOSSIBLE\n");
		re 0;
	}
	for (int i = sz (res) - 1; i >= 0; i--) printf ("%s %d\n", res[i].fi == 0 ? "RUN" : "JUMP", res[i].se);
	return 0;
}