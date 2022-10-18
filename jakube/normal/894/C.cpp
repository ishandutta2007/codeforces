#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int g = accumulate(v.begin(), v.end(), 0, [](int a, int b){ return __gcd(a, b);});
    if (g != v[0]) {
        cout << -1 << endl;
    } else {
        cout << 2*n << endl;
        for (int i : v)
            cout << i << ' ' << g << ' ';
        cout << endl;
    }
}