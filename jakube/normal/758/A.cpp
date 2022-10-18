#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    int m = *max_element(v.begin(), v.end());
    cout << m*n - accumulate(v.begin(), v.end(), 0) << endl;

    return 0;
}