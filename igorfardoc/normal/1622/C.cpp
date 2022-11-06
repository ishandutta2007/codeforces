#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        int n;
        ll k;
        cin >> n >> k;
        vi a(n);
        ll sum = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 1000000000000000000ll;
        for(int i = 0; i < n; i++) {
            ll sum1 = sum - a[0];
            ll need = k - sum1;
            ll each = 0;
            if(need >= 0) {
                each = need / (i + 1);
            } else {
                each = -((-need - 1) / (i + 1) + 1);
            }
            ans = min(ans, i + max(a[0] - each, 0ll));
            sum -= a[n - i - 1];
        }
        cout << ans << '\n';
    }
}