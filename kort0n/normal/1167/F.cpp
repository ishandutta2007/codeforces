#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

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
        int sz = 500050;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
 
    void update(int x, ll val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = (node[2*x+1] + node[2*x+2]) % mod;
        }
    }
    // hannkaikukann 
    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return (vl + vr) % mod;
    }
};


int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    SegmentTree left, right;
    ll n;
    cin >> n;
    set<l_l> st;
    for(ll i = 1; i <= n; i++) {
        ll in;
        cin >> in;
        st.insert({in, i});
    }
    ll ans = 0;
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        l_l now = *itr;
        ans += now.first * (now.second * (n - now.second + 1) % mod);
        ans %= mod;
        //cerr << now.first << " " << ans << " ";;
        ans += (n - now.second + 1) * (left.getsum(1, now.second) * now.first % mod);
        ans += now.second * (right.getsum(now.second, n + 1) * now.first % mod);
        ans %= mod;
        //cerr << ans << endl;
        left.update(now.second, now.second);
        right.update(now.second, n - now.second + 1);
    }
    cout << ans << endl;
    return 0;
}