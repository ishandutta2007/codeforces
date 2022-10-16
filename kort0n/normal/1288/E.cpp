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
ll N, M;
ll a[600500];
ll before[300500];
int pos[300500];
int ans[300500];
struct SegmentTree {
private:
    int n;
    vector<int> node;
 
public:
    SegmentTree() {
        int sz = 600000;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
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
    int getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return (vl + vr);
    }
};


int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        before[i] = i + 1;
    }
    for(int i = 1; i <= N; i++) {
        a[i] = N - i;
    }
    for(int i = N + 1; i <= N + M; i++) {
        cin >> a[i];
        a[i]--;
        before[a[i]] = 1;
    }
    SegmentTree seg;
    for(int i = 1; i <= N + M; i++) {
        int val = seg.getsum(pos[a[i]] + 1, i);
        //cerr << i << " " << a[i] << " " << val << endl;
        if(pos[a[i]] != 0) chmax(ans[a[i]], val + 1);
        seg.update(pos[a[i]], 0);
        seg.update(i, 1);
        pos[a[i]] = i;
    }
    for(int i = 0; i < N; i++) {
        int val = seg.getsum(pos[i] + 1, N + M + 1);
        chmax(ans[i], val + 1);
    }
    for(int i = 0; i < N; i++) {
        cout << before[i] << " " << ans[i] << endl;
    }
    return 0;
}