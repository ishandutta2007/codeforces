#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, x;
    cin >> n >> k >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    
    long long sum = 0;
    for (int i = n-1; i >= 0; i--) {
        if (k && v[i] > x) {
            sum += x;
            k--;
        } else {
            sum += v[i];
        }
    }
    cout << sum << endl;
}