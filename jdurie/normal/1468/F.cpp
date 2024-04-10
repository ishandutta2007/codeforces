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
ld EPS = 1e-14, PI = acosl(-1);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    MULT {
        map<ld, ll> cnt;
        G(n)
        vector<ld> vals(n);
        F(i,0,n) {
            G(x) G(y) G(u) G(v)
            ld theta = fmodl(10 * PI + atan2l(u - x, v - y), 2*PI);
            if (cnt.lower_bound(theta - EPS) != cnt.end()) {
                auto val = (*cnt.lower_bound(theta - EPS)).K;
                if (abs(theta - val) <= EPS) theta = val;
            }
            cnt[theta]++;
            vals[i] = theta;
        }
        ll ans = 0;
        F(i,0,n) {
            ld theta = fmodl(11 * PI + vals[i], 2*PI);
            if (cnt.lower_bound(theta - EPS) != cnt.end()) {
                auto val = (*cnt.lower_bound(theta - EPS)).K;
                if (abs(theta - val) <= EPS) ans += cnt[val];
            }
        }
        cout << ans / 2 << endl;
    };
}