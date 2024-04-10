#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
        x %= k;
    }
    int g = accumulate(v.begin(), v.end(), k, [](int a, int b){ return gcd(a, b); });
    cout << k / g << endl;
    cout << 0;
    int last = g;
    while (last < k) {
        cout << " " << last;
        last += g;
    }
}