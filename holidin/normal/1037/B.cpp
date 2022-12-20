#include <bits/stdc++.h>
using namespace std;
const int N = 20000;

int main() {
    int i, j, n, s;
    vector <int> v;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for (i = 0; i < n; ++i) {
        cin >> j;
        v.push_back(j);
    }
    sort(v.begin(), v.end());
    long long ans = abs(v[n / 2] - s);
    for (i = n / 2 + 1; i < n; ++i)
    if (v[i] < s)
        ans += s - v[i];
    for (i = 0; i < n / 2; ++i)
    if (v[i] > s)
        ans -= s - v[i];
    cout << ans;
}