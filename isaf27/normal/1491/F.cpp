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
const int MOD = 1e9 + 7;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(5e3 + 10);
const int L = 21;
const int T = (1 << 20) + 239;
const int B = 510;
const int X = 110;

#ifdef ONPC
string types;
int cnt;
int up;
#endif

int n;

int check(vector<int> a, vector<int> b) {
    if (a.empty() || b.empty()) {
        return 0;
    }
#ifdef ONPC
    cnt++;
    if (cnt > up) {
        cout << "too many queries!!!\n";
        exit(0);
    }
    int n1 = 0;
    int s1 = 0;
    for (int i : a) {
        if (types[i] == 'N') {
            n1++;
        } else if (types[i] == 'S') {
            s1++;
        }
    }
    int n2 = 0;
    int s2 = 0;
    for (int i : b) {
        if (types[i] == 'N') {
            n2++;
        } else if (types[i] == 'S') {
            s2++;
        }
    }
    int f = n1 * n2 + s1 * s2 - n1 * s2 - n2 * s1;
    if (abs(f) > n) {
        cout << "machine is broken!!!\n";
        exit(0);
    }
    return f;
#else
    cout << "? " << a.size() << " " << b.size() << endl;
    for (int i : a) {
        cout << i + 1 << " ";
    }
    cout << endl;
    for (int i : b) {
        cout << i + 1 << " ";
    }
    cout << endl;
    int f;
    cin >> f;
    return f;
#endif
}

void answer(vector<int> a) {
    sort(a.begin(), a.end());
#ifdef ONPC
    vector<int> need;
    for (int i = 0; i < n; i++) {
        if (types[i] == '-') {
            need.emplace_back(i);
        }
    }
    cout << "! " << a.size() << " ";
    for (int i : a) {
        cout << i + 1 << " ";
    }
    cout << endl;
    if (need != a) {
        cout << "WA!!!\n";
        exit(0);
    }
#else
    cout << "! " << a.size() << " ";
    for (int i : a) {
        cout << i + 1 << " ";
    }
    cout << endl;
#endif
}

void solve() {
    cin >> n;
#ifdef ONPC
    cin >> types;
    cnt = 0;
    up = 0;
    while ((1 << (up + 1)) <= n) {
        up++;
    }
    up += n;
#endif
    for (int i = 1; i < n; i++) {
        vector<int> a;
        for (int j = 0; j < i; j++) {
            a.emplace_back(j);
        }
        if (check(a, {i}) != 0) {
            int l = 0;
            int r = i;
            while (r - l > 1) {
                int h = (l + r) / 2;
                vector<int> a;
                for (int j = 0; j < h; j++) {
                    a.emplace_back(j);
                }
                if (check(a, {i}) != 0) {
                    r = h;
                } else {
                    l = h;
                }
            }
            vector<int> ans;
            for (int j = 0; j < i; j++) {
                if (j != l) {
                    ans.emplace_back(j);
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (check({i}, {j}) == 0) {
                    ans.emplace_back(j);
                }
            }
            answer(ans);
            break;
        }
    }
}

int32_t main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}