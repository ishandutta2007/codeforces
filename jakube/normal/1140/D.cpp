#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long res = 0;
    for (int i = 2; i < n; i++) {
        res += i * (i + 1);
    }
    cout << res << '\n';
}