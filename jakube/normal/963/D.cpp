#include <bits/stdc++.h>
using namespace std;

constexpr int K = 26;
struct Vertex {
    std::array<int, K> next;
    bool terminal = false;
    int terminal_idx = -1;
    int p = -1;
    char pch;
    int depth = 0;
    int link = 0;
    int next_terminal = 0;
    std::array<int, K> go;

    Vertex(int p, char ch, int depth) : p(p), pch(ch), depth(depth) {
        std::fill(next.begin(), next.end(), 0);
        std::fill(go.begin(), go.end(), 0);
    }
};

class AhoCorasick {
public:
    AhoCorasick() : t(1, {-1, '$', 0}) {}

    void add_string(std::string const& s, int idx) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (!t[v].next[c]) {
                t[v].next[c] = t.size();
                t.emplace_back(v, ch, t[v].depth + 1);
            }
            v = t[v].next[c];
        }
        t[v].terminal = true;
        t[v].terminal_idx = idx;
    }

    void push_links() {
        std::queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            auto& cur = t[v];
            auto& link = t[cur.link];
            q.pop();
            cur.next_terminal = link.terminal ? cur.link : link.next_terminal;

            for (int c = 0; c < K; c++) {
                if (cur.next[c]) {
                    t[cur.next[c]].link = v ? link.next[c] : 0;
                    q.push(cur.next[c]);
                } else {
                    cur.next[c] = link.next[c];
                }
            }
        }
    }

    int transition(int idx, char c) {
        return t[idx].next[c - 'a'];
    }

    Vertex const& getInfo(int idx) {
        return t[idx];
    }

private:
    std::vector<Vertex> t;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int n;
    cin >> n;
    
    vector<pair<int, int>> queries(n);
    AhoCorasick aho;
    for (int i = 0; i < n; i++) {
        cin >> queries[i].first;
        string t;
        cin >> t;
        aho.add_string(t, i);
        queries[i].second = t.size();
    }
    aho.push_links();

    vector<vector<int>> occurences(n);
    int cur = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        cur = aho.transition(cur, s[i]);
        int tmp = cur;
        while (tmp) {
            auto& x = aho.getInfo(tmp);
            if (x.terminal)
                occurences[x.terminal_idx].push_back(i);
            tmp = x.next_terminal;
        }
    }

    for (int i = 0; i < n; i++) {
        auto [k, l] = queries[i];
        auto& o = occurences[i];
        int m = o.size();
        if (k > m) {
            cout << -1 << '\n';
            continue;
        }

        int best = std::numeric_limits<int>::max();
        for (int j = 0; j + k - 1 < m; j++) {
            best = min(best, o[j+k-1] - o[j] + l);
        }
        cout << best << '\n';
    }
}