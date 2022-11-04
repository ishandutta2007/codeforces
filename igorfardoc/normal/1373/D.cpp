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
        cin >> n;
        ll sum = 0;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i % 2 == 0) {
                sum += a[i];
            }
        }
        ll now = 0;
        vector<ll> prefmax1(n + 1, 0), prefmax2(n + 1, 0);
        for(int i = 2; i <= n; i+=2) {
            now += a[i - 1];
            now -= a[i - 2];
            prefmax1[i] = now;
        }
        now = 0;
        for(int i = 3; i <= n; i+=2) {
            now -= a[i - 1];
            now += a[i - 2];
            prefmax2[i] = now;
        }
        ll ans = sum;
        ll max1 = -1000000000000000000ll;
        ll max2 = -1000000000000000000ll;
        for(int i = n - 1; i >= 0; i--) {
            if(i % 2 == 0 && i != n - 1) {
                ans = max(ans, sum + max1 - prefmax1[i]);
            } else if(i % 2 == 1 && i != n - 1) {
                ans = max(ans, sum + max2 - prefmax2[i]);
            }
            if(i % 2 == 0) {
                max2 = max(max2, prefmax2[i + 1]);
            } else {
                max1 = max(max1, prefmax1[i + 1]);
            }
        }
        cout << ans << '\n';
    }

}