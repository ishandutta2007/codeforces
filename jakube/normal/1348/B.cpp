#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    
    set<int> s(a.begin(), a.end());
    if (s.size() > k) {
        cout << -1 << '\n';
        return;
    }
    int c = 1;
    while (s.size() < k) {
        while (s.count(c))
            c++;
        s.insert(c);
    }

    cout << k * 100 << '\n';
    for (int i = 0; i < 100; i++) {
        for (int x : s)
            cout << x << ' ';
    }
    cout << '\n';
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