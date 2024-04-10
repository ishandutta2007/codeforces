#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>




using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const int INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;

struct DSU {
    int n;
    vector<int> p;
    vector<int> d;
    vector<int> val;
    DSU(int nn) {
        n = nn;
        p.resize(n);
        val.assign(n, 0);
        for (int i = 0; i < n; ++i) {
            p[i] = i;
        }
        d.assign(n, 1);
    }
    void add() {
        ++n;
        p.push_back(n - 1);
        d.push_back(1);
        val.push_back(0);
    }
    int root(int x) {
        if (p[x] == x)
            return x;
        int r = root(p[x]);
        val[x] = val[x] ^ val[p[x]];
        p[x] = r;
        return r;
    }
    bool eq(int x, int y) {
        return (root(x) == root(y));
    }
    void unite(int x, int y, int xr) {
        if (eq(x, y))
            return;
        int r1 = root(x);
        int r2 = root(y);
        xr = xr ^ val[x] ^ val[y];
        if (d[r1] < d[r2])
            swap(r1, r2);
        p[r2] = r1;
        val[r2] = xr;
        d[r1] += d[r2];
        return;
    }
    int getVal(int x) {
        root(x);
        return val[x];
    }
};

void solve() {
    int q;
    cin >> q;
    int lst = 0;
    int t, l, r, x;
    DSU d(0);
    map<int, int> mp;
    int sz = 0;
    for (int qq = 0; qq < q; ++qq) {
        cin >> t >> l >> r;
        l = l ^ lst;
        r = r ^ lst;
        if (l > r) {
                swap(l, r);
        }
        ++r;
        auto itl = mp.find(l); 
            
        if (itl == mp.end()) {
                mp[l] = sz;
                l = sz;
                ++sz;
                d.add();
        }
        else {
                l = itl->second;
        }
        auto itr = mp.find(r);
        if (itr == mp.end()) {
                mp[r] = sz;
                r = sz;
                ++sz;
                d.add();
            }
            else {
                r = itr->second;
        
        }


        if (t == 1) {
            cin >> x;
            x = x ^ lst;
            if (d.eq(l, r))
                continue;
            d.unite(l, r, x);
        }
        else {
            if (!d.eq(l, r)) {
                cout << -1 << "\n";
                lst = 1;
            }
            else {
                lst = (d.getVal(l) ^ d.getVal(r));
            cout << lst << "\n";
            }
        }

    }
    

}

//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();


#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}