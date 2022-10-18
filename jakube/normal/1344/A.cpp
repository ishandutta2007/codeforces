#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int idx = 0;
    for (auto& x : a) {
        cin >> x;
        x = (((x + idx) % n) + n) % n;
        idx++;
    }
    set<int> s(a.begin(), a.end());
    if (s.size() == n)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        solve();
    }
    
}