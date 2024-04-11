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
struct SegmentTree {
private:
    int n;
    vector<ll> node;
 
public:
    SegmentTree() {
        int sz = 200010;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = (node[2*i+1] + node[2*i+2]);
    }
 
    void update(int x, ll val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = (node[2*x+1] + node[2*x+2]);
        }
    }
    // hannkaikukann 
    ll getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return (vl + vr);
    }
};

ll N, a[205000];
ll inv[200500];
ll ans[200500];
ll INVERSION[200500];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        inv[a[i]] = i;
    }
    SegmentTree segindex, segval;
    for(ll val = 1; val <= N; val++) {
        segindex.update(inv[val], 1);
        segval.update(inv[val], inv[val]);
        int ok = N;
        int ng = 0;
        while(abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            ll num = segindex.getmin(1, mid + 1);
            if(num >= (val + 2) / 2) ok = mid;
            else ng = mid;
        }
        //cerr<< val << " " << ok << endl;
        ans[val] += segval.getmin(ok + 1, N + 1);
        ans[val] -= segindex.getmin(ok + 1, N + 1) * ok;
        //cerr << val << " " << ok << " " << ans[val] << endl;
        ans[val] -= segval.getmin(1, ok);
        ans[val] += segindex.getmin(1, ok) * ok;
        //cerr << val << " " << ok << " " << ans[val] << endl;
        ans[val] -= (val/2)*(val/2+1) / 2;
        ans[val] -= ((val-1)/2)*((val-1)/2+1)/2;
        //cerr << val << " " << ok << " " << ans[val] << endl;
    }
    SegmentTree Inversion;
    for(ll i = 1; i <= N; i++) {
        INVERSION[i] = Inversion.getmin(inv[i], N + 1);
        Inversion.update(inv[i], 1);
        INVERSION[i] += INVERSION[i-1];
    }
    for(int i = 1; i <= N; i++) {
        cout << ans[i] + INVERSION[i] << " ";
    }
    cout << endl;
    /*
    for(int i = 1; i <= N; i++) {
        ok[i] = 1;
        ng[i] = i + 1;
    }
    for(int _ = 1; _ <= 20; _++) {
        for(int i = 1; i <= N; i++) Query[i].clear();
        for(int i = 1 ;i <= N; i++) {
            mid[i] = (ok[i] + ng[i]) / 2;
            ll index = mid[i] + (i / 2) - 1;
            Query[index].push_back(index);
        }

    }
    */
    return 0;
}