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

void invert(char& c) {
    if (c == '1') {
        c = '0';
    } else {
        c = '1';
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int q;
    cin >> q;

    while (q--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        SuffixAutomaton sa(s);
        string t = "";
        for (int i = 0; i < k; ++i) {
            t += "1";
        }
        vector<int> nodes;
        nodes.pb(0);
        bool found = false;
        for (int i = 0; i < k; ++i) {
            int v = nodes.back();
            if (!sa.t[v].to.count(t[i])) {
                found = true;
                break;
            } else {
                nodes.pb(sa.t[v].to[t[i]]);
            }
        }
        if (found) {
            cout << "YES\n";
            for (int i = 0; i < k; ++i) {
                cout << 0;
            }
            cout << "\n";
            continue;
        }
        while (true) {
            int pos = -1;
            for (int i = k - 1; i >= 0; --i) {
                if (t[i] == '1') {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                cout << "NO\n";
                break;
            }
            for (int i = pos; i < k; ++i) {
                nodes.pop_back();
            }
            for (int i = pos; i < k; ++i) {
                invert(t[i]);
                int v = nodes.back();
                if (!sa.t[v].to.count(t[i])) {
                    found = true;
                    break;
                } else {
                    nodes.pb(sa.t[v].to[t[i]]);
                }
            }
            if (found) {
                cout << "YES\n";
                for (int i = 0; i < k; ++i) {
                    invert(t[i]);
                    cout << t[i];
                }
                cout << "\n";
                break;
            }
        }
    }

}