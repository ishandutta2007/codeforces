#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200000];
vector<int> ans;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ans.clear();
        ans.push_back(a[1]);
        bool f = (a[1] < a[2]);
        for (int i = 2; i < n; i++) {
            if ((a[i] < a[i + 1]) == f)
                continue;
            else {
                ans.push_back(a[i]);
                f ^= 1;
            }
        }
        ans.push_back(a[n]);
        cout << ans.size() << endl;
        for (auto x : ans) cout << x << ' ';
        cout << endl;
    }
}