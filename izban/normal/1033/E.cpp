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

#undef HOME

using namespace std;
typedef long long ll;
typedef double dbl;

const string YES = "YES";
const string NO = "NO";

const int MOD = 998244353;

int realN;
vector<pair<int, int>> ed;


void gen() {
    while (1) {
        realN = rand() % 20 + 1;
        ed.clear();
        int n = realN;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                ed.push_back({i, j});
            }
        }
        random_shuffle(ed.begin(), ed.end());
        ed.resize(rand() % (ed.size() + 1));

        bool ok = 1;
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        function<int(int)> get = [&](int x) {
            if (x == p[x]) return x;
            return p[x] = get(p[x]);
        };
        auto uni = [&](int u, int v) {
            p[get(v)] = get(u);
        };
        for (auto o : ed) {
            uni(o.first, o.second);
        }
        for (int i = 1; i < n; i++) ok &= p[i] == p[0];
        if (ok) break;
    }
}

int readN() {
#ifdef HOME
    gen();
    return realN;
#else
    int n;
    cin >> n;
    return n;
#endif
}

int ask(vector<int> p) {
    if (p.empty()) return 0;
#ifdef HOME
    vector<char> f(realN);
    for (auto x : p) f[x] = 1;
    int res = 0;
    for (auto o : ed) res += f[o.first] && f[o.second];
    return res;
#else
    cout << "? " << p.size() << endl;
    for (int i = 0; i < (int)p.size(); i++) {
        cout << p[i] + 1;
        if (i < (int)p.size() - 1) cout << " ";
    }
    cout << endl;
    int x;
    cin >> x;
    return x;
#endif
}

bool anyEdge(int v, vector<int> vct) {
    int t1 = ask(vct);
    vct.push_back(v);
    int t2 = ask(vct);
    return t1 != t2;
}

int findEdge(int v, vector<int> vct) {
    if (!anyEdge(v, vct)) return -1;
    while (vct.size() > 1) {
        vector<int> v1, v2;
        for (int i = 0; i < (int)vct.size(); i++) {
            if (i * 2 < (int)vct.size()) {
                v1.push_back(vct[i]);
            } else {
                v2.push_back(vct[i]);
            }
        }
        if (anyEdge(v, v1)) vct = v1;
        else vct = v2;
    }
    return vct[0];
}

void answer(bool ok, vector<int> vct) {
    if (ok) {
#ifdef HOME
        vector<int> f(realN);
        for (auto x : vct) f[x] = 1;
        for (auto o : ed) {
            assert(f[o.first] + f[o.second] == 1);
        }
#else
        cout << "Y" << " " << vct.size() << endl;
        for (int i = 0; i < (int)vct.size(); i++) {
            cout << vct[i] + 1;
            if (i + 1 < (int)vct.size()) cout << " ";
        }
        cout << endl;
#endif
    } else {
#ifdef HOME
        assert(vct.size() % 2 == 1);
        for (int i = 0; i < (int)vct.size(); i++) {
            auto o = make_pair(vct[i], vct[(i + 1) % vct.size()]);
            auto oo = o;
            swap(oo.first, oo.second);
            bool any = 0;
            for (auto t : ed) {
                any |= o == t || oo == t;
            }
            assert(any);
        }
#else
        cout << "N" << " " << vct.size() << endl;
        for (int i = 0; i < (int)vct.size(); i++) {
            cout << vct[i] + 1;
            if (i + 1 < (int)vct.size()) cout << " ";
        }
        cout << endl;
#endif
    }
}

void solve() {
    int n = readN();

    bool fail = 0;
    vector<int> cycle;

    vector<int> c(n, -1);
    vector<int> pr(n, -1);
    function<void(int, int)> dfs = [&](int v, int curC) {
        //db(v);
        c[v] = curC;
        vector<int> another;
        for (int i = 0; i < n; i++) {
            if (c[i] == (c[v]) && i != v) {
                another.push_back(i);
            }
        }
        int u = findEdge(v, another);
        if (u != -1) {
            fail = 1;
            vector<int> v1, v2;
            for (int x = v; x != -1; x = pr[x]) v1.push_back(x);
            for (int y = u; y != -1; y = pr[y]) v2.push_back(y);
            int last = -1;
            while (!v1.empty() && !v2.empty() && v1.back() == v2.back()) {
                last = v1.back();
                v1.pop_back();
                v2.pop_back();
            }

            cycle.clear();
            for (int i = 0; i < (int)v1.size(); i++) cycle.push_back(v1[i]);
            cycle.push_back(last);
            for (int i = (int)v2.size() - 1; i >= 0; i--) cycle.push_back(v2[i]);
            return;
        }

        while (1) {
            vector<int> oth;
            for (int i = 0; i < n; i++) if (c[i] == -1) oth.push_back(i);

            int to = findEdge(v, oth);
            //dbv(oth);
            //db(to);
            if (to == -1) break;
            pr[to] = v;
            dfs(to, curC ^ 1);
            if (fail) break;
        }
    };
    dfs(0, 0);

    if (fail) {
        answer(0, cycle);
    } else {
        for (int i = 0; i < n; i++) assert(c[i] != -1);
        vector<int> vct;
        for (int i = 0; i < n; i++) if (c[i] == 0) vct.push_back(i);
        answer(1, vct);
    }
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif

#ifdef HOME
    for (int it = 7;; it++) {
        srand(it);
        db(it);
        solve();
    }
#endif

    solve();

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}