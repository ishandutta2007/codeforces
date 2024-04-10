#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
#define ii pair<int, int>
#define PI 3.141592653589793238462643383279502884
#define ll long long
#define for1(i, ff, gg) for(int i = ff; i <= gg; ++i)
#define for2(i, ff, gg) for(int i = ff; i >= gg; --i)
const ll mod = 1e9 + 7;
const int maxN = 300005;
const ll oo = 1e18 + 7;
int n, a[maxN], b[maxN];
int x, y, z, k;

vector<int> vc[maxN];

// Short code and faster
// Keeps upper hull for maximums.
// add lines with -m and -b and return -ans to
// make this code working for minimums.
// source: http://codeforces.com/blog/entry/11155?#comment-162462

bool Q;
const ll is_query = -(1LL<<62);
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const {
        return Q ? p < o.p : k < o.k;
    }
};
struct LineContainer : multiset<Line> {
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b){
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
        return l.k * x + l.m;
    }
} mp[maxN];
int dp[maxN];

void dfs(int node, int par){
    for(int child : vc[node]){
        if(child == par) continue;
        dfs(child, node);
        if(mp[node].size() < mp[child].size()) swap(mp[node], mp[child]);
        for(Line game : mp[child]){
            mp[node].add(game.k, game.m);
        }
    }
    if(vc[node].size() == 1 && node != 1) dp[node] = 0;
    else{
        int dumb = mp[node].query(a[node]);
        dp[node] = 0 - dumb;
    }
    mp[node].add(0 - b[node], 0 - dp[node]);
    // if(node == 3) cout << 0 - b[node] << " " << 0 - dp[node] << endl;
    return;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // mp[1].insert_line(-5, 0);
    // cout << mp[1].eval(10) << endl;
    // return 0;
    cin >> n;
    for1(i, 1, n) cin >> a[i];
    for1(i, 1, n) cin >> b[i];
    for1(i, 2, n){
        cin >> x >> y;
        vc[x].pb(y);
        vc[y].pb(x);
    }
    dfs(1, 0);
    for1(i, 1, n){
        cout << dp[i] << " ";
    }
    cout << endl;
}