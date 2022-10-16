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
ll l[201000], r[201000], t[201000];
vector<ll> query[401000];
struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree() {
        int sz = 400010;
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
            node[k] = max(node[2*k+1], node[2*k+2]);
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



int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> cmp;
    LazySegmentTree seg[2];
    for(int i = 0; i < N; i++) {
        cin >> l[i] >> r[i] >> t[i];
        t[i]--;
        cmp.push_back(l[i]);
        cmp.push_back(r[i]);
    }
    sort(cmp.begin(), cmp.end());
    cmp.erase(unique(cmp.begin(), cmp.end()), cmp.end());
    for(int i = 0; i < N; i++) {
        auto itr = lower_bound(cmp.begin(), cmp.end(), l[i]);
        l[i] = itr - cmp.begin();
        itr = lower_bound(cmp.begin(), cmp.end(), r[i]);
        r[i] = itr - cmp.begin();
        r[i]++;
        query[l[i]].push_back(i);
        //cerr << "{" << l[i] << ", " << r[i] << "} " << t[i] << endl;
    }
    ll ans = 0;
    for(int i = 0; i <= 2 * N; i++) {
        for(int j = 0; j < 2; j++) {
            ll val = seg[j].getmax(i, i + 1);
            //cerr << i << " " << j << " " << val << endl;
            chmax(ans, val);
            ll val2 = seg[1-j].getmax(i, i + 1);
            ll delta = val2 - val;
            chmax(delta, 0LL);
            seg[j].add(i, i + 1, delta);
        }
        for(auto idx : query[i]) {
            seg[t[idx]].add(r[idx], 2 * N + 1, 1);
            auto val = seg[t[idx]].getmax(0, r[idx]) + 1;
            ll val2 = seg[t[idx]].getmax(r[idx], r[idx] + 1);
            ll delta = val - val2;
            chmax(delta, 0LL);
            seg[t[idx]].add(r[idx], r[idx] + 1, delta);
        }
    }
    cout << ans << endl;
    return 0;
}