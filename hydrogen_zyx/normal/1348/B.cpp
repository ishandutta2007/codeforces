#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[500];
vector<int> v;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        v.clear();
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        set<int> s;
        for (int i = 1; i <= n; i++) {
            if (s.count(a[i]) == 0) {
                v.push_back(a[i]);
                s.insert(a[i]);
            }
        }
        if (s.size() > k) {
            cout << -1 << endl;
            continue;
        }
        while (v.size() < k) v.push_back(1);
        cout << k * n << endl;
        for (int i = 1; i <= n; i++) {
            for (auto x : v) cout << x << ' ';
        }
        cout << endl;
    }
}