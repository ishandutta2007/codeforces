#include <bits/stdc++.h>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, a, b, k;
    string s;
    cin >> n >> a >> b >> k;
    cin >> s;
    s += "1";
    vector<int> left;
    vector<int> right;
    int prev = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (i != prev) {
                left.push_back(prev);
                right.push_back(i - 1);
            }
            prev = i + 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < left.size(); i++) {
        sum += (right[i] - left[i] + 1) / b;
    }
    vector<int> ans;
    for (int i = 0; i < left.size(); i++) {
        int p = left[i] + b - 1;
        while (sum >= a && p <= right[i]) {
            sum--;
            ans.push_back(p);
            p += b;
        }
    }

    cout << ans.size() << '\n';
    for (auto i: ans) {
        cout << i + 1 << ' ';
    }
}