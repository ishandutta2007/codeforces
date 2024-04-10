#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

long long cnt[N];

int main() {
    int i, j, k, n;
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    long long ans = 0;
    for (i = 2; i <= n; ++i) {
        for (j = 2; i * j <= n; ++j) {
            cnt[i * j] += j;
            cnt[i] += j;
        }
        if (cnt[i] > 0)
            ans += 2 * cnt[i];
    }
    cout << ans;
}