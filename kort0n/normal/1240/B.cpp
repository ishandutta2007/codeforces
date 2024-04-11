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
    SegmentTree(int SIZE) {
        int sz = SIZE;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
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
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        int vl = getmax(a, b, 2*k+1, l, (l+r)/2);
        int vr = getmax(a, b, 2*k+2, (l+r)/2, r);
        return max(vl, vr);
    }
};

void solve() {
    int N;
    cin >> N;
    vector<int> v(N + 10);
    vector<int> maxi(N + 10, -1);
    vector<int> mini(N + 10, 1e9);
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
        chmax(maxi[v[i]], i);
        chmin(mini[v[i]], i);
    }
    int total = 0;
    int now = 0;
    int before = 0;
    int nowmax = 0;
    for(int val = 1; val <= N; val++) {
        if(maxi[val] == -1) continue;
        if(before != -1 && maxi[before] < mini[val]) {
            now++;
        } else {
            now = 1;
        }
        chmax(nowmax, now);
        before = val;
        total++;
    }
    cout << total - nowmax << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    while(Q--) solve();
    return 0;
}