#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<long long> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());

    vector<long long> delta(n);
    for (int i = 0; i + 1 < n; i++) {
        delta[i] = s[i + 1] - s[i];
    }
    delta[n - 1] = 2e18 + 7;
    sort(delta.begin(), delta.end());

    vector<long long> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + delta[i];
    }

    int q;
    cin >> q;
    while(q--) {
        long long l, r;
        cin >> l >> r;
        long long m = r - l + 1;

        int ind = lower_bound(delta.begin(), delta.end(), m) - delta.begin();

        long long ans = sum[ind] + (n - ind) * m;
        cout << (long long)ans << ' ';

    }

    return 0;
}