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
ll N;
vector<ll> xcomp, ycomp;
ll x[205000], y[205000];
struct SegmentTree {
private:
    int n;
    vector<ll> node;
 
public:
    SegmentTree() {
        int sz = 205000;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        for(int i=0; i<sz; i++) node[i+n-1] = 0;
        for(int i=n-2; i>=0; i--) node[i] = min(node[2*i+1], node[2*i+2]);
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
    ll getsum(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
 
        ll vl = getsum(a, b, 2*k+1, l, (l+r)/2);
        ll vr = getsum(a, b, 2*k+2, (l+r)/2, r);
        return (vl + vr);
    }
};

vector<ll> points[205000];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> x[i] >> y[i];
        xcomp.push_back(x[i]);
        ycomp.push_back(y[i]);
    }
    sort(xcomp.begin(), xcomp.end());
    sort(ycomp.begin(), ycomp.end());
    xcomp.erase(unique(xcomp.begin(), xcomp.end()), xcomp.end());
    ycomp.erase(unique(ycomp.begin(), ycomp.end()), ycomp.end());
    for(int i = 1; i <= N; i++) {
        auto itr = lower_bound(xcomp.begin(), xcomp.end(), x[i]);
        x[i] = distance(xcomp.begin(), itr);
        itr = lower_bound(ycomp.begin(), ycomp.end(), y[i]);
        y[i] = distance(ycomp.begin(), itr);
        points[y[i]].push_back(x[i]);
    }
    SegmentTree seg;
    ll ans = 0;
    for(int Y = 2e5; Y >= 0; Y--) {
        if(points[Y].empty()) continue;
        sort(points[Y].begin(), points[Y].end());
        points[Y].erase(unique(points[Y].begin(), points[Y].end()), points[Y].end());
        for(int i = 0; i < points[Y].size(); i++) {
            seg.update(points[Y][i], 1);
        }
        for(int i = 0; i < points[Y].size(); i++) {
            int minimum = 0;
            if(i > 0) {
                minimum = points[Y][i-1] + 1;
            }
            ll l = seg.getsum(minimum, points[Y][i]) + 1;
            ll r = seg.getsum(points[Y][i] + 1, 200005) + 1;
            //cerr << Y << " " << points[Y][i] << " " << l << " " << r << endl;
            ans += l * r;
        }
    }
    cout << ans << endl;
    return 0;
}