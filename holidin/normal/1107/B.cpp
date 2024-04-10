#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int i, j, n, q;
    long long k, t;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> k >> t;
        cout << (k - 1) * 9 + t << "\n";
    }
}