#include <bits/stdc++.h>

using namespace std;

#define re return
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define fill(x,y) memset(x,y,sizeof(x))
#define mp make_pair
#define pb push_back
#define j0 j237849523
#define j1 j5435324
#define y0 y2543
#define y1 y548975
#define prev PREV
#define next NEXT
#define left LEFT
#define right RIGHT

typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef double D;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sqr (T x) { re x * x; }

const double pi = 2 * asin (1.0);

const int N = 100100;

int n;
int m;
ii v[N];
ii w[N];
ii q[N];
int x, y;

ll vect (ii a, ii b, ii c) {
    re (ll)(b.fi - a.fi) * (c.se - b.se) - (ll)(b.se - a.se) * (c.fi - b.fi);
}

int main () {
    scanf ("%d%d", &n, &m);
    scanf ("%d%d", &x, &y);
    for (int i = 0; i < n; i++) scanf ("%d%d", &v[i].fi, &v[i].se);
    int mx = 0, my = 0;
    for (int i = 0; i < m; i++) {
        scanf ("%d%d", &w[i].fi, &w[i].se);
        mx = max (mx, w[i].fi);
        my = max (my, w[i].se);
    }   
    w[m++] = mp (0, my);
    sort (v, v + n);
    sort (w, w + m);
    int o = 1;
    q[0] = w[0];
    for (int i = 0; i < m; i++) {
        while (o > 1 && vect (q[o - 2], q[o - 1], w[i]) >= 0) o--;
        q[o++] = w[i];
    }
    if (v[n - 1].fi >= q[o - 1].fi) {
        printf ("Max\n");
        re 0;
    }
    for (int i = 0, j = 0; i < n; i++) {
        while (j + 1 < o && q[j + 1].fi < v[i].fi) j++;
        if ((ll)v[i].se * (q[j + 1].fi - q[j].fi) >= (ll)(q[j + 1].se - q[j].se) * (v[i].fi - q[j].fi) + (ll)q[j].se * (q[j + 1].fi - q[j].fi)) {
            printf ("Max\n");
            re 0;
        }
    }
    printf ("Min\n");
    return 0;
}