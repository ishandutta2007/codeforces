#include <bits/stdc++.h>
//#define endl "\n"
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
struct SegmentTree {
private:
    int n;
    vector<l_l> node;
 
public:
    l_l f(l_l a, l_l b) {
        l_l ret;
        ret.first = a.first + b.first;
        if(a.second + b.first >= b.second) {
            ret.second = a.second + b.first;
        } else {
            ret.second = b.second;
        }
        return ret;
    }
    SegmentTree() {
        int sz = 400010;
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, {-1, 0});
        for(int i=0; i<sz; i++) node[i+n-1] = {-1, 0};
        for(int i=n-2; i>=0; i--) node[i] = f(node[2*i+1], node[2*i+2]);
    }
 
    void add(int x, int val) {
        x += (n - 1);
        node[x].first += val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = f(node[2*x+1], node[2*x+2]);
        }
    }
    // hannkaikukann 
    l_l fold(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        if(r <= a || b <= l) return {0, -INF};
        if(a <= l && r <= b) return node[k];
 
        auto vl = fold(a, b, 2*k+1, l, (l+r)/2);
        auto vr = fold(a, b, 2*k+2, (l+r)/2, r);
        return f(vl, vr);
    }
};


//const ll mod = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K, M;
    cin >> N >> K >> M;
    SegmentTree seg;
    set<l_l> st;
    multiset<ll> val;
    for(int q = 0; q < M; q++) {
        ll x, y;
        cin >> x >> y;
        ll d = y + abs(x - K);
        if(st.find({x, y}) != st.end()) {
            st.erase({x, y});
            auto itr = val.lower_bound(d);
            val.erase(itr);
            seg.add(d, -1);
        } else {
            st.insert({x, y});
            val.insert(d);
            seg.add(d, 1);
        }
        if(val.empty()) {
            cout << 0 << endl;
            continue;
        }
        auto itr = val.end();
        itr--;
        auto maxi = *itr;
        auto tmp = seg.fold(0, maxi + 1);
        //cerr << d << " " << maxi << " " << tmp.first << " " << tmp.second << endl;
        ll Y = max(tmp.first, tmp.second) + maxi - N;
        chmax(Y, 0LL);
        cout << Y << endl;
    }
    return 0;
}