#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const long long N = 1e4 + 1;
const long long mod = 998244353;


int main() {
    int i, j, k, n, l, r, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int mn = 1e9, cnt = 0;
    for (i = 1; i <= n; ++i) {
        cin >> j;
        if (j < mn) {
            mn = j;
            cnt = 0;
        }
        if (j == mn)
            ++cnt;
    }
    if (cnt > n / 2)
        cout << "Bob";
    else
        cout << "Alice";
}