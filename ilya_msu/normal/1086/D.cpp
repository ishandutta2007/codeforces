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

class Fenvick {
    vector<int> a;
    ll get(int r) const {
        ll res = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            res += a[r];
        return res;
    }
public:
    void build(int n) {
        a.assign(n, 0);
    }
    ll get(int l, int r) const {
        if (l > r)
            return 0;
        return get(r) - get(l - 1);
    }
    void inc(int pos, int delta) {
        for (; pos < a.size(); pos = pos | (pos + 1)) {
            a[pos] += delta;
        }
    }
};


void solve(const vector<set<int> >& sets, const vector<Fenvick>& trees, int n) {
    int res = 0;
    for (int i = 0; i < 3; ++i) {
        int g = (i + 2) % 3;
        int b = (i + 1) % 3;
        if (sets[b].empty()) {
            res += sets[i].size();
            continue;
        }
        if (sets[g].empty()) {
            continue;
        }
        int l1 = (*sets[b].begin()), r1 = (*sets[b].rbegin());
        int l2 = (*sets[g].begin()), r2 = (*sets[g].rbegin());
        res += trees[i].get(max(r1, l2), n - 1);
        res += trees[i].get(0, min(r2, l1));
        res += trees[i].get(max(l1, l2), min(r1, r2));
    }
    cout << res << "\n";
}

void solve() {
    int n, q;
    cin >> n >> q;
    map<char, int> mp;
    mp['R'] = 0;
    mp['P'] = 1;
    mp['S'] = 2;
    string s;
    cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = mp[s[i]];
    }
    vector<set<int> > sets(3);
    for (int i = 0; i < n; ++i) {
        sets[a[i]].insert(i);
    }
    vector<Fenvick> trees(3);
    for (int i = 0; i < 3; ++i) {
        trees[i].build(n);
    }
    for (int i = 0; i < n; ++i) {
        trees[a[i]].inc(i, 1);
    }
    solve(sets, trees, n);
    for (int i = 0; i < q; ++i) {
        int pos;
        cin >> pos >> s;
        --pos;
        sets[a[pos]].erase(pos);
        trees[a[pos]].inc(pos, -1);
        a[pos] = mp[s[0]];
        sets[a[pos]].insert(pos);
        trees[a[pos]].inc(pos, 1);
        solve(sets, trees, n);
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