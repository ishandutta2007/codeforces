#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k, b, c;
vector<int> t;

int f(int mod) {
    vector< pair<int, int> > arr(n);
    for (int i = 0; i < n; i++) {
        arr[i] = {t[i], 0};
        int tmp = t[i] % 5;
        if (tmp <= mod) {
            arr[i].first += mod - tmp;
            arr[i].second = (mod - tmp) * c;
        } else {
            arr[i].first += 5 + mod - tmp;
            arr[i].second = (5 + mod - tmp) * c;
        }
    }
    sort(arr.begin(), arr.end());

    vector<int> t(n), cost(n);
    for (int i = 0; i < n; i++) {
        t[i] = arr[i].first;
        cost[i] = arr[i].second;
    }

    int ans = 1e18;
    set< pair<int, int> > d;
    int sum = 0;
    int prev = t[0];
    for (int i = 0; i < n; i++) {
        sum += cost[i];
        sum += (t[i] - prev) / 5 * b * d.size();
        d.insert({cost[i] - (t[i] - t[0]) / 5 * b, i});
        if (d.size() > k) {
            auto p = *d.rbegin();
            d.erase(p);
            sum -= cost[p.second];
            sum -= (t[i] - t[p.second]) / 5 * b;
        }
        if (d.size() == k) ans = min(ans, sum);
        prev = t[i];
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> k >> b >> c;
    t.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        t[i] += (int) 1e9;
    }
    b = min(b, 5 * c);

    int ans = 1e18;
    for (int i = 0; i < 5; i++) {
        ans = min(ans, f(i));
    }
    cout << ans << '\n';
}