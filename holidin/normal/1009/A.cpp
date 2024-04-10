#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;


int a[N], b[N];

int main() {
    int i, j, n, q, top, l, r, t, k;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (i = 0; i < n; ++i)
        cin >> a[i];
    for (i = 0; i < k; ++i)
        cin >> b[i];
    j = 0;
    int cnt = 0;
    for (i = 0; i < n; ++i)
    if (j < k && a[i] <= b[j]) {
        ++j;
        ++cnt;
    }
    cout << cnt;
}