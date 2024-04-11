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
    vector<int> node;
 
public:
    SegmentTree() {
        int sz = 200100;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = 0;
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

ll ans[201000];
ll N, Q;
ll d[201000], l[201000], r[201000], u[201000];
ll p[201000];
ll pinv[201000];

ll f(ll x) {
    return x * (x - 1) / 2;
}

void print(SegmentTree &seg) {
    for(int i = 0; i <= 10; i++) cerr << seg.getsum(i, i + 1) << " ";
    cerr << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    for(int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
        pinv[p[i]] = i;
    }
    for(int i = 0; i < Q; i++) {
        cin >> l[i] >> d[i] >> r[i] >> u[i];
        l[i]--;
        d[i]--;
        r[i]--;
        u[i]--;
        ans[i] = f(N);
        ans[i] -= f(l[i]);
        ans[i] -= f(d[i]);
        ans[i] -= f(N - r[i] - 1);
        ans[i] -= f(N - u[i] - 1);
    }
    {
        SegmentTree seg;
        vector<l_l> a, b;
        for(int i = 0; i < Q; i++) {
            a.push_back({l[i], i});
            b.push_back({r[i], i});
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int aidx = 0;
        int bidx = 0;
        for(int i = 0; i < N; i++) {
            while(aidx < Q and a[aidx].first == i) {
                ll tmp = a[aidx].second;
                ll num = seg.getsum(0, d[tmp]);
                //cerr << tmp << " " << num << endl;
                ans[tmp] += f(num);
                num = seg.getsum(u[tmp] + 1, N);
                //cerr << tmp << " " << num << endl;
                ans[tmp] += f(num);
                aidx++;
            }
            seg.update(p[i], 1);
            //print(seg);
            while(bidx < Q and b[bidx].first == i) {
                ll tmp = b[bidx].second;
                ll num = (d[tmp]) - seg.getsum(0, d[tmp]);
                //cerr << tmp << " " << num << endl;
                ans[tmp] += f(num);
                num = (N - 1 - u[tmp]) - seg.getsum(u[tmp] + 1, N);
                //cerr << tmp << " " << num << endl;
                ans[tmp] += f(num);
                bidx++;
            }
        }
    }
    /*
    {
        SegmentTree seg;
        vector<l_l> a, b;
        for(int i = 0; i < Q; i++) {
            a.push_back({d[i], i});
            b.push_back({u[i], i});
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int aidx = 0;
        int bidx = 0;
        for(int i = 0; i < N; i++) {
            while(aidx < Q and a[aidx].first == i) {
                ll tmp = a[aidx].second;
                ll num = seg.getsum(0, l[tmp]);
                cerr << tmp << " " << num << endl;
                ans[tmp] += f(num);
                num = seg.getsum(r[tmp] + 1, N);
                cerr << tmp << " " << num << endl;
                ans[tmp] += f(num);
                aidx++;
            }
            seg.update(pinv[i], 1);
            //print(seg);
            while(bidx < Q and b[bidx].first == i) {
                ll tmp = b[bidx].second;
                ll num = (l[tmp]) - seg.getsum(0, l[tmp]);
                cerr << tmp << " " << num << endl;
                ans[tmp] += f(num);
                num = (N - 1 - r[tmp]) - seg.getsum(r[tmp] + 1, N);
                cerr << tmp << " " << num << endl;
                ans[tmp] += f(num);
                bidx++;
            }
        }
    }
    */
    for(int i = 0; i < Q; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}