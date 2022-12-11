#include <bits/stdc++.h>
 
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;
 
struct SuffixAutomaton {
 
    SuffixAutomaton(const string& s) {
        t.pb(node());
        last = 0;
        for (int i = 0; i < sz(s); ++i) {
            add(s[i]);
        }
 
        vector<int> order;
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
 
const int magic = 10;
 
int main() {
 
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    string s;
    cin >> s;
 
    int q;
    cin >> q;
 
    vector<string> p(q);
    vector<int> lf(q), rg(q);
    for (int i = 0; i < q; ++i) {
        cin >> p[i] >> lf[i] >> rg[i];
    }
 
    string str = s;
    str += char(magic);
    for (int i = 0; i < q; ++i) {
        str += p[i];
        str += char(magic + i + 1);
    }
 
    SuffixAutomaton automaton(str);
 
    vector<int> order;
    for (int v = 0; v < sz(automaton.t); ++v) {
        order.pb(v);
    }
    sort(all(order), [&] (int x, int y) { return automaton.t[x].len > automaton.t[y].len; });
 
    vector<vector<int> > cnt(sz(automaton.t), vector<int>(q + 1));
    for (int v : order) {
        for (auto it : automaton.t[v].to) {
            if (isalpha(it.first)) {
                for (int i = 0; i <= q; ++i) {
                    cnt[v][i] += cnt[it.second][i];
                }
            } else {
                ++cnt[v][it.first - magic];
            }
        }
    }
 
    ll ans = 0;
    for (int v = 1; v < sz(automaton.t); ++v) {
        if (cnt[v][0] == 0) {
            continue;
        }
        bool ok = true;
        for (int i = 0; i < q; ++i) {
            if (cnt[v][i + 1] >= lf[i] && cnt[v][i + 1] <= rg[i]) {
                continue;
            } else {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        ans += automaton.t[v].len - automaton.t[automaton.t[v].link].len;
    }
 
    cout << ans << "\n";
 
}