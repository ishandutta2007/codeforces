#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        n = n * m;
        if (n & 1) n++;
        cout << n / 2 << endl;
    }
}