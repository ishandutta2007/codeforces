#include "bits/stdc++.h"
using namespace std;
using ll = long long;

const ll INF = 1e18;

struct SegmentTree {
    ll n;
    vector<ll> node;
    SegmentTree(ll N) {
        ll sz = N;
        n = 1;
        while(n < sz) n *= 2;
        node.resize(2*n-1, -INF);
        for(int i = n - 2; i >= 0; i--) {
            node[i] = max(node[2*i+1], node[2*i+2]);
        }
    }
    void chmax(ll x, ll val) {
        x += n - 1;
        if(val < node[x]) return;
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }

    ll getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a or b <= l) return -INF;
        if(a <= l and r <= b) return node[k];
        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

using l_l = pair<ll, ll>;

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    SegmentTree seg(N);
    seg.chmax(0, 0);
    ll ans = 1;
    stack<l_l> sta;
    sta.push({a[0], 1});
    for(int i = 1; i < N; i++) {
        ll newval = seg.getmax(0, a[i] + 1) + 2;
        //cerr << i << " " << newval << endl;
        while(sta.size() >= 1) {
            if(sta.top().first <= a[i]) {
                auto tmp = sta.top();
                seg.chmax(tmp.first, tmp.second);
                newval = max(newval, tmp.second + 1);
                sta.pop();
            } else {
                break;
            }
        }
        sta.push({a[i], newval});
        ans = max(ans, newval);
        //cerr << i << " " << newval << endl;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}