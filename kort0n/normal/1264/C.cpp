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
const ll mod = 998244353;
ll N, Q;

ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret % mod;
    if(b & 1) {
        ret = ret * a % mod;
    }
    return ret;
}

ll inv(ll a) {
    return beki(a, mod - 2);
}

struct SegmentTree {
private:
    int n;
    vector<ll> node[2];
 
public:
    SegmentTree(vector<ll> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node[0].resize(2*n-1, 1);
        node[1].resize(2 * n - 1, 1);
        for(int i=0; i<sz; i++) {
            node[0][i+n-1] = v[i] * inv(100) % mod;
            node[1][i+n-1] = inv(node[0][i+n-1]);
            node[0][i+n-1] = node[1][i+n-1];
        }
        for(int i=n-2; i>=0; i--) {
            //node[i] = min(node[2*i+1], node[2*i+2]);
            node[0][i] = node[0][2*i+1] * node[0][2*i+2] % mod;
            node[1][i] = node[1][2*i+1] * node[0][2*i+2] + node[1][2*i+2];
            node[1][i] %= mod;
        }
    }

    /*
 
    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }
    */
    // hannkaikukann 
    l_l getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return {1, 0};
        if(a <= l && r <= b) return {node[0][k], node[1][k]};
 
        l_l vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        l_l vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        l_l ret;
        ret.first = vl.first * vr.first % mod;
        ret.second = vl.second * (vr.first) + vr.second;
        ret.second %= mod;
        return ret;
    }
};


int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    vector<ll> p(N);
    for(ll i = 0; i < N; i++) {
        cin >> p[i];
    }
    SegmentTree seg(p);
    /*
    for(int i = 1; i <= N; i++) {
        auto now = seg.getsum(i-1, i);
        cout << i << "  " << now.first << " " << now.second << endl;
    }
    cout << seg.getsum(0, 1).second << " " << seg.getsum(1, 5).second << endl;
    */
    ll ans = seg.getsum(0, N).second;
    set<ll> st;
    st.insert(0);
    st.insert(N);
    for(int q = 1; q <= Q; q++) {
        ll u;
        cin >> u;
        u--;
        if(st.count(u)) {
            auto itr = st.lower_bound(u + 1);
            ll r = *itr;
            itr--;
            itr--;
            ll l = *itr;
            ans -= seg.getsum(l, u).second;
            ans -= seg.getsum(u, r).second;
            ans += seg.getsum(l, r).second;
            st.erase(u);
        } else {
            auto itr = st.lower_bound(u);
            ll r = *itr;
            itr--;
            ll l = *itr;
            ans -= seg.getsum(l, r).second;
            ans += seg.getsum(l, u).second;
            ans += seg.getsum(u, r).second;
            st.insert(u);
        }
        ans += mod;
        ans += mod;
        ans %= mod;
        cout << ans << "\n";
    }
    return 0;
}