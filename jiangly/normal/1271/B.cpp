#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    int x = 0;
    for (int i = 0; i < n; ++i)
        if (s[i] == 'B')
            ++x;
    if (n % 2 == 0 && x % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }
    char goal = x % 2 == 0 ? 'W' : 'B';
    vector<int> sol;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != goal) {
            s[i] ^= 'W' ^ 'B';
            s[i + 1] ^= 'W' ^ 'B';
            sol.push_back(i + 1);
        }
    }
    cout << sol.size() << "\n";
    for (int i : sol)
        cout << i << " \n"[i == sol.back()];
    return 0;
}