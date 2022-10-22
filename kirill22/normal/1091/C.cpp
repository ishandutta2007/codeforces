#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<long long> ans;
    auto upd = [&] (int x) {
        long long res = n / x;
        res += x * 1ll * (n / x) * 1ll * (n / x - 1) / 2;
        ans.push_back(res);
    };
    int m = n;
    for (int x = 1; x * x <= m; x++) {
        if (m % x == 0) {
            upd(x);
            upd(n / x);
        }
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    for (auto x : ans) {
        cout << x << " ";
    }
}