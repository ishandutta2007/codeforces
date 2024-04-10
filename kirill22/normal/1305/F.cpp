#include<bits/stdc++.h>

using namespace std;

#define int long long

int solve(vector<int>& a, int d) {
    int res = 0;
    for (auto x : a) {
        if (x == x % d) res += d - x % d;
        else res += min(x % d, d - x % d);
    }
    return res;
}

void update(int k, int& ans, vector<int>& a) {
    for (int i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            ans = min(ans, solve(a, i));
        }
        while (k % i == 0) k /= i;
    }
    if (k > 1) ans = min(ans, solve(a, k));
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    mt19937 gen(time(0));
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = n;
    int test_keys = 5;
    while (test_keys--) {
        int x = gen() % n;
        update(a[x], ans, a);
        update(a[x] - 1, ans, a);
        update(a[x] + 1, ans, a);
    }
    cout << ans;
}