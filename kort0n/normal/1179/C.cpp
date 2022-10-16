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
//const ll mod = 1000000007;
struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;
    int sz;

public:
    LazySegmentTree() {
        sz = 1e6 + 10;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }

    // k 
    void eval(int k, int l, int r) {

    // 
    // 
        if(lazy[k] != 0) {
            node[k] += lazy[k] / (r - l);

        // 
        //  1/2 
        // 
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k] / 2;
                lazy[2*k+2] += lazy[k] / 2;
            }

        // 
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;

    // k 
        eval(k, l, r);

    // 
        if(b <= l || r <= a) return;
    
    // 
        if(a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k, l, r);
        }

    // 
    // 
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = max(node[2*k+1] , node[2*k+2]);
        }
    }

    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;

    // 
        eval(k, l, r);

        if(b <= l || r <= a) return -INF;
        if(a <= l && r <= b) return node[k];
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
    ll find(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
        if(r == -1) r = n;
        eval(k, l, r);
        if(node[k] <= 0 || r <= a || b <= l) return -1;
        if(k >= n - 1) return k - (n - 1);
        int rv = find(a, b, 2 * k + 2, (l + r) / 2, r);
        if(rv != -1) return rv;
        return find(a, b, 2 * k + 1, l, (l + r) / 2);
    }
};



int n, m;
int a[300050], b[300050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    LazySegmentTree seg;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        seg.add(0, a[i] + 1, 1);
    }
    for(int i = 1; i <= m; i++) {
        cin >> b[i];
        seg.add(0, b[i] + 1, -1);
    }
    int q;
    cin >> q;
    while(q--) {
        int d, e, f;
        cin >> d >> e >> f;
        if(d == 1) {
            seg.add(0, a[e] + 1, -1);
            a[e] = f;
            seg.add(0, a[e] + 1, 1);
        } else {
            seg.add(0, b[e] + 1, 1);
            b[e] = f;
            seg.add(0, b[e] + 1, -1);
        }
        cout << seg.find(1, 1e6 + 1) << endl;
        /*
        if(seg.getsum(0, 1e6 + 1) <= 0) {
            cout << -1 << endl;
            continue;
        }
        ll ok = 0;
        ll ng = 1e6 + 1;
        while(ng - ok > 1) {
            ll mid = (ok + ng) /2 ;
            if(seg.getsum(mid, 1e6 + 1) > 0) ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
        */
    }
    return 0;
}