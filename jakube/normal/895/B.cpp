#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, k;
    cin >> n >> x >> k;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    long long res = 0;
    for (int i = 0; i < n; i++) {
        // a[j] / x - (a[i] - 1) / x = k
        // a[j] /x =  k + (a[i] - 1) / x
        long long b = k + (v[i] - 1) / x;
        long long low = max(b * x, v[i]);
        long long high = (b + 1) * x;
        res += lower_bound(v.begin(), v.end(), high) - lower_bound(v.begin(), v.end(), low);
    }
    cout << res << endl;
}