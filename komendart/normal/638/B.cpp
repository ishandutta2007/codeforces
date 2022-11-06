#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    vector<int> next(26, -1);
    vector<char> is_child(26);
    vector<char> used(26);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int m = s.size();
        for (int j = 0; j < m; j++) {
            int c = s[j] - 'a';
            used[c] = true;
            if (j > 0) {
                next[s[j - 1] - 'a'] = c;
                is_child[c] = true;
            }
        }
    }

    string res;
    for (int i = 0; i < 26; i++) {
        if (!used[i] || is_child[i]) continue;
        for (int j = i; j != -1; j = next[j]) {
            res += string(1, j + 'a');
        }
    }

    cout << res << '\n';

}