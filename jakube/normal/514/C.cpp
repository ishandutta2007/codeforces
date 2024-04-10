#include <bits/stdc++.h>
using namespace std;

struct Node {
    array<Node*, 3> next = {{nullptr}};
    bool finish;
};

bool isSubstrExcept1(string& s, int idx, Node* node, int difference) {
    if (idx == s.size()) {
        return node->finish && difference == 1;
    }

    for (int i = 0; i < 3; i++) {
        if (node->next[i] != nullptr && (difference == 0 || s[idx] == 'a' + i)) {
            if (isSubstrExcept1(s, idx + 1, node->next[i], difference + (s[idx] != 'a' + i)))
                return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;

    Node* root = new Node;;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        Node* cur = root;
        for (char c : s) {
            if (cur->next[c - 'a'] == nullptr) 
                cur->next[c - 'a'] = new Node;
            cur = cur->next[c - 'a'];
        }
        cur->finish = true;
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        cout << (isSubstrExcept1(s, 0, root, 0) ? "YES" : "NO") << '\n';
    }
}