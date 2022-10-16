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

public:
    LazySegmentTree() {
        int sz = 200500;
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
            node[k] = max(node[2*k+1] ,node[2*k+2]);
        }
    }

    ll getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);

        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }

};


int who[200500];
int k[3];
int ans = 0;
int now = 0;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N = 0;
    for(int i = 0; i <= 2; i++) {
        cin >> k[i];
        N += k[i];
    }
    now = k[0];
    ans = k[0];
    for(int i = 0; i <= 2; i++) {
        while(k[i]--) {
            int a;
            cin >> a;
            who[a] = i;
        }
    }
    LazySegmentTree seg;
    for(int Delete = N; Delete >= 1; Delete--) {
        if(who[Delete] == 0) {
            now--;
        }
        if(who[Delete] == 1) {
            seg.add(Delete, N + 1, 1);
        }
        if(who[Delete] == 2) {
            seg.add(0, Delete, 1);
        }
        //cerr << Delete << " " << now << " " << seg.getmax(0, N + 1) << endl;
        chmax(ans, now + (int)seg.getmax(0, N + 1));
    }
    cout << N - ans << endl;
    return 0;
}