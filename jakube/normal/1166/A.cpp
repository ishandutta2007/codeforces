#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<char, int> cnts;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cnts[s[0]]++;
    }

    int result = 0;
    for (auto [_, c] : cnts) {
        int x = c / 2;
        result += x * (x-1) / 2;
        x = c - x;
        result += x * (x-1) / 2;
    }
    cout << result << '\n';
}