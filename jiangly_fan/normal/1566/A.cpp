#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    for (cin >> T; T; T -= 1) {
        LL n, s;
        cin >> n >> s;
        cout << s / (n - (n - 1) / 2) << "\n";
    }
    return 0;
}