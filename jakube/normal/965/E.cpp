#include <bits/stdc++.h>
using namespace std;

struct Vertex {
    std::array<int, 26> next;
    bool terminal = false;

    Vertex() {
        std::fill(next.begin(), next.end(), 0);
    }
};

class Trie {
public:
    Trie() : t(1) {}

    void add_string(std::string const& s) {
        int v = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (!t[v].next[c]) {
                t[v].next[c] = t.size();
                t.emplace_back();
            }
            v = t[v].next[c];
        }
        t[v].terminal = true;
    }

    std::vector<Vertex> t;
};
Trie trie;


struct S {
    int sum;
    int cnt;
    vector<int> cnts;
};

S dfs(int v) {
    S result = {0, 0, {}};

    auto node = trie.t[v];
    for (int i = 0; i < 26; i++) {
        if (node.next[i]) {
            auto res = dfs(node.next[i]);
            result.sum += res.sum;
            result.cnt += res.cnt;
            if (res.cnts.size() > result.cnts.size())
                result.cnts.resize(res.cnts.size());
            for (int i = 0; i < (int)res.cnts.size(); i++) {
                result.cnts[i] += res.cnts[i];
            }
        }
    }

    if (node.terminal) {
        result.cnts.insert(result.cnts.begin(), 1);
        result.cnt++;
        // result.
    }
    else {
        auto& c = result.cnts;
        int idx = c.size() - 1;
        if (c.back() > 1)
            c.push_back(c.back() - 1);
        for (int j = idx; j >= 0; j--) {
            c[j] = 1 + (j ? c[j-1] - 1 : 0);
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        trie.add_string(s);
    }
    
    int sum = 0;
    auto& t = trie.t[0];
    for (int i = 0; i < 26; i++) {
        if (t.next[i]) {
            auto x = dfs(t.next[i]).cnts;
            for (int j = 0; j < (int)x.size(); j++) {
                sum += (j + 1) * x[j];
            }
        }
    }
    cout << sum << endl;
}