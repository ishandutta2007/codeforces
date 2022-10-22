#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = (int) s.size(), x;
        cin >> x;
        vector<pair<int, int>> tmp;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            tmp.push_back({s[i] - 'a' + 1, i});
            sum += s[i] - 'a' + 1;
        }
        sort(tmp.rbegin(), tmp.rend());
        vector<int> used(n, 1);
        for (auto [y, i] : tmp) {
            if (sum > x) {
                sum -= y;
                used[i] = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (used[i]) {
                cout << s[i];
            }
        }
        cout << '\n';
    }
}