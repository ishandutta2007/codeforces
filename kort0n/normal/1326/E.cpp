#include <bits/stdc++.h>
#define endl "\n"
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

const long long INF = 1e18;
//const ll mod = 1000000007;
struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree() {
        int sz = 300010;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
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
            node[k] = max(node[2*k+1], node[2*k+2]);
        }
    }

    ll getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);

        if(b <= l || r <= a) return -1e9;
        if(a <= l && r <= b) return node[k];
        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }

};



int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    cerr << N << endl;
    vector<ll> p(N), q(N), pinv(N), qinv(N);
    for(int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }
    for(int i = 0; i < N; i++) {
        cin >> q[i];
        q[i]--;
    }
    for(int i = 0; i < N; i++) {
        pinv[p[i]] = i;
        qinv[q[i]] = i;
    }
    LazySegmentTree seg;
    vector<int> ok(N);
    vector<int> ans(N, N);
    int ansidx = 0;
    for(int i = N - 1; i >= 0; i--) {
        //cerr << i << " " << pinv[i] << endl;
        seg.add(0, pinv[i] + 1, 1);
        while(seg.getmax(0, N) > 0) {
            seg.add(0, q[ansidx] + 1, -1);
            ansidx++;
        }
        ok[i] = ansidx;
        //cerr << i << " " << ok[i] << endl;
        if(ok[i] < N) chmin(ans[ok[i]], i);
    }
    /*
    for(int i = N - 2; i >= 0; i--) {
        chmax(ans[i], ans[i+1]);
    }
    */
    for(int i = 1; i < N; i++) {
        chmin(ans[i], ans[i-1]);
    }
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}