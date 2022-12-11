#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct SuffixAutomaton {

    SuffixAutomaton(const string& s) {
        t.pb(node());
        last = 0;
        for (int i = 0; i < sz(s); ++i) {
            add(s[i]);
        }

        for (int v = 0; v < sz(t); ++v) {
            order.pb(v);
        }
     
        sort(all(order), [&] (int u, int v) { return t[u].len < t[v].len; });
        reverse(all(order));
     
        int tmp = order[0];
        ++t[tmp].num;
        ++t[tmp].sum;
        while (true) {
            tmp = t[tmp].link;
            if (tmp == -1) {
                break;
            }
            ++t[tmp].num;
            ++t[tmp].sum;
        }
     
        for (int v : order) {
            for (auto it : t[v].to) {
                t[v].num += t[it.second].num;
            }
        }

        for (int v : order) {
            for (auto it : t[v].to) {
                t[v].sum += t[it.second].sum + t[it.second].num;
            }
        }
    }

    struct node {
        int link;
        int len;
        map<char, int> to;
        int num; // right-context size
        ll sum;
        int firstpos;
        int lastpos;
        node() : link(-1), len(0), num(0), sum(0) {}
    };
 
    vector<node> t;
    int last;
    vector<int> order;
     
    void add(char c) {
        int curr = sz(t);
        t.pb(node());
        t[curr].len = t[last].len + 1;
        t[curr].firstpos = t[curr].lastpos = t[last].len;
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
        if (t[q].len == t[p].len + 1) {
            t[curr].link = q;
            last = curr;
            return;
        }
        int clone = sz(t);
        t.pb(node());
        t[clone].len = t[p].len + 1;
        t[clone].firstpos = t[q].firstpos;
        t[q].lastpos = t[last].len;
        t[clone].link = t[q].link;
        t[clone].to = t[q].to;
        t[curr].link = clone;
        t[q].link = clone;
        last = curr;
        while (p != -1 && t[p].to[c] == q) {
            t[p].to[c] = clone;
            p = t[p].link;
        }
    }

};

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

void mul(int& a, int b) {
    ll c = ll(a) * b;
    if (c >= mod) {
        c %= mod;
    }
    a = c;
}

void sub(int& a, int b) {
    a -= b;
    if (a < 0) {
        a += mod;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string a, b, c;
    cin >> a >> b >> c;

    string s = a;
    s += char(0);
    s += b;
    s += char(1);
    s += c;
    s += char(2);

    SuffixAutomaton sa(s);
    vector<int> order = sa.order;
    //reverse(all(order));
    int N = sz(sa.t);

    vector<vector<int> > cnt(N, vector<int>(3));
    for (int i = 0; i < 3; ++i) {
        for (int v : order) {
            for (auto it : sa.t[v].to) {
                if (it.first == char(i)) {
                    ++cnt[v][i];
                } else if (it.first != char(0) && it.first != char(1) && it.first != char(2)) {
                    cnt[v][i] += cnt[it.second][i];
                }
            }
        }
    }

    
    //assert(cnt[v][2] == 1);

    int k = min(sz(a), min(sz(b), sz(c)));
    vector<int> info(k + 1);
    for (int v = 1; v < N; ++v) {
        int p = sa.t[v].link;
        int l = sa.t[p].len + 1;
        int r = sa.t[v].len;
        int val = cnt[v][0];
        mul(val, cnt[v][1]);
        mul(val, cnt[v][2]);
        add(info[l], val);
        if (r + 1 <= k) {
            sub(info[r + 1], val);
        }
    }

    int ans = info[0];
    for (int i = 1; i <= k; ++i) {
        add(ans, info[i]);
        cout << ans << " ";
    }
    cout << "\n";

}