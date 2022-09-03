/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/

#include <bits/stdc++.h>

using namespace std;

//defines
typedef long long ll;
typedef long double ld;
#define TIME clock() * 1.0 / CLOCKS_PER_SEC
#define y0 _y0
#define kill _kill

//permanent constants
const ld pi = acos(-1.0);
const int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int digarr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int alf = 26;
const ld eps = 1e-10;
const ll INF = (ll)(4e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353; //1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(1e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 21;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 2010;

string s;
bool bad;

vector<int> func(int l, int r, int& pos) {
    if (r - l == 1) {
        return {l};
    }
    int mid = (l + r) / 2;
    vector<int> vl = func(l, mid, pos);
    vector<int> vr = func(mid, r, pos);
    vector<int> res;
    int i = 0;
    int j = 0;
    while (i < (int)vl.size() && j < (int)vr.size()) {
        bool val = false;
        if (pos == (int)s.size()) {
            cerr << l << " " << r << "\n";
            bad = true;
        } else {
            if (s[pos] == '1') {
                val = true;
            }
            pos++;
        }
        if (!val) {
            res.emplace_back(vl[i]);
            i++;
        } else {
            res.emplace_back(vr[j]);
            j++;
        }
    }
    while (i < (int)vl.size()) {
        res.emplace_back(vl[i]);
        i++;
    }
    while (j < (int)vr.size()) {
        res.emplace_back(vr[j]);
        j++;
    }
    return res;
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> s;
    for (int n = 2; ; ++n) {
        int pos = 0;
        bad = false;
        vector<int> ans = func(0, n, pos);
        if (!bad && pos == (int)s.size()) {
            vector<int> p(n);
            for (int i = 0; i < n; i++) {
                p[ans[i]] = i;
            }
            cout << n << "\n";
            for (int i : p) {
                cout << i + 1 << " ";
            }
            cout << "\n";
            return 0;
        }
    }
    return 0;
}