#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);

    function<int(int)> sum_of_digits = [&](int u) {
        return u == 0 ? 0 : u % 10 + sum_of_digits(u / 10);
    };

    int t; cin >> t;
    while (t--) {
        int s, n; cin >> s >> n;
        priority_queue<int, vector<int>, greater<int>> ans;
        vector<int> xd;
        for (int cur = 1; n > 0 && s != 0; n--) {
            while (s % 10 == 0) {
                s /= 10;
                cur *= 10;
            }
            if (n == 1) {
                xd.push_back(s * cur);
                s = 0;
            } else {
                ans.push(cur);
                s--;
            }
        }
        while (n > 0) {
            int s = ans.top(); ans.pop();
            if (s == 1) {
                xd.push_back(s);
                continue;
            }
            ans.push(s / 10); s -= s / 10;
            for (int cur = 1; n > 0 && s != 0; n--) {
                while (s % 10 == 0) {
                    s /= 10;
                    cur *= 10;
                }
                if (n == 1) {
                    xd.push_back(s * cur);
                    s = 0;
                } else {
                    ans.push(cur);
                    s--;
                }
            }
        }
        for (; !ans.empty(); ans.pop()) {
            cout << ans.top() << " ";
        }
        for (; !xd.empty(); xd.pop_back()) {
            cout << xd.back() << " ";
        }
        cout << '\n';
    }
}