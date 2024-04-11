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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
typedef pair<ll, l_l> lll;
ll N, M, P;
vector<l_l> tmpa, tmpb;
vector<lll> c;
vector<l_l> a, b;
ll ans = -1e18;

struct LazySegmentTree {
private:
    int n;
    vector<ll> node, lazy;

public:
    LazySegmentTree(vector<ll> v) {
        int sz = (int)v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] = max(node[i*2+1], node[i*2+2]);
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

        if(b <= l || r <= a) return -INF;
        if(a <= l && r <= b) return node[k];
        ll vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }

};


void print(LazySegmentTree seg) {
    for(int i = 0; i < M; i++) {
        cerr << seg.getmax(i, i + 1) << " ";
    }
    cerr << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> P;
    tmpa.resize(N);
    tmpb.resize(M);
    c.resize(P);
    for(int i = 0; i < N; i++) cin >> tmpa[i].first >> tmpa[i].second;
    for(int i = 0; i < M; i++) cin >> tmpb[i].first >> tmpb[i].second;
    for(int i = 0; i < P; i++) {
        cin >> c[i].first >> c[i].second.first >> c[i].second.second;
    }
    sort(tmpa.begin(), tmpa.end());
    sort(tmpb.begin(), tmpb.end());
    sort(c.begin(), c.end());
    for(int i = 0; i < N; i++) {
        while(!a.empty() and a.back().second >= tmpa[i].second) a.pop_back();
        a.push_back(tmpa[i]);
    }
    for(int i = 0; i < M; i++) {
        while(!b.empty() and b.back().second >= tmpb[i].second) b.pop_back();
        b.push_back(tmpb[i]);
    }
    b.push_back({1e17, 1e17});
    N = a.size();
    M = b.size();
    /*
    for(auto tmp : a) {
        cerr << "{" << tmp.first << ", " << tmp.second << "}" << endl;
    }
    cerr << endl;
    for(auto tmp : b) {
        cerr << "{" << tmp.first << ", " << tmp.second << "}" << endl;
    }
    cerr << endl;
    */
    vector<ll> INIT;
    for(int i = 0; i < M; i++) {
        INIT.push_back(-b[i].second);
    }
    LazySegmentTree seg(INIT);
    //print(seg);
    int monster = 0;
    for(int i = 0; i < N; i++) {
        while(monster != P and c[monster].first < a[i].first) {
            l_l tmp = {c[monster].second.first, 1e18};
            auto itr = lower_bound(b.begin(), b.end(), tmp);
            int idx = distance(b.begin(), itr);
            seg.add(idx, M, c[monster].second.second);
            monster++;
        }
        //print(seg);
        ll now = seg.getmax(0, M);
        chmax(ans, now - a[i].second);
    }
    cout << ans << endl;
    return 0;
}