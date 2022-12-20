#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 5e3;


int main() {
    int i, j, n, k;
    //freopen("input.txt", "r", stdin);
    ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    cout << n + 1 << "\n";
    cout << 1 << ' ' << n << ' ' << 800000 << "\n";
    for (i = 1; i <= n; ++i) {
        cin >> j;
        j += 800000;
        cout << 2 << ' ' << i << ' ' << j - i << "\n";
    }
}