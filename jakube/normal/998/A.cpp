#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
        sum += v[i].first;
    }
    sort(v.begin(), v.end());
    if (n == 1 || v[0].first*2 == sum) {
        cout << -1 << '\n';
    } else {
        cout << 1 << '\n';
        cout << v[0].second + 1 << '\n';
    }
}