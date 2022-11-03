#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (abs(a - b) > 1) {
            cout << -1 << "\n";
            continue;
        }
        string s;
        if (a > b) {
            s.push_back('+');
        } else {
            s.push_back('-');
        }
        while (a > 0 || b > 0) {
            if (s.back() == '-') {
                --b;
                s.push_back('+');
            } else {
                --a;
                s.push_back('-');
            }
        }
        if (s.size() > n - 1) {
            cout << -1 << "\n";
            continue;
        }
        char c = s.back();
        int L = 1, R = n;
        int tail = n - 1 - s.size();
        if (c == '-') {
            L += tail;
        } else {
            R -= tail;
        }
        vector<int> ans;
        if (s[0] == '+') {
            ans.push_back(L);
            ++L;
        } else {
            ans.push_back(R);
            --R;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '-') {
                ans.push_back(L);
                ++L;
            } else {
                ans.push_back(R);
                --R;
            }
        }
        if (c == '-') {
            for (int i = tail; i >= 1; --i) {
                ans.push_back(i);
            }
        } else {
            for (int i = tail; i >= 1; --i) {
                ans.push_back(n - i + 1);
            }
        }
        for (int i = 0; i < ans.size(); ++i) {
            if (i) {
                cout << " ";
            }
            cout << ans[i];
        }
        cout << "\n";
    }

}