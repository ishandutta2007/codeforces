#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    long long sum = 0;
    for (int x : v) {
        sum += (x + k - 1) / k;
    }

    cout << (sum + 1) / 2 << endl;

    return 0;
}