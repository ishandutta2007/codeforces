#include <bits/stdc++.h>

#ifdef HOME
#define db(x) cerr << #x << " = " << x << endl
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")" << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define dbv(a) cerr << #a << " = "; for (auto xxx: a) cerr << xxx  << " "; cerr << endl
#else
#define db(x) ;
#define db3(x, y, z) ;
#define db2(x, y) ;
#define dbv(a) ;
#endif

using namespace std;
typedef long long ll;
typedef double dbl;


const int INF = 1.01e9;

const int N = 1e4;

int t, c;
int nxt[N];
int pos[N];

void init() {
#ifdef HOME
    t = c = 1000;
    while (t + c > 1000) {
        t = rand() % 1000 + 1;
        c = rand() % 1000 + 1;
    }
    for (int i = 0; i < t + c; i++) nxt[i] = i + 1;
    nxt[t + c - 1] = t;

    for (int i = 0; i < 10; i++) pos[i] = 0;
#else

#endif
}

vector<int> go(vector<int> who) {
    vector<int> res(10);
#ifdef HOME
    for (int x : who) pos[x] = nxt[pos[x]];

    vector<vector<int>> q(t + c);
    for (int i = 0; i < 10; i++) q[pos[i]].push_back(i);
    int cc = 0;
    for (int i = 0; i < t + c; i++) {
        if (q[i].empty()) continue;
        for (int x : q[i]) {
            res[x] = cc;
        }
        cc++;
    }
#else
    cout << "next";
    for (int x : who) cout << " " << x;
    cout << endl;

    int k;
    cin >> k;
    vector<string> s(k);
    for (int i = 0; i < k; i++) cin >> s[i];
    for (int i = 0; i < k; i++) for (char c : s[i]) res[c - '0'] = i;
#endif
    return res;
}

void ans() {
#ifdef HOME
    for (int i = 0; i < 10; i++) assert(pos[i] == t);
#else
    cout << "done" << endl;
#endif
}

void solve() {
    init();

    while (1) {
        auto r = go({0, 1});
        r = go({1});
        if (r[0] == r[1]) {
            break;
        }
    }
    while (1) {
        vector<int> all(10);
        for (int i = 0; i < 10; i++) all[i] = i;
        auto r = go(all);

        bool ok = 1;
        for (int i = 1; i < 10; i++) ok &= r[i] == r[0];

        if (ok) break;
    }
    ans();
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

#ifdef HOME
    for (int it = 0;; it++) {
        db(it);
        srand(it);

        solve();
    }
#endif
    solve();

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}