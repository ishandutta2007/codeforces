#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    int k = n / 2;
    int result = 1e9;
    for (int i = 0; i < n - k; i++) {
        result = min(result, x[i + k] - x[i]);
    }
    cout << result << '\n';
}