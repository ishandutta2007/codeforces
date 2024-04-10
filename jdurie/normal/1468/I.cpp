#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void __print(bool x) {cerr << (x ? "true" : "false");}void __print(int x) {cerr << x;} void __print(long x) {cerr << x;} void __print(long long x) {cerr << x;} void __print(unsigned x) {cerr << x;} void __print(unsigned long x) {cerr << x;} void __print(unsigned long long x) {cerr << x;} void __print(float x) {cerr << x;} void __print(double x) {cerr << x;} void __print(long double x) {cerr << x;} void __print(char x) {cerr << '\'' << x << '\'';} void __print(const char *x) {cerr << '"' << x << '"';} void __print(const string &x) {cerr << '"' << x << '"';} template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';} template<typename T> void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";} void _print() {cerr << "]\n";} template <typename T, typename... V> void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define D(x...) cerr << "[" << #x << "] = ["; _print(x);
#else
#define D(x...)
#endif

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
#define oset tree<ll, null_type, less<>, rb_tree_tag,tree_order_statistics_node_update>
#define F(i, start, end) for(ll i = (start); i < (end); ++i)
#define FD(i, start, end) for(ll i = (start-1); i >= (end); --i)
#define A(x) (x).begin(), (x).end()
#define G(x) ll x; cin >> x;
#define X first
#define Y second
#define tr(x, v) for (auto x : v)
#define MULT G(T) while(T--)

ll MOD = 998244353; // 1000000007;
pair<ll, ll> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll inv(ll a, ll b){return 1<a ? b - inv(b%a,a)*b/a : 1;}

#define NN
ld EPS = 1e-12;

ll gceil(ld x) {
    if (abs(x - roundl(x)) < EPS/10) return roundl(x);
    return ceill(x);
}
ll gfloor(ld x) {
    if (abs(x - roundl(x)) < EPS/10) return roundl(x);
    return floorl(x);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    G(n)
    pl v1, v2;
    cin >> v1.X >> v1.Y >> v2.X >> v2.Y;

#define PERP(v) { cout << "YES\n"; F(i,0,n) cout << v.X * i << " " << v.Y * i << '\n'; exit(0); }
#define FAIL { cout << "NO\n"; exit(0); };
    pl g{1,1};
    if ((v1.X == 0 and v1.Y == 0) or (v2.X == 0 and v2.Y == 0)) FAIL
    if (v1.X * v2.Y == v1.Y * v2.X) FAIL

    if (v1.X * v1.Y == 0 and v2.X * v2.Y == 0) {
        if (v1.X == 0) swap(v1, v2);
        vector<pl> ans;
        if (abs(v1.X) * abs(v2.Y) != n) FAIL
        F(x,0,abs(v1.X)) F(y,0,abs(v2.Y)) ans.emplace_back(x, y);
        cout << "YES\n";
        tr(v, ans) cout << v.X << " " << v.Y << '\n';
        exit(0);
    }

    if (v1.Y < 0) v1.X *= -1, v1.Y *= -1;
    if (v2.Y < 0) v2.X *= -1, v2.Y *= -1;
    bool xflip = false;
    if (v1.X < 0 and v2.X < 0) xflip = true, v1.X *= -1, v2.X *= -1;
    if (v1.X < 0) swap(v1, v2);
    if (v2.X < 0) {
        ld slop1 = ((ld)v1.Y) / (v1.X + EPS);
        ld slop2 = ((ld)v2.Y) / (v2.X + EPS);
        vector<pl> ans;
        F(x,v2.X + 1, v1.X) {
            ld up;
            if (x < v2.X + v1.X) up = v2.Y + min((ld)v1.Y, slop1 * (x - v2.X));
            else up = v1.Y + min((ld)v2.Y, slop2 * -(v1.X - x));
            ld bot;
            if (x < 0) bot = slop2 * x;
            else bot = slop1 * x;
            D(x, bot, up)
            F(y, gceil(bot - EPS * 2), gfloor(up - EPS * 2) + 1) {
                D(x, y, n)
                if ((x == v1.X and y == v1.Y) or (x == v2.X and y == v2.Y)) continue;
                if (!n) FAIL
                n--;
                ans.emplace_back(x, y);
            }
        }
        if (n) FAIL
        cout << "YES\n";
        tr(v, ans) cout << -(2 * xflip - 1) * v.X << " " << v.Y << '\n';
    } else {
        D(v1, v2)
        ld slop1 = ((ld)v1.Y) / (v1.X + EPS);
        ld slop2 = ((ld)v2.Y) / (v2.X + EPS);
        D(slop1, slop2)
        if (slop1 > slop2) swap(slop1, slop2), swap(v1, v2);
        vector<pl> ans;
        D(v1, v2)
        F(x,0, v1.X + v2.X) {
            ld up;
            if (x < v2.X) up = min((ld)v2.Y, slop2 * x);
            else up = v2.Y + min((ld)v1.Y, slop1 * (x - v2.X));
            ld bot;
            if (x <= v1.X) bot = min((ld)v1.Y, slop1 * x);
            else bot = v1.Y + min((ld)v2.Y, slop2 * (x - v1.X));
            D(x, bot, up)
            F(y, gceil(bot - EPS * 2), gfloor(up - EPS * 2) + 1) {
                D(x, y, n)
                if (!n) FAIL
                n--;
                ans.emplace_back(x, y);
            }
        }
        D(ans)
        if (n) FAIL
        cout << "YES\n";
        tr(v, ans) cout << -(2 * xflip - 1) * v.X << " " << v.Y << '\n';
    }
}