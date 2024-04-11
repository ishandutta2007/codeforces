#include <bits/stdc++.h>
//#include <atcoder/all>
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

const int INF = 1e9;
//const ll mod = 1000000007;
struct SegmentTree {
private:
    int n;
    vector<int> node;
 
public:
    SegmentTree(vector<int> v) {
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, INF);
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
 
    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }
    // hannkaikukann 
    int getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return INF;
        if(a <= l && r <= b) return node[k];
 
        int vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};


vector<int> a;
ll N;
bool IsP(vector<int> b) {
    sort(b.begin(), b.end());
    for(int i = 0; i < b.size(); i++) {
        if(b[i] != i + 1) return false;
    }
    return true;
}
bool f(ll x) {
    SegmentTree seg(a);
    vector<int> b;
    for(int i = 0; i + x <= N; i++) {
        b.push_back(seg.getmin(i, i + x));
    }
    return IsP(b);
}

void solve() {
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    string ans;
    if(f(1)) ans.push_back('1');
    else ans.push_back('0');
    ll ok = N + 1;
    ll ng = 1;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(f(mid)) ok = mid;
        else ng = mid;
    }
    for(int i = 2; i <= ng; i++) ans.push_back('0');
    while(ans.size() < N) ans.push_back('1');
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}