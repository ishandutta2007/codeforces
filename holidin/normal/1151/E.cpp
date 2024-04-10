#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 45;
const int mod = 1e9 + 7;
long long a[N];

int main() {
    long long i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    long long cnt = 0;
    for (i = 1; i <= n; ++i)
    if (a[i - 1] < a[i])
        cnt += (a[i] - a[i - 1]) * (n - a[i] + 1);
    else
        cnt += (a[i - 1] - a[i]) * a[i];
    cout << cnt;
}