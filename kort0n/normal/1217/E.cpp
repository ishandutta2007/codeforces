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

i_i mergepair(i_i a, i_i b) {
    if(a.first > b.first) swap(a, b);
    if(a.second < b.first) return a;
    else return {a.first, b.first};
}

struct SegmentTree {
private:
    int n;
    vector<i_i> node;
 
public:
    SegmentTree() {
        int sz = 200100;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, {INF, INF});
        for(int i=0; i<sz; i++) node[i+n-1] = {INF, INF};
        for(int i=n-2; i>=0; i--) node[i] = {INF, INF};
    }
 
    void update(int x, int val) {
        x += (n - 1);
        node[x] = {val, INF};
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = mergepair(node[2*x+1], node[2*x+2]);
        }
    }
    // hannkaikukann 
    i_i getmin(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return {INF, INF};
        if(a <= l && r <= b) return {node[k]};
 
        i_i vl = getmin(a, b, 2*k+1, l, (l+r)/2);
        i_i vr = getmin(a, b, 2*k+2, (l+r)/2, r);
        return mergepair(vl, vr);
    }
};

SegmentTree seg[9];
int g(int val) {
    int ret = 0;
    for(int _ = 0; _ <= 8; _++) {
        ret *= 2;
        if(val % 10 > 0) ret += 1;
        val /= 10;
    }
    return ret;
}
void f(int index, int val) {
    int bit = g(val);
    //cerr << "bit: " << val << " " << bit << endl;
    for(int i = 0; i <= 8; i++) {
        if((1 << i) & bit) {
            seg[i].update(index, val);
            //cerr << i << " " << val << endl;
        }
        else seg[i].update(index, INF);
    }
}


int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        f(i, a);
    }
    while(m--) {
        int ope;
        cin >> ope;
        if(ope == 1) {
            int i, x;
            cin >> i >> x;
            f(i, x);
            continue;
        } else if(ope == 2) {
            int ans = 2 * INF;
            int l, r;
            cin >> l >> r;
            for(int bit = 0; bit <= 8; bit++) {
                i_i now = seg[bit].getmin(l, r + 1);
                if(now.second == INF) continue;
                chmin(ans, now.first + now.second);
            }
            if(ans == 2 * INF) ans = -1;
            cout << ans << endl;
        }
    }
    return 0;
}