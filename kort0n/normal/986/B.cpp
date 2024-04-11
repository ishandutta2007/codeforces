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
struct SegmentTree {
private:
    int n;
    vector<ll> node;
 
public:
    SegmentTree() {
        int sz = 1000500;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
 
    void update(int x, int val) {
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


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    ll inversion = 0;
    SegmentTree seg;
    for(int i = 0; i < N; i++) {
        inversion += seg.getsum(a[i], N);
        seg.update(a[i], 1);
    }
    string ans;
    if(inversion % 2 == (3 * N) % 2) ans = "Petr";
    else ans = "Um_nik";
    cout << ans << endl;
    return 0;
}