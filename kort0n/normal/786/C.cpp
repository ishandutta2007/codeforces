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

const long long INF = 1e9;
//const ll mod = 1000000007;
ll N;
vector<ll> a;
ll ans[101000];
ll SQRT;

ll LastAppear[105000];

void f(int num) {
    for(int i = 1; i <= N; i++) {
        LastAppear[i] = -1;
    }
    ll L = 0;
    ll sz = 0;
    for(int i = 0; i < N; i++) {
        if(LastAppear[a[i]] >= L) continue;
        if(sz == num) {
            sz = 0;
            ans[num]++;
            L = i;
        }
        sz++;
        LastAppear[a[i]] = i;
    }
}

void print() {
    for(int i = 1; i <= N; i++) {
        if(i != 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

const int SZ = 1<<19;

struct LazySegmentTree {
    int n;
    vector<l_l> node;
    vector<ll> lazy;

public:
    LazySegmentTree() {
        int sz = SZ;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, {INF, 0});
        lazy.resize(2*n-1, 0);

        for(int i=0; i<sz; i++) node[i+n-1] = {INF, i};
        for(int i=n-2; i>=0; i--) node[i] = min(node[i*2+1], node[i*2+2]);
    }
    void eval(int k, int l, int r) {
        if(lazy[k] != 0) {
            node[k].first += lazy[k];
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
            node[k] = min(node[2*k+1], node[2*k+2]);
        }
    }

    l_l getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);

        if(b <= l || r <= a) return {2*INF, -1};
        if(a <= l && r <= b) return node[k];
        l_l vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        l_l vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return min(vl, vr);
    }

};


ll num;
ll idx[1000000];
ll Last[1000000];
LazySegmentTree seg;
void ADD(int i, int val) {
    auto tmp = seg.getmin(num, num + 1);
    seg.add(num, num+1, -tmp.first + val);
    idx[num] = i;
    num++;
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) ans[i]++;
    SQRT = min(3000LL, N);
    ll tmp = 0;
    for(ll i = SQRT; i <= N; i++) {
        tmp += (N + i - 1) / i;
    }
    cerr << tmp << endl;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 1; i < SQRT; i++) {
        f(i);
    }
    for(int i = SQRT; i <= N; i++) {
        ADD(i, i);
    }
    for(int i = 0; i < N; i++) {
        seg.add(Last[a[i]], SZ, -1);
        while(true) {
            ll MIN = seg.node[0].first + seg.lazy[0];
            if(MIN >= 0) break;
            auto tmp = seg.getmin(0, SZ);
            //cerr << i << " " << tmp.first << " " << tmp.second << endl;
            int now = idx[tmp.second];
            ans[now]++;
            seg.add(tmp.second, tmp.second+1, INF);
            if(N - i > now) {
                ADD(now, now - 1);
            }
            if(num >= SZ) assert(0);
        }
        Last[a[i]] = num;
    }
    print();
    return 0;
}