// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    vector<int> a;
    for (int x=1; x<=10000; x++) {
        if (x % 3 == 0 || x % 10 == 3) continue;
        a.push_back(x);
    }

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        cout << a[x-1] << '\n';
    }
}