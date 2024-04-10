#include <bits/stdc++.h>

const int MOD = 1e9 + 7;

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> cnt(k);
    for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i] % k]++;

    int ans = 0;
    for (int i = 1; i < (k + 1) / 2; i++) ans += min(cnt[i], cnt[k - i]);
    ans += cnt[0] / 2;
    if (k % 2 == 0) ans += cnt[k / 2] / 2;

    cout << ans * 2;
}