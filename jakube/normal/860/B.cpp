#include <bits/stdc++.h>

using namespace std;

struct Node {
    array<Node*, 10> next = {{nullptr}};
    int last = -1;
    int cnt = 0;
};

int main() {
    std::ios::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    Node *root = new Node;
    for (int i = 0; i < n; i++) {
        auto s = v[i];
        for (int start = 0; start < 9; start++) {
            Node *cur = root;
            for (int j = start; j < 9; j++) {
                if (cur->next[s[j] - '0'] == nullptr)
                    cur->next[s[j] - '0'] = new Node;
                cur = cur->next[s[j] - '0'];
                if (cur->last != i) {
                    cur->last = i;
                    cur->cnt++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int best_start = 0;
        int best_len = 999;
        auto s = v[i];
        for (int start = 0; start < 9; start++) {
            Node *cur = root;
            for (int j = start; j < 9; j++) {
                cur = cur->next[s[j] - '0'];
                if (cur->cnt == 1 && j + 1 - start < best_len) {
                    best_start = start;
                    best_len = j + 1 - start;
                }
            }
        }

        for (int j = 0; j < best_len; j++) {
            cout << s[best_start+j];
        }
        cout << '\n';
    }
}