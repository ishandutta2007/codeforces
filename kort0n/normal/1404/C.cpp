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
    vector<ll> lazy;
    vector<l_l> node;

public:
    LazySegmentTree(ll N) {
        int sz = N;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = {0, i};
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }
    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k].first += lazy[k];
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

    l_l getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);

        if(b <= l || r <= a) return {INF, -1};
        if(a <= l && r <= b) return node[k];
        l_l vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        l_l vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }

};

ll N, Q;
const ll B = 3800;
//const ll B = 3;
ll a[301000];
ll x[301000], y[301000];
vector<ll> query[301000];
ll ans[301000];


void print(LazySegmentTree seg) {
    for(int i = 0; i < N; i++) {
        cout << seg.getmin(i, i + 1).first << " ";
    }
    cout << endl;
}

int main() {
    cin >> N >> Q;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < Q; i++) {
        cin >> x[i] >> y[i];
        y[i] = N - y[i] - 1;
        query[y[i]].push_back(i);
    }
    LazySegmentTree seg(N);
    for(ll i = 0; i < N; i++) {
        ll delta = i - a[i];
        if(delta >= 0) {
            ll ng = i + 1;
            ll ok = -1;
            while(ng - ok > 1) {
                ll mid = (ok + ng) / 2;
                if(seg.getmin(mid, mid + 1).first >= delta) ok = mid;
                else ng = mid;
            }
            seg.add(0, ok + 1, 1);
        }
        //print(seg);
        for(auto q : query[i]) {
            ll tmp = seg.getmin(x[q], x[q] + 1).first;
            ans[q] = tmp;
            //cout << q << " " << tmp << endl;
        }
    }
    for(int i = 0; i < Q; i++) cout << ans[i] << endl;
    return 0;
}