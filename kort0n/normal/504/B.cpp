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
    vector<int> node;
 
public:
    SegmentTree() {
        int sz = 205000;
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
            node[x] =(node[2*x+1] + node[2*x+2]);
        }
    }
    // hannkaikukann 
    int getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        int vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        int vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return (vl +vr);
    }
};

ll num[2][205000];
ll ans[205000];
ll N;
ll p[2][205000];
ll q[205000];

void f(int index) {
    SegmentTree seg;
    for(int i = 0; i < N; i++) {
        num[index][i] = p[index][i] - seg.getsum(0, p[index][i]);
        seg.update(p[index][i], 1);
        //cerr << num[index][i] << " ";
    }
    //cerr << endl;
}

void add() {
    int up = 0;
    for(int i = N - 1; i >= 0; i--) {
        ans[i] = num[0][i] + num[1][i] + up;
        if(ans[i] >= N - i) {
            ans[i] -= N - i;
            up = 1;
        } else up = 0;
        //cerr << ans[i] << " ";
    }
    //cerr << endl;
}

void g() {
    set<int> unused;
    for(int i = 0; i < N; i++) unused.insert(i);
    SegmentTree seg;
    for(int i = 0; i < N; i++) {
        int ok = N;
        int ng = -1;
        while(ok - ng > 1) {
            int mid = (ok + ng) / 2;
            if(mid - seg.getsum(0, mid) >= ans[i]) ok = mid;
            else ng = mid;
        }
        //cerr << i << " " << ans[i] << " " << ok << endl;
        auto itr = unused.lower_bound(ok);
        seg.update(*itr, 1);
        q[i] = *itr;
        unused.erase(itr);
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i <= 1; i++) {
        for(int j = 0; j < N; j++) cin >> p[i][j];
    }
    f(0);
    f(1);
    add();
    g();
    for(int i = 0; i < N; i++) cout << q[i] << " ";
    cout << endl;
    return 0;
}