#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int a[N];

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int lst = 0, ans = 0;
    cin >> n;
    for (i = 1; i <= n; ++i) {
        cin >> a[i];
        lst = max(lst, a[i]);
        if (lst <= i)
            ++ans;
    }
    cout << ans;
}