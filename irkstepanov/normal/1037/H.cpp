#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct node {
    int link;
    int len;
    map<char, int> to;
    int firstpos;
    node() : link(-1), len(0) {}
};

vector<node> t;
int last;

void add(char c) {
    int curr = sz(t);
    t.pb(node());
    t[curr].len = t[last].len + 1;
    t[curr].firstpos = t[curr].len - 1;
    int p = last;
    while (p != -1 && !t[p].to.count(c)) {
        t[p].to[c] = curr;
        p = t[p].link;
    }
    if (p == -1) {
        t[curr].link = 0;
        last = curr;
        return;
    }
    int q = t[p].to[c];
    if (t[p].len + 1 == t[q].len) {
        t[curr].link = q;
        last = curr;
        return;
    }
    int clone = sz(t);
    t.pb(node());
    t[clone].link = t[q].link;
    t[clone].to = t[q].to;
    t[clone].len = t[p].len + 1;
    t[clone].firstpos = t[q].firstpos;
    while (p != -1 && t[p].to[c] == q) {
        t[p].to[c] = clone;
        p = t[p].link;
    }
    t[curr].link = t[q].link = clone;
    last = curr;
}

vector<vector<int> > tree;

struct query {
    int id;
    int len;
    int l, r;
    int pref;
    char c;
};

vector<vector<query> > vct;
string s;
vector<pair<int, char> > ans;

void upd(pair<int, char>& p, int x, char y) {
    if (x > p.first) {
        p = {x, y};
    } else if (x == p.first && y < p.second) {
        p = {x, y};
    }
}

void dfs(int v, set<int>& setik) {
    if (v) {
        setik.insert(t[v].firstpos);
    }
    for (int to : tree[v]) {
        set<int> tmp;
        dfs(to, tmp);
        if (sz(tmp) > sz(setik)) {
            for (int x : setik) {
                tmp.insert(x);
            }
            setik.swap(tmp);
        } else {
            for (int x : tmp) {
                setik.insert(x);
            }
        }
    }
    for (query& q : vct[v]) {
        int l = q.l, r = q.r;
        set<int>::iterator it = setik.upper_bound(r);
        if (it == setik.begin()) {
            continue;
        }
        --it;
        if (*it < l) {
            continue;
        }
        upd(ans[q.id], q.pref, q.c);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    t.pb(node());
    last = 0;

    cin >> s;

    for (int i = 0; i < sz(s); ++i) {
        add(s[i]);
    }

    tree.resize(sz(t));
    for (int v = 1; v < sz(t); ++v) {
        int u = t[v].link;
        tree[u].pb(v);
    }

    int q;
    cin >> q;
    vct.resize(sz(t));
    ans.assign(q, {-1, -1});
    vector<string> str(q);

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        string x;
        cin >> x;
        str[i] = x;
        int v = 0;
        bool finish = true;
        for (int j = 0; j < sz(x); ++j) {
            if (l + j > r) {
                finish = false;
                break;
            }
            for (auto it : t[v].to) {
                if (it.first <= x[j]) {
                    continue;
                }
                int to = it.second;
                vct[to].pb({i, j + 1, l + j, r, j, it.first});
            }
            if (!t[v].to.count(x[j])) {
                finish = false;
                break;
            }
            v = t[v].to[x[j]];
        }
        if (finish) {
            for (auto it : t[v].to) {
                int to = it.second;
                vct[to].pb({i, sz(x) + 1, l + sz(x), r, sz(x), it.first});
            }
        }
    }

    set<int> setik;
    dfs(0, setik);

    for (int i = 0; i < q; ++i) {
        if (ans[i].first == -1) {
            cout << "-1\n";
        } else {
            cout << str[i].substr(0, ans[i].first) << ans[i].second << "\n";
        }
    }

}