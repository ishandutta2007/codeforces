#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    map<int, int> m;
    int longest = 0;
    for (int x : v) {
        m[x] = m[x-1] + 1;
        longest = max(longest, m[x]);
    }

    int start = 0;
    for (auto [a, b] : m) {
        if (b == longest) {
            start = a - longest + 1;
            break;
        }
    }

    cout << longest << '\n';
    for (int i = 0; i < n; i++) {
        if (v[i] == start) {
            cout << i + 1 << ' ';
            start++;
        }
    }
    cout << '\n';
}