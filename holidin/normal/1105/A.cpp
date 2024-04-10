#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 1e5 + 2;

int a[N];

int main() {
    int i, j, k, n, l;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = 1e9, ms = -1;
    for (i = 1; i <= 100; ++i) {
        int sum = 0;
        for (j = 1; j <= n; ++j)
            sum += min(min(abs(a[j] - i + 1), abs(a[j] - i - 1)), abs(a[j] - i));
        if (ans > sum) {
            ans  = sum;
            ms = i;
        }
    }
    cout << ms << ' ' <<ans;
}