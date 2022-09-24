#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1.01e9;
const int N = 1 << 19;
const int MOD = (int)1e9 + 7;

template <typename T>
struct fenwick {
    int n;
    vector<T> f;
    int cn;
    fenwick() {}

    fenwick(int N) {
        n = N;
        f.assign(N, T(0));
        cn = 0;
    }

    fenwick(vector<T> a) {
        n = a.size();
        for (int i = 0; i < n; i++) add(i, a[i]);
    }

    void add(int x, T y) {
        for (; x < n; x |= x + 1) f[x] += y;
    }

    T get(int x) {
        T res(0);
        for (; x >= 0; x = (x & (x + 1)) - 1) res += f[x];
        return res;
    }

    T get(int l, int r) {
        return get(r) - get(l - 1);
    }

    T getSuf(int x) {
        return get(n - 1) - get(x - 1);
    }

    void print() {
        for (int i = 0; i < n; i++) cout << get(i) - get(i - 1) << " ";
        cout << endl;
    }

    void append() {
        ll val = get(cn - 1);
        val -= get((cn & (cn + 1)) - 1);

        cn++;
        f.push_back(val);
    }
};

int n;
int p[N];
vector<int> e[N];
int dep[N];
fenwick<ll> f;
ll ans[N];

void dfs1(int v) {
    dep[v] = 0;
   // dep[v] = 1;
    for (int to : e[v]) {
        dfs1(to);
        //dep[v] += dep[to];
        dep[v] = max(dep[v], dep[to] + 1);
    }
    sort(e[v].begin(), e[v].end(), [&](int v1, int v2) {
        return dep[v1] > dep[v2];
    });
}

void dfs3(int v, int h, int p) {
    f.add(h, p);
    for (int to : e[v]) {
        dfs3(to, h + 1, p);
    }
}

vector<pair<int, fenwick<ll>*>> st;
int last;

fenwick<ll>* dfs2(int v, int h) {
    ans[v] = 0;
    ans[v] += f.get(h);
    for (auto o : st) {
        int myH = h - o.first;
        assert(myH >= 0);
        int myPos = o.second->cn - 1 - myH;
        ans[v] += o.second->getSuf(myPos) * o.first;
        //o.second->print();
    }
    //ans[v] += h;

    for (int i = 1; i < (int)e[v].size(); i++) {
        dfs3(e[v][i], h + 1, +(h + 1));
    }
    fenwick<ll>* res;
    if (!e[v].empty()) {
        f.add(h, h + 1);
        auto ff = dfs2(e[v][0], h + 1);
        st.push_back({h + 1, ff});
        vector<fenwick<ll>*> vv;
        for (int i = 1; i < (int)e[v].size(); i++) {
            dfs3(e[v][i], h + 1, -(h + 1));
            int old = last;
            last = h;
            vv.push_back(dfs2(e[v][i], h + 1));
            last = old;
            dfs3(e[v][i], h + 1, +(h + 1));
        }
        f.add(h, -(h + 1));
        res = st.back().second;
        st.pop_back();

        //int mx = 0;
        //for (auto f2 : vv) mx = max(mx, f2->n);
        //while (res->n < mx) res->append();

        for (auto f2 : vv) {
            for (int i = 0; i < f2->cn; i++) {
                ll x = f2->get(i) - f2->get(i - 1);
                int ch = f2->cn - 1 - i;
                res->add(res->cn - 1 - ch, x);
            }
        }
    } else {
        res = new fenwick<ll>(h - last + 2);
    }
    for (int i = 1; i < (int)e[v].size(); i++) {
        dfs3(e[v][i], h + 1, -(h + 1));
    }
    res->append();
    res->add(res->cn - 1, 1);
    return res;
}

vector<ll> solve() {
    int root = -1;
    for (int i = 0; i < n; i++) {
        e[i].clear();
    }
    for (int i = 0; i < n; i++) {
        if (p[i] == -1) root = i;
        else e[p[i]].push_back(i);
    }
    dfs1(root);
    f = fenwick<ll>(n);
    last = 0;
    dfs2(root, 0);
    vector<ll> res(n);
    for (int i = 0; i < n; i++) res[i] = ans[i];
    return res;
}

void print(vector<ll> a) {
    for (int i = 0; i < (int)a.size(); i++) {
        printf("%lld%c", a[i], " \n"[i + 1 == (int)a.size()]);
    }
}

vector<ll> slow() {
    vector<vector<int> > cnt(n, vector<int>(n));
    for (int i = n - 1; i > 0; i--) {
        cnt[i][0]++;
        for (int j = 0; j < n - 1; j++) {
            cnt[p[i]][j + 1] += cnt[i][j];
        }
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; i++) {
        int pr = p[i];
        int cc = 1;
        ans[i] = 0;
        while (pr != -1) {
            for (int j = 1; j <= cc; j++) ans[i] += cnt[pr][j];
            pr = p[pr];
            cc++;
        }
    }
    return ans;
}

void stress() {
    for (int it = 3009; it < 1e5; it++ ){
        srand(it);
        cout << it << endl;

        //n = rand() % 5 + 1;
        n = 10;
        p[0] = -1;
        for (int i = 1; i < n; i++) {
            p[i] = rand() % i;
        }

        auto ans1 = solve();
        auto ans2 = slow();
        if (ans1 != ans2) {
            cout << "----------" << endl;
            print(ans1);
            cout << "instead of" << endl;
            print(ans2);
            cout << "----------" << endl;
            cout << n << endl;
            for (int i = 0; i < n; i++) cout << p[i] << " ";
            slow();
            exit(0);
        }
    }
    exit(0);
}

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    //stress();

    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
        }
        int root = -1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            p[i]--;
            if (p[i] == -1) root = i;
            else e[p[i]].push_back(i);
        }

        print(solve());
    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}