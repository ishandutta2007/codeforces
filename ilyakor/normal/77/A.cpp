#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

map<string, vector<string> > M;

int calc(vector<string>& v) {
    sort(all(v));
    int res = 0;
    for (int i = 0; i < sz(v); ++i)
        for (int j = 0; j < sz(M[v[i]]); ++j)
            if (binary_search(all(v), M[v[i]][j]))
                ++res;
    return res;
}

const int inf = 2 * 1000 * 1000 * 1000 + 100;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s1, s, s2;
        cin >> s1 >> s >> s2;
        M[s1].pb(s2);
    }
    int A, B, C;
    cin >> A >> B >> C;
    vector<string> v;
    v.pb("Anka");
    v.pb("Chapay");
    v.pb("Cleo");
    v.pb("Troll");
    v.pb("Dracul");
    v.pb("Snowy");
    v.pb("Hexadecimal");
    vi a(sz(v), 0);
    ii res = ii(inf, inf);
    while (1) {
        vector<string> va, vb, vc;
        for (int i = 0; i < sz(a); ++i) {
            if (a[i] == 0) va.pb(v[i]);
            if (a[i] == 1) vb.pb(v[i]);
            if (a[i] == 2) vc.pb(v[i]);
        }
        if (sz(va) && sz(vb) && sz(vc)) {
            vi t;
            int cva = calc(va);
            int cvb = calc(vb);
            int cvc = calc(vc);
            t.pb(A / sz(va));
            t.pb(B / sz(vb));
            t.pb(C / sz(vc));
            sort(all(t));
            int cur = t[sz(t) - 1] - t[0];
            res = min(res, ii(cur, -(cva + cvb + cvc)));
        }
        int cur = sz(a) - 1;
        while (cur >= 0 && a[cur] == 2)
            a[cur] = 0, --cur;
        if (cur < 0) break;
        ++a[cur];
    }
    cout << res.first << " " << (-res.second) << "\n";
    return 0;
}