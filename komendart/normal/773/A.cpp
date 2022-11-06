#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))
#define pb push_back
#define mp make_pair
#define ins insert
#define f first
#define s second
#define fin(name) freopen(name, "r", stdin)
#define fout(name) freopen(name, "w", stdout)
#define files(name) fin(name".in"); fout(name".out")
#define endl "\n"
#define fi(st,n) for (int i = (st); i <= (int)(n); ++i)
#define fj(st,n) for (int j = (st); j <= (int)(n); ++j)
#define fk(st,n) for (int k = (st); k <= (int)(n); ++k)
#define fq(st,n) for (int q = (st); q <= (int)(n); ++q)
#define fw(st,n) for (int w = (st); w <= (int)(n); ++w)
#define ff(i, st, n) for (int (i) = (st); (i) <= (int)(n); ++(i))
#define ei(st,n) for (int i = (st); i >= (int)(n); --i)
#define ej(st,n) for (int j = (st); j >= (int)(n); --j)
#define ek(st,n) for (int k = (st); k >= (int)(n); --k)
#define ef(i, st, n) for (int (i) = (st); (i) >= (int)(n); --(i))
#define ri(st,n) for (int i = (st); i < (int)(n); ++i)
#define rj(st,n) for (int j = (st); j < (int)(n); ++j)
#define rk(st,n) for (int k = (st); k < (int)(n); ++k)
#define rq(st,n) for (int q = (st); q < (int)(n); ++q)
#define rf(i, st, n) for (int (i) = (st); (i) < (int)(n); ++(i))
#define clean(a) memset((a),0,sizeof (a))
#define sync ios_base::sync_with_stdio(0);cin.tie(0)
#define y1 dsklmlvmd
#define y0 dsklmlvmdsadasmc

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

const int inf = (int)1e9;
const ll linf = (ll)1e18;
const dbl eps = (dbl) 1e-8;
const int mod = (int) 1e9 + 7;
const int maxn = (int) 1e5 + 5;
//const dbl M_PI = (dbl)2 * (dbl)acos(0);

//cout<<fixed<<setprecision(10);
//srand(time(0));

ll x, y, p, q;
ll a, b, c;
ll x1, y1, x0, y0;
ll g, k;

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll solve(ll x, ll y, ll p, ll q) {
    if (p == q) {
        if (y == 0)
            return 1;
        else {
            if (x == y)
                return 0;
            else
                return -1;
        }
    }
    if (p == 0) {
        if (x == 0) {
            if (y == 0)
                return 1;
            else
                return 0;
        } else {
            return -1;
        }
    }
    k = max((x + p - 1) / p, max((y + q - 1) / q, (y - x + q - p - 1) / (q - p)));
    p *= k;
    q *= k;
    return q - y;


/*
    x0 = x;
    y0 = y;
    a = q - p;
    b = -p;
    c = -(x0 * q - p * y0);

//    cout << "a b c" << endl;
//    cout << a << " " << b << " " << c << endl;

    g = gcd(abs(a), abs(b), x, y);
    if (c % g != 0) {
        return -1;
    }

    x *= c / g;
    y *= c / g;
    if (a < 0)
        x = -x;
    if (b < 0)
        y = -y;

//    cout << x << " " << y << " " << g << endl;

    k = min(((y * g) / a), (x * g) / abs(b));

    ll cnt = 0;
    while ((x + k * (b / g) < 0 || y - k * (a / g) < 0) && cnt < 10000) {
        --k;
        ++cnt;
    }

    if (x + k * (b / g) < 0 || y - k * (a / g) < 0) {
        k += cnt;
        cnt = 0;
        while ((x + k * (b / g) < 0 || y - k * (a / g) < 0) && cnt < 10000) {
            ++k;
            ++cnt;
        }
    }

//    cout << k << endl;

    x1 = x + k * (b / g);
    y1 = y - k * (a / g);
    cout << x1 << " " << y1 << endl;
    if (x1 >= 0 && y1 >= 0) {
        return x1 + y1;
    } else {
        return -1;
    }
    */
}

ll sol_stupid(ll x, ll y, ll p, ll q) {
    ll ans = -1;
    fi(0, 300) {
        fj(0, 300) {
            if ((x + i) * (q) == (y + i + j) * (p)) {
                if (ans == -1 || ans > i + j) {
                    ans = i + j;
                }
            }
        }
    }
    return ans;
}

int main() {
//    fin("t.in");
    sync;
    int T;
    cin >> T;
    ff(numt, 1, T) {
        cin >> x >> y >> p >> q;
        cout << solve(x, y, p, q) << endl;
//        cout << x << " " << y << " " << p << " " << q << endl;
//        cout << solve(x, y, p, q) << " " << sol_stupid(x, y, p, q) << endl;
    }
    
    /*
    fi(0, 10) {
        fj(0, 10) {
            ff(k, 0, 10) {
                fw(0, 10) {
                    x = i;
                    y = i + j;
                    p = k;
                    q = w + k;
                    if (__gcd(p, q) == 1 && y > 0 && q > 0 && solve(x, y, p, q) != sol_stupid(x, y, p, q)) {
                        cout << x << " " << y << " " << p << " " << q << endl;
                        cout << solve(x, y, p, q) << " " << sol_stupid(x, y, p, q) << endl;
                        return 0; 
                    }
                }
            }
        }
    }
    */
    return 0;
}