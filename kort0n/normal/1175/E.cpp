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
struct LazySegmentTree {
private:
    int n;
    vector<int> node, lazy;
    vector<bool> lazyFlag;
 
public:
    LazySegmentTree() {
        int sz = (int)1000050;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1);
        lazy.resize(2*n-1, 0);
        lazyFlag.resize(2*n-1, false);
 
        for(int i=0; i<sz; i++) node[i+n-1] = i;
        for(int i=n-2; i>=0; i--) node[i] = max(node[i*2+1], node[i*2+2]);
    }
 
    void lazyEvaluate(int k, int l, int r) {
        if(lazyFlag[k]) {
            node[k] = max(node[k], lazy[k]);
            if(r - l > 1) {
                lazy[k*2+1] = max(lazy[k*2+1], lazy[k]);
                chmax(lazy[k*2+2], lazy[k]);
                lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
            }
            lazyFlag[k] = false;
        }
    }
 
    void update(int a, int b, int x, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] = max(lazy[k], x);
            lazyFlag[k] = true;
            lazyEvaluate(k, l, r);
        }
        else {
            update(a, b, x, 2*k+1, l, (l+r)/2);
            update(a, b, x, 2*k+2, (l+r)/2, r);
            node[k] = max(node[2*k+1], node[2*k+2]);
        }
    }
 
    int find(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        lazyEvaluate(k, l, r);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        int vl = find(a, b, 2*k+1, l, (l+r)/2);
        int vr = find(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

int dp[500050][30];
int f(int x, int y) {
    if(dp[x][29] < y) return -1;
    if(dp[x][0] >= y) return 1;
    int index = 0;
    while(dp[x][index+1] < y) index++;
    return (1 << index) + f(dp[x][index], y);
} 

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    LazySegmentTree seg;
    while(n--) {
        int l, r;
        cin >> l >> r;
        seg.update(l, r, r);
    }
    for(int i = 0; i <= 5e5; i++) {
        dp[i][0] = seg.find(i, i + 1);
        //cerr << i << " " << dp[i][0] << endl;
    }
    for(int time = 1; time < 30; time++) {
        for(int j = 0; j <= 5e5; j++) {
            dp[j][time] = dp[dp[j][time-1]][time-1];
            //cerr << time << " " << j << " " << dp[j][time] << endl;
        }
    }
    while(m--) {
        int x, y;
        cin >> x >> y;
        cout << f(x, y) << endl;
    }
    return 0;
}