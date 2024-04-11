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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree() {
        int sz = 200010;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = node[i*2+1] + node[i*2+2];
    }
    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k] += lazy[k];
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

    void add(int a, int b, ll x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += x;
            eval(k, l, r);
        }
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }

    ll getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);

        if(b <= l || r <= a) return 1e18;
        if(a <= l && r <= b) return node[k];
        ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }

};


ll N;
ll p[200000];
ll a[200000];
LazySegmentTree seg;

void print() {
    return;
    for(int i = 0; i <= N + 1; i++) {
        cerr << seg.getmin(i, i + 1) << " ";
    }
    cerr << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    ll ans = 1e18;
    for(int i = 0; i < N; i++) {
        seg.add(p[i] + 1, N + 1, a[i]);
    }
    print();
    for(int i = 0; i < N - 1; i++) {
        seg.add(p[i] + 1, N + 1, -a[i]);
        seg.add(0, p[i] + 1, a[i]);
        print();
        chmin(ans, seg.getmin(0, N + 1));
    }
    cout << ans << endl;
    return 0;
}