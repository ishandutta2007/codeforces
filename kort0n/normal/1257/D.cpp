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
#define INF (2e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
struct SegmentTree {
private:
    int n;
    vector<int> node;
 
public:
    SegmentTree(int _n) {
        int sz = _n;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, -INF);
        for(int i=0; i<sz; i++) node[i+n-1] = -INF;
        for(int i=n-2; i>=0; i--) node[i] = max(node[2*i+1], node[2*i+2]);
    }
 
    void update(int x, int val) {
        x += (n - 1);
        node[x] = val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = max(node[2*x+1], node[2*x+2]);
        }
    }
    // hannkaikukann 
    int getmax(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return -INF;
        if(a <= l && r <= b) return node[k];
 
        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};


void solve() {
    int N, M;
    cin >> N;
    SegmentTree seg(N);
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        seg.update(i, a);
    }
    cin >> M;
    vector<l_l> w;
    for(int i = 0; i < M; i++) {
        int p, s;
        cin >> p >> s;
        w.push_back({s, p});
    }
    sort(w.begin(), w.end());
    reverse(w.begin(), w.end());
    vector<l_l> v;
    for(auto val : w) {
        if(v.empty() || v.back().second < val.second) {
            v.push_back(val);
            //cerr << val.first << " " << val.second << endl;
        }
    }
    //for(auto &val : v) swap(val.first, val.second);
    reverse(v.begin(), v.end());
    //for(auto val : v) cerr << val.first << " " << val.second << endl;
    int ans = 0;
    int pos = 0;
    while(true) {
        //cerr << ans << " " << pos << endl;
        if(pos == N) {
            cout << ans << "\n";
            return;
        }
        int ok = -1;
        int ng = v.size();
        while(ng - ok > 1) {
            int mid = (ok + ng) / 2;
            int End = min(pos + (int)v[mid].first, N);
            if(seg.getmax(pos, End) <= v[mid].second) ok = mid;
            else ng = mid;
        }
        int Next = pos;
        if(ok >= 0) {
            Next = min(pos + (int)v[ok].first, N);
        }
        if(ok != v.size() - 1) {
            int ok2 = pos;
            int ng2 = N;
            while(ng2 - ok2 > 1) {
                int mid = (ok2 + ng2) / 2;
                if(seg.getmax(pos, mid) <= v[ok+1].second) ok2 = mid;
                else ng2 = mid;
            }
            chmax(Next, ok2);
        }
        if(Next == pos) {
            cout << -1 << endl;
            return;
        }
        ans++;
        pos = Next;
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}