//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")
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
const ll INF = (ll)(2e18 + 239);
const int BIG = (int)(1e9 + 239);
const int MOD = 998244353;
const ll MOD2 = (ll)MOD * (ll)MOD;

//random
#ifdef ONPC
mt19937_64 rnd(239);
#else
mt19937_64 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

//constants
const int M = (int)(2e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 1e6 + 239;

int ask(int i) {
    cout << "? " << i + 1 << endl;
    int x;
    cin >> x;
    return x - 1;
}

int answer(int i) {
    cout << "! " << i + 1 << endl;
    exit(0);
}

int n;

int dist(int l, int r) {
    if (l <= r) {
        return r - l;
    }
    return n - (l - r);
}

int middle(int l, int r) {
    return (l + (dist(l, r) / 2)) % n;
}

int32_t main() {
#ifdef ONPC
    //freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n <= 3) {
        vector<int> p;
        for (int i = 0; i < n; i++) {
            p.emplace_back(ask(i));
        }
        for (int i = 0; i < n; i++) {
            if (i > 0 && p[i - 1] < p[i]) {
                continue;
            }
            if (i + 1 < n && p[i + 1] < p[i]) {
                continue;
            }
            answer(i);
        }
    }
    int x = 0;
    int y = 1;
    int z = 2;
    int fx = ask(x);
    int fy = ask(y);
    int fz = ask(z);
    if (fx < fy && fx < fz) {
        swap(fy, fz);
        swap(y, z);
    } else if (fy < fx && fy < fz) {
        swap(fx, fy);
        swap(x, y);
    } else {
        swap(fx, fz);
        swap(x, z);
    }
    while (dist(y, x) + dist(x, z) > 2) {
        if (dist(y, x) <= dist(x, z)) {
            int t = middle(x, z);
            int ft = ask(t);
            if (ft < fx) {
                y = x;
                fy = fx;
                x = t;
                fx = ft;
                continue;
            } else {
                z = t;
                fz = ft;
                continue;
            }
        } else {
            int t = middle(y, x);
            int ft = ask(t);
            if (ft < fx) {
                z = x;
                fz = fx;
                x = t;
                fx = ft;
                continue;
            } else {
                y = t;
                fy = ft;
                continue;
            }
        }
    }
    answer(x);
    return 0;
}