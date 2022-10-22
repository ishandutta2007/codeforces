#include<bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define eb emplace_back
#define ld long double

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n, -1);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    int tmp = n - 1, tmp2 = 0;
    for (int i = 0; i < n; i += 2) b[i] = a[tmp], tmp--;
    for (int i = n - 2; i >= 0; i--) {
        if (b[i] == -1 && a[tmp2] < b[i + 1] && a[tmp2] < b[i - 1]) {
            b[i] = a[tmp2], tmp2++;
        }
    }
    for (int i = 0; i < n; i++) if (b[i] == -1) b[i] = a[tmp2], tmp2++;
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        if (b[i] < b[i - 1] && b[i] < b[i + 1]) ans++;
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) cout << b[i] << " ";
}