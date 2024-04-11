#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

const int maxn = 3e5 + 100;

map<char, int> go[maxn];
int last = 0;
int cnt[maxn];

void add(const string &s) {
    int node = 0;
    for (char c: s) {
        if (!go[node].count(c)) {
            ++last;
            go[node][c] = last;
        }
        assert(go[node].count(c) && go[node][c]);
        node = go[node][c];
        ++cnt[node];
    }
}

int autocomplete(const string &s) {
    int node = 0;
    for (int it = 0; it < sz(s); ++it) {
        char c = s[it];
        if (!go[node].count(c)) {
            if (!go[node].empty()) return -1;
            return sz(s) - it;
        }
        assert(go[node].count(c) && go[node][c] > 0);
        node = go[node][c];
    }
    if (go[node].empty()) return 0;
    return -1;
}

int ask(const string &s) {
    int kek = autocomplete(s);
    if (kek == -1) return sz(s);
    int node = 0;
    for (int it = 0; it < sz(s); ++it) {
        char c = s[it];
        if (node != 0 && cnt[node] == 1) {
            return min(sz(s), it + 1 + kek);
        }
        if (!go[node].count(c)) return sz(s);
        node = go[node][c];
    }
    return sz(s);
}

signed main() {
    //freopen("t.in", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0);

    int ans = 0;
    vector<string> words;
    string cur = "";
    for (char c; cin.get(c);) {
        if (!isalpha(c)) {
            //cerr << (int) c << ' ';
            ++ans;
            if (!cur.empty()) {
                words.push_back(cur);
                cur = "";
            }
        } else {
            cur.push_back(c);
        }
    }
    //cerr << ans << endl;
    if (!cur.empty()) {
        words.push_back(cur);
        cur = "";
    }
    set<string> added;
    for (auto i: words) {
        //if (ask(i) != sz(i)) cerr << i << ' ' << sz(i) - ask(i) << endl;
        ans += ask(i);
        if (!added.count(i)) {
            add(i);
            added.insert(i);
        }
    }
    cout << ans << '\n';
}