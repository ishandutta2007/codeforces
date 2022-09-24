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


void print(vector<int> a) {
    for (int x : a) printf("%d\n", x);
}

struct segtree {
    struct item {
        int mx, mn;
        int maxLeft;
        int maxRight;
        int diam;

        item() {}
        item(int val) {
            mx = val;
            mn = val;
            maxLeft = -val;
            maxRight = -val;
            diam = 0;
        }
    };

    vector<int> a;
    int n;
    vector<item> t;
    vector<int> p;

    segtree(vector<int> _a) {
        a = _a;
        n = a.size();
        t.resize(4 * n);
        p.resize(4 * n);
        build(1, 0, n - 1);
    }

    item combine(item a, item b) {
        item c;
        c.mx = max(a.mx, b.mx);
        c.mn = min(a.mn, b.mn);
        c.maxLeft = max(a.maxLeft, max(a.mx - 2 * b.mn, b.maxLeft));
        c.maxRight = max(a.maxRight, max(-2 * a.mn + b.mx, b.maxRight));
        c.diam = max(a.diam, max(b.diam, max(a.maxLeft + b.mx, a.mx + b.maxRight)));
        return c;
    }

    void push(int v, int tl, int tr) {
        if (p[v] == 0) return;
        if (tl != tr) {
            p[v * 2] += p[v];
            p[v * 2 + 1] += p[v];
        }
        t[v].mx += p[v];
        t[v].mn += p[v];
        t[v].maxLeft -= p[v];
        t[v].maxRight -= p[v];
        p[v] = 0;
    }

    void build(int v, int tl, int tr) {
        p[v] = 0;
        if (tl == tr) {
            t[v] = item(a[tl]);
            return;
        }
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }

    void add(int v, int tl, int tr, int l, int r, int x) {
        push(v, tl, tr);
        if (l > r) return;
        if (l == tl && r == tr) {
            p[v] += x;
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) >> 1;
        add(v * 2, tl, tm, l, min(r, tm), x);
        add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
        t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }

    void add(int l, int r, int x) {
        assert(0 <= l && l <= r && r < n);
        add(1, 0, n - 1, l, r, x);
    }

    int ans() {
        return t[1].diam;
    }
};

vector<int> fast(string s, vector<pair<int, int>> q) {
    vector<int> a;
    int cur = 0;
    a.push_back(0);
    for (char c : s) {
        if (c == '(') cur++;
        else cur--;
        a.push_back(cur);
    }
    segtree tr(a);

    vector<int> ans;
    ans.push_back(tr.ans());
    for (auto cur : q) {
        if (cur.first > cur.second) swap(cur.first, cur.second);

        int delta = s[cur.first - 1] == ')';
        delta = 2 * delta - 1;
        delta = 2 * delta;

        s[cur.first - 1] ^= '(' ^ ')';
        s[cur.second - 1] ^= '(' ^ ')';

        tr.add(cur.first, cur.second - 1, delta);
        ans.push_back(tr.ans());
    }
    return ans;
}

vector<int> slow(string s, vector<pair<int, int>> a) {
    auto calc = [&]() {
        vector<int> b;
        b.push_back(0);
        int bal = 0;
        for (char c : s) {
            if (c == '(') bal++;
            else bal--;
            b.push_back(bal);
        }

        int ans = 0;
        for (int i = 0; i < (int)b.size(); i++) {
            int mn = b[i];
            for (int j = i; j < (int)b.size(); j++) {
                mn = min(mn, b[j]);
                ans = max(ans, b[i] + b[j] - 2 * mn);
            }
        }
        return ans;
    };
    vector<int> ans;
    ans.push_back(calc());
    for (auto o : a) {
        swap(s[o.first - 1], s[o.second - 1]);
        ans.push_back(calc());
    }
    return ans;
}

void stress() {
    auto good = [&](string s) {
        int cur =0 ;
        for (char c : s) {
            if (c == '(') cur++;
            else cur--;
            if (cur < 0) return false;
        }
        return cur == 0;
    };
    for (int it = 72;; it++) {
        srand(it);
        cerr << it << endl;

        int n = rand() % 10 + 3;
        string s = "";
        for (int i = 0; i < n - 1; i++) s += "(";
        for (int i = 0; i < n - 1; i++) s += ")";

        while (1) {
            random_shuffle(s.begin(), s.end());
            if (good(s)) break;
        }
        auto ss = s;

        int q = rand() % 10 + 1;
        vector<pair<int, int>> a;
        while ((int)a.size() < q) {
            int i = rand() % s.length();
            int j = rand() % s.length();
            if (i == j || s[i] == s[j]) continue;
            swap(s[i], s[j]);
            if (good(s)) {
                a.push_back({i + 1, j + 1});
                break;
            } else {
                swap(s[i], s[j]);
            }
        }

        auto ans1 = fast(ss, a);
        auto ans2 = slow(ss, a);
        if (ans1 != ans2) {
            print(ans1);
            cout << "instead of" << endl;
            print(ans2);
            cout << ss << endl;
            for (auto o : a) cout << o.first << " " << o.second << endl;
            exit(0);
        }
    }
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif
//    stress();

    int n, q;
    bool first = 1;
    while (scanf("%d%d", &n, &q) == 2) {
        if (first) first = 0;
        else cout << endl;

        static char buf[(int) 1.01e6];
        scanf("%s", buf);
        string s = buf;

        vector<pair<int, int>> a(q);
        for (int i = 0; i < q; i++) {
            scanf("%d%d", &a[i].first, &a[i].second);
        }

        print(fast(s, a));
    }

#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
}