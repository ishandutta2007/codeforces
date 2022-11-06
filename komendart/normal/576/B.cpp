#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> p(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
        if (i == p[i]) root = i;
    }

    if (root != -1) {
        cout << "YES" << '\n';
        for (int i = 0; i < n; i++) {
            if (i != root) {
                cout << root + 1 << ' ' << i + 1 << '\n';
            }
        }
        return 0;
    }

    bool odd = false;
    vector<char> used(n, false);
    vector< vector<int> > cycles;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            used[i] = true;
            vector<int> v = {i};
            for (int j = p[i]; j != i; j = p[j]) {
                used[j] = true;
                v.push_back(j);
            }
            cycles.push_back(v);
            if (v.size() == 2) {
                root = cycles.size() - 1;
            }
            if (v.size() % 2 == 1) {
                odd = true;
            }
        }
    }

    if (root == -1 || odd) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        cout << cycles[root][0] + 1 << ' ' << cycles[root][1] + 1 << '\n';
        for (int i = 0; i < cycles.size(); i++) {
            if (i == root) continue;
            for (int j = 0; j * 2 < cycles[i].size(); j++) {
                cout << cycles[root][0] + 1 << ' ' << cycles[i][2 * j] + 1 << '\n';
                cout << cycles[root][1] + 1 << ' ' << cycles[i][2 * j + 1] + 1 << '\n';
            }
        }
    }
}