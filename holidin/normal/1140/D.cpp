#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 1;

int main() {
    int i, j, k, n, q, t, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    long long ans = 0;
    for (i = 2; i < n; ++i)
        ans += i * (i + 1);
    cout << ans;
}