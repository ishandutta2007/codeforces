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

ll N, M, K;
ll a[300050];

struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree() {
        int sz = 300050;
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
            node[k] += lazy[k];

        // 
        //  1/2 
        // 
            if(r - l > 1) {
                lazy[2*k+1] += lazy[k];
                lazy[2*k+2] += lazy[k];
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
            lazy[k] += x;
            eval(k, l, r);
        }

    // 
    // 
        else {
            add(a, b, x, 2*k+1, l, (l+r)/2);
            add(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = max(node[2*k+1], node[2*k+2]);
        }
    }

    ll getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;

    // 
        eval(k, l, r);

        if(b <= l || r <= a) return -1e17;
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
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) cin >> a[i];
    ll ans = 0;
    for(int s = 1; s <= M; s++) {
        if(s > N) continue;
        LazySegmentTree seg;
        for(int i = 1; i <= s; i++) {
            seg.add(1, i + 1, a[i]);
        }
        seg.add(1, s + 1, -K);
        chmax(ans, seg.getmax(1, s + 1));
        for(int t = s + M; t <= N; t += M) {
            for(int i = t - M + 1; i <= t; i++) {
                seg.add(1, i + 1, a[i]);
            }
            seg.add(1, t + 1, -K);
            chmax(ans, seg.getmax(1, t + 1));
        }
    }
    cout << ans << endl;
    return 0;
}