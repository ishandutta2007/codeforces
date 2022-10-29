#include <bits/stdc++.h>
using namespace std;
int a[200000], b[2000000];
vector<int> ans;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ans.clear();
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            a[i] = c - '0';
        }
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            b[i] = c - '0';
        }
        int p = n - 1;
        bool f = 0;
        int s = 0;
        int cnt = 0;
        while (cnt < n) {
            if (a[p] ^ f == b[n - cnt - 1]) {
                cnt++;
                if (f) {
                    p++;
                } else
                    p--;
                continue;
            }
            if (a[s] ^ f != b[n - cnt - 1]) {
                ans.push_back(n - cnt++);
                swap(s, p);
                if (f)
                    p--;
                else
                    p++;
                f ^= 1;
            } else {
                ans.push_back(1);
                ans.push_back(n - cnt++);
                swap(s, p);
                if (f)
                    p--;
                else
                    p++;
                f ^= 1;
            }
        }
        cout << ans.size() << ' ';
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}