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
const int two = 2;
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
const int M = (int)(3e5 + 239);
const int N = (int)(2e3 + 10);
const int L = 20;
const int T = (1 << 18) + 239;
const int B = 510;
const int X = 1e6 + 239;

void simulate(int n, int k, int moves) {
    vector<int> a(n, k);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int it = 0; it < moves; it++) {
        vector<int> wa = a;
        vector<int> b(n, 0);
        for (int i = 1; i < n; i++) {
            b[i - 1] += a[i] / 2;
            b[(i + 1) % n] += (a[i] + 1) / 2;
        }
        b[1] += a[0];
        a = b;
        for (int i = 0; i < n; i++) {
            cout << k - a[i] << "\t";
        }
        cout << "\n";
        if (a == wa) {
            cout << "stop " << it + 1 << "\n";
            break;
        }
    }
}

int n, k;

#ifdef ONPC
vector<int> a;
int need;

void move() {
    vector<int> b(n, 0);
    for (int i = 1; i < n; i++) {
        b[i - 1] += a[i] / 2;
        b[(i + 1) % n] += (a[i] + 1) / 2;
    }
    b[1] += a[0];
    a = b;
}
#endif

void watch(int n, int k, int moves) {
    simulate(n, k, moves);
}

int ask(int p) {
#ifdef ONPC
    int res = a[(p + n - need) % n];
    move();
    return res;
#endif
    cout << "? " << p + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

int dist(int a, int b) {
    if (a <= b) {
        return b - a;
    }
    return n - a + b;
}

int32_t main() {
#ifdef ONPC
    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
#ifdef ONPC
    cin >> need;
    need--;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        a[i] = k;
    }
#endif
    //watch(n, k, 1000);
    int jump = 0;
    while (jump * jump < n) {
        jump++;
    }
    if (n <= 100) {
        jump = n - 1;
    }
    for (int i = 0; i < jump + 10; i++) {
        ask(0);
    }
    int l = -1;
    int r = -1;
    for (int i = 0; i < jump + 10; i++) {
        int pos = (jump * i) % n;
        int f = ask(pos);
        if (f < k && l == -1) {
            l = pos;
        }
        if (f > k && r == -1) {
            r = pos;
        }
    }
    assert(l != -1);
    assert(r != -1);
    while (dist(l, r) > 1) {
        int d = (dist(l, r) / 2);
        int h = (d + l) % n;
        int cur = ask(h);
        if (cur == k) {
            cout << "! " << h + 1 << endl;
            return 0;
        }
        if (cur < k) {
            l = h;
        } else {
            r = h;
        }
    }
    return 0;
}