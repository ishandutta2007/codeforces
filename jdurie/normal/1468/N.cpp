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
#define K first
#define V second
#define tr(x, v) for (auto x : v)
#define MULT G(T) while(T--)

ll MOD = 998244353; // 1000000007;
pair<ll, ll> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll inv(ll a, ll b){return 1<a ? b - inv(b%a,a)*b/a : 1;}

#define NN

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    MULT {
        vector<ll> c(3), a(5);
        F(i,0,3) cin >> c[i];
        F(i,0,5) cin >> a[i];
        D(a, c)
        F(i,0,3) c[i] -= a[i];
        bool good = true;
        ll rem1 = max(0ll, min(c[0], a[3]));
        c[0] -= rem1;
        a[3] -= rem1;
        c[2] -= a[3];
        ll rem2 = max(0ll, min(c[1], a[4]));
        c[1] -= rem2;
        a[4] -= rem2;
        c[2] -= a[4];
        D(a, c)
        F(i,0,3) good &= c[i] >= 0;
        cout << ((good) ? "YES\n" : "NO\n");
    };
}