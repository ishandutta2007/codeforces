#include <bits/stdc++.h>
using namespace std;
vector<int> v[300000];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 2; j * j <= a; j++) {
            int cnt = 0;
            while (a % j == 0) {
                cnt++;
                a /= j;
            }
            if (cnt) v[j].push_back(cnt);
        }
        if (a != 1) v[a].push_back(1);
    }
    long long ans = 1;
    for (int i = 1; i <= 200000; i++) {
        if (v[i].size() == n) {
            nth_element(v[i].begin(), v[i].begin() + 1, v[i].end());
            ans *= pow(i, v[i][1]);
        } else if (v[i].size() == n - 1) {
            nth_element(v[i].begin(), v[i].begin(), v[i].end());
            ans *= pow(i, v[i][0]);
        }
    }
    cout << ans;
}