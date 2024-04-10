#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> indices(26);
    for (int i = 0; i < n; i++)
        indices[s[i] - 'a'].push_back(i);

    vector<bool> use(n, true);
    int i = 0, j = 0;
    while (k) {
        while (indices[i].size() == j) {
            i++;
            j = 0;
        }
        use[indices[i][j]] = false;
        j++;
        k--;
    }

    for (int i = 0; i < n; i++) {
        if (use[i])
            cout << s[i];
    }
    cout << endl;
}