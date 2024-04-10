//
// Created by hydd on 2022/10/11.
//
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int n = 0;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n + 1));

    int sum = 0, v = 0;
    for (int k = 0; k <= 1; k++)
        for (int i = 1; i <= n; i++) {
            cin >> v;
            a[k][i] = v;
            sum += v;
        }
    for (int k = 0; k <= 1; k++)
        for (int i = 1; i <= n; i++) {
            cin >> v;
            a[k][i] -= v;
            sum -= v;
        }
    if (sum) {
        cout << "-1" << endl;
        return 0;
    }

    int s0 = 0, s1 = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        s0 += a[0][i];
        s1 += a[1][i];
        while (s0 > 0 && s1 < 0) {
            s0--;
            s1++;
            ans++;
        }
        while (s0 < 0 && s1 > 0) {
            s0++;
            s1--;
            ans++;
        }
        ans += abs(s0) + abs(s1);
    }
    cout << ans << endl;
    return 0;
}