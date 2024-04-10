#include <bits/stdc++.h>
using namespace std;

int main() {
    int i, j, n;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //ios_base::sync__with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int x = 1, ans = 0;
    while (x < n) {
        ++ans;
        x *= 2;
    }
    if (x == n)
        ++ans;
    cout << ans;
}