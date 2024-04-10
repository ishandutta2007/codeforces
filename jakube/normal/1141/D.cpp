#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(2);
    for (auto& x : s)
        cin >> x;
    
    vector<pair<int, int>> result;
    vector<map<char, vector<int>>> cnts(2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cnts[i][s[i][j]].push_back(j);
        }
    }

    auto add = [&](char c, char d) {
        while (!cnts[0][c].empty() && !cnts[1][d].empty()) {
            result.push_back({cnts[0][c].back(), cnts[1][d].back()});
            cnts[0][c].pop_back();
            cnts[1][d].pop_back();
        }
    };

    for (char c = 'a'; c <= 'z'; c++)
        add(c, c);
    for (char c = 'a'; c <= 'z'; c++)
        add('?', c);
    for (char c = 'a'; c <= 'z'; c++)
        add(c, '?');
    add('?', '?');

    cout << (int)result.size() << '\n';
    for (auto [a, b] : result) {
        cout << a + 1 << " " << b + 1 << '\n';
    }
}