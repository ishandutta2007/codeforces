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
struct SegmentTree {
private:
    int n;
    vector<ll> node;
 
public:
    SegmentTree() {
        int sz = 200050;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = (node[2*i+1] + node[2*i+2]);
    }
 
    void update(int x, ll val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = (node[2*x+1] + node[2*x+2]);
        }
    }
    // hannkaikukann 
    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return (vl + vr);
    }
};

ll N;
ll s[205000];
ll p[205000];
set<int> unused;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    SegmentTree seg;
    for(int i = 1; i <= N; i++) cin >> s[i];
    for(int i = 1; i <= N; i++) {
        seg.update(i, i);
        unused.insert(i);
    }
    for(int i = N; i >= 1; i--) {
        int ok = 1;
        int ng = N + 1;
        while(ng - ok > 1) {
            int mid = (ok + ng) / 2;
            if(seg.getsum(0, mid) <= s[i]) ok = mid;
            else ng = mid;
        }
        auto itr = unused.lower_bound(ok);
        p[i] = *itr;
        seg.update(*itr, 0);
    }
    for(int i = 1; i <= N; i++) cout << p[i] << " ";
    cout << endl;
    return 0;
}