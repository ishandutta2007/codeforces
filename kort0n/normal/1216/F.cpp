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
string S;
struct SegmentTree {
private:
    int n;
    vector<ll> node;
 
public:
    SegmentTree() {
        int sz = 200500;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 1e17);
        for(int i=0; i<sz; i++) node[i+n-1] = 1e17;
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
    }
 
    void update(int x, ll val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = min(node[2*x+1], node[2*x+2]);
        }
    }
    // hannkaikukann 
    ll getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 1e17;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }
};


int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    cin >> S;
    S = "#" + S;
    SegmentTree dp;
    dp.update(0, 0);
    for(ll i = 1; i <= N; i++) {
        dp.update(i, dp.getmin(i-1, i) + i);
        if(i > K) {
            if(S[i-K] == '1') {
                ll pos = i - K - K - 1;
                chmax(pos, 0LL);
                ll val = dp.getmin(pos, i) + i - K;
                if(val < dp.getmin(i, i+1)) {
                    dp.update(i, val);
                }
            }
        }
    }
    for(ll i = 1; i <= N; i++) {
        if(S[i] == '1') {
            ll l = i - K - 1;
            chmax(l, 0LL);
            ll r = i + K;
            chmin(r, N);
            ll val = dp.getmin(l, r) + i;
            if(val < dp.getmin(r, r+1)) {
                dp.update(r, val);
            }
        }
    }
    cout << dp.getmin(N, N + 1) << endl;
    return 0;
}