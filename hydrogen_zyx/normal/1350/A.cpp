#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int d = 2;
        while (n % d) d++;
        n += d;
        n += (k - 1) * 2;
        cout << n << endl;
    }
}