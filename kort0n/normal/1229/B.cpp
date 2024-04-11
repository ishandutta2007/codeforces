#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;
struct SegmentTree {
private:
    int n;
    vector<ll> node;
 
public:
    SegmentTree() {
        int sz = 100001;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = __gcd(node[2*i+1], node[2*i+2]);
    }
 
    void update(int x, ll val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = __gcd(node[2*x+1], node[2*x+2]);
        }
    }
    // hannkaikukann 
    ll getgcd(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getgcd(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getgcd(a, b, 2*k+2, (l+r)/2, r);
        return __gcd(vl, vr);
    }
    ll g(int a, int b, ll x) {
        return g(a, b, x, 0, 0, n);
    }
    ll g(ll a, ll b, ll x, ll k, ll l, ll r) {
        //cerr << index << " " << x << endl;
        //cerr << a << " " << b << " " << k << " " << l << " " << r << endl;
        if(r <= a || b <= l) return -1;
        if(x == 0 && node[k] == 0) return -1;
        if(x != 0 && node[k] % x == 0) return -1;
        if(k >= n - 1) return (k - (n - 1));
        int rv = g(a, b, x, 2*k+2, (l+r)/2, r);
        if(rv != -1) return rv;
        return g(a, b, x, 2*k+1, l, (l+r)/2);
    }
    /*
    ll find(int a, int b, ll x) {
        return find(a, b, x, 0, 0, n);
    }

    ll find(int a, int b, ll x, int k, int l, int r) {
        if()
    }
    */
};
ll N;
ll x[100050];
vector<ll> pathes[100050];
SegmentTree seg;

ll f(ll under, ll nowval) {
    if(under < 0) return 0;
    nowval = __gcd(nowval, seg.getgcd(under, under + 1));
    //cerr << "f:" << under << " " << nowval << endl;
    //for(int i = 0; i <= under; i++) cerr << seg.getgcd(i, i + 1) << " ";
    //cerr << endl;
    ll ok = seg.g(0, under + 1, nowval);
    //cerr << under << " " << nowval << " " << ok << endl;
    return nowval * (under - ok) + f(ok, nowval);
}

ll dfs(int now, int from, int depth) {
    //cerr << "dfs:" << now << " " << depth << endl;
    seg.update(depth, x[now]);
    ll nowval = f(depth, 0);
    for(int to : pathes[now]) {
        if(to == from) continue;
        nowval += dfs(to, now, depth + 1);
    }
    return nowval % mod;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> x[i];
    for(int i = 1; i <= N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        pathes[a].push_back(b);
        pathes[b].push_back(a);
    }
    cout << dfs(1, -1, 0) << endl;
    return 0;
}