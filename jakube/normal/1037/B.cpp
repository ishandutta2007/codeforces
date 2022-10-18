#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (auto& x : v)
        cin >> x;
    sort(v.begin(), v.end());

    int mid = n / 2;
    if (v[mid] < s) {
        long long sum = 0;
        for (int i = mid; i < n; i++) {
            sum += max(0, s - v[i]);
        }
        cout << sum << '\n';
    } else {
        long long sum = 0;
        for (int i = mid; i >= 0; i--) {
            sum += max(0, v[i] - s);
        }
        cout << sum << '\n';
    }
}