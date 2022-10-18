#include <bits/stdc++.h>

#define int long long
#define fs first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define len(v) ((int)v.size())
#define vc vector
#define pr pair
#define endl "\n"
#define endd "\n"; return 0;
#define all(v) v.begin(), v.end()

using namespace std;

const int MAXN = 1e5;
const int INF = 1e10;
const int MOD = 1e9 + 7;

main() {
    ios_base::sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 0;
    int tek = 0;
    for (int i = 0; i < n - 1; i++){
        if ((a[i + 1] - a[i]) % k != 0){
            cout << -1 << endd;
        }
        tek += (a[i + 1] - a[i]) / k;
        ans += tek;
    }
    cout << ans;
}