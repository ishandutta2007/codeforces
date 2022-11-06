#include <bits/stdc++.h>
using namespace std;
const long long p = 1e9 + 7;
int main() {
    long long n, ans1 = 1, ans2 = 1;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ans1 = (27 * ans1) % p;
        ans2 = (7 * ans2) % p;
    }
    cout << (ans1 + p - ans2) % p;
};