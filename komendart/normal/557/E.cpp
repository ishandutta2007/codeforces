#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000;

int n, k;
string s;

char good[maxn][maxn];

bool is_good(int i, int j) {
    if (i > j) return true;
    if (good[i][j] != -1) return good[i][j];
    return good[i][j] = (s[i] == s[j] && is_good(i + 2, j - 2));
}

struct Trie {
    int cnt;
    Trie* liters[2];
} nodes[maxn * maxn + 2];
Trie* last_node = &nodes[0];

void add_string(int i) {
    Trie* p = &nodes[0];
    for (int j = i; j < n; j++) {
        int c = s[j] == 'a' ? 0: 1;
        if (!p->liters[c]) {
            p->liters[c] = ++last_node;
            p = last_node;
        } else {
            p = p->liters[c];
        }
        if (good[i][j]) {
            p->cnt++;
        }
    }
}

stack<char> result;
bool walk(Trie* p) {
    k -= p->cnt;
    if (k <= 0) return true;
    for (int i = 0; i < 2; i++) {
        Trie* child = p->liters[i];
        if (child && walk(child)) {
            result.push(i == 0 ? 'a': 'b');
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> s >> k;
    n = s.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            good[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            is_good(i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        add_string(i);
    }

    walk(&nodes[0]);
    while (!result.empty()) {
        cout << result.top();
        result.pop();
    }
}