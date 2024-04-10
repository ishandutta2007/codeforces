#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    sort(v.begin(), v.end());
    long long sum = accumulate(v.begin(), v.end(), 0LL);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cout << sum - v[n - x] << '\n';
    }
}