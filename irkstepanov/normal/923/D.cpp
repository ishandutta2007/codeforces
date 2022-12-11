#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <random>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __ll128 bigll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

class ST {
public:
    ST(const string& ss) : s(ss) {
        n = sz(s);
        t.resize(4 * n);
        build(1, 0, n - 1);
    }

    vector<int> get(int l, int r) {
        return inner(1, 0, n - 1, l, r);
    }
private:
    string s;
    int n;

    struct node {
        int cntb;
        int cnta;
        int lst;
        int len;
    };

    vector<node> t;

    void build(int v, int tl, int tr) {
        t[v].len = tr - tl + 1;
        if (tl == tr) {
            if (s[tl] == 'A') {
                t[v].cntb = 0;
                t[v].cnta = 1;
                t[v].lst = 1;
            } else {
                t[v].cntb = 1;
                t[v].cnta = 0;
                t[v].lst = 0;
            }
            return;
        }
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v].cntb = t[v * 2].cntb + t[v * 2 + 1].cntb;
        t[v].cnta = t[v * 2].cnta + t[v * 2 + 1].cnta;
        t[v].lst = t[v * 2 + 1].lst;
        if (t[v * 2 + 1].lst == t[v * 2 + 1].len) {
            t[v].lst += t[v * 2].lst;
        }
    }

    vector<int> inner(int v, int tl, int tr, int l, int r) {
        if (tl == l && tr == r) {
            return {t[v].cnta, t[v].cntb, t[v].lst};
        }
        int tm = (tl + tr) >> 1;
        if (r <= tm) {
            return inner(v * 2, tl, tm, l, r);
        }
        if (l > tm) {
            return inner(v * 2 + 1, tm + 1, tr, l, r);
        }
        vector<int> ans = inner(v * 2 + 1, tm + 1, tr, tm + 1, r);
        vector<int> vct = inner(v * 2, tl, tm, l, tm);
        ans[0] += vct[0], ans[1] += vct[1];
        if (ans[2] == r - (tm + 1) + 1) {
            ans[2] += vct[2];
        }
        return ans;
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s, t;
    cin >> s >> t;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] == 'C') {
            s[i] = 'B';
        }
    }
    for (int i = 0; i < sz(t); ++i) {
        if (t[i] == 'C') {
            t[i] = 'B';
        }
    }

    ST u(s);
    ST v(t);

    int q;
    cin >> q;

    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        --l1, --r1, --l2, --r2;
        vector<int> vct1 = u.get(l1, r1);
        vector<int> vct2 = v.get(l2, r2);
        vct1[0] -= vct1[2];
        vct2[0] -= vct2[2];
        if (vct1[1] % 2 != vct2[1] % 2 || vct1[1] > vct2[1]) {
            cout << '0';
            continue;
        }
        int x = vct1[2], y = vct2[2];
        if (x < y) {
            cout << '0';
            continue;
        }
        if (x >= y + 1 && vct1[1] + 2 <= vct2[1]) {
            cout << '1';
            continue;
        }
        if (vct1[1] == vct2[1]) {
            if (x % 3 == y % 3) {
                cout << '1';
            } else {
                cout << '0';
            }
            continue;
        }
        assert(x == y && vct1[1] != vct2[1]);
        if (vct1[1] == 0) {
            cout << '0';
            continue;
        }
        cout << '1';
    }
    cout << "\n";

}