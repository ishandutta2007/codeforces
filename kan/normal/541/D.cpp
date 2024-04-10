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

const int N = 1000100;

ll n;
int m;
vector<ll> v;
int num1[N + 1];
int num2[N + 1];
ll res[2][100000];
int f[N + 1];
vector<pair<ll, ll> > w;

void add (ll x, int y) {
    if (x <= N) num1[x] = y; else num2[n / x] = y;
}

int get (ll x) {
    if (x <= N) re num1[x];
    re num2[n / x];
}

ll power (ll a, int b, ll MAX) {
//  cout << a << " " << b << " " << MAX << endl;
    ll c = 1;
    while (b) {
        if (b & 1) {
            if (c > MAX / a) re MAX;
            c *= a;
        }
        b /= 2;
        if (!b) break;
        if (a > MAX / a) re MAX;
        a *= a;
    }
    re c;
}

int isprime (ll m) {
//  cout << m << endl;
    if (m <= N) re 1 - f[m];
    for (int i = 2; (ll)i * i <= m; i++)
        if (m % i == 0)
            re 0;
    re 1;
}

ll getp (ll x) {
    for (int t = 39; t >= 1; t--) {
        ll l = 1, r = x + 1;
        while (r - l > 1) {
            ll s = (l + r) / 2;
            if (power (s, t, x + 1) > x) r = s; else l = s;
        }
//      cout << l << " " << t << endl;
        if (power (l, t, x + 1) == x && isprime (l)) re l;
    }
    re -1;
}

int main () {
    f[1] = 1;
    for (int i = 2; i <= N; i++)
        if (!f[i])
            if (i <= N / i)
                for (int j = i * i; j <= N; j += i)
                    f[j] = 1;
    cin >> n;
    for (int i = 1; (ll)i * i <= n; i++)
        if (n % i == 0) {
            v.pb (i);
            if (i != n / i) 
                v.pb (n / i);
        }
    sort (all (v));
    for (int i = 0; i < sz (v); i++) {
        add (v[i], i);
        if (v[i] > 2) {
            ll p = getp (v[i] - 1);
            if (p != -1) {
                w.pb (mp (p, v[i]));
            }   
        }
    }
    sort (all (w));
    memset (res, 0, sizeof (res));
    res[0][0] = 1;
    int ci = 0, ni = 1;
    for (int i = 0; i < sz (w); ) {
        for (int j = 0; j < sz (v); j++)
            res[ni][j] = res[ci][j];
        int j = i;
        while (j < sz (w) && w[j].fi == w[i].fi) {
            ll y = w[j].se;
            for (int k = 0; k < sz (v); k++)
                if (v[k] % y == 0) {
                    int na = k;
                    int nb = get (v[k] / y);
//                  printf ("%I64d -> %I64d | %d -> %d | %d %d\n", v[k], v[k] / y, nb, na, ci, ni);
//                  fflush (stdout);
                    res[ni][na] += res[ci][nb];
                }
            j++;
        }
//      for (int k = 0; k < sz (v); k++) printf ("%I64d = %I64d\n", v[k], res[ni][k]);
        i = j;
        swap (ci, ni);
    }
    cout << res[ci][sz (v) - 1] << endl;
    return 0;
}