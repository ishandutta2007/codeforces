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
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vi pref(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            pref[i] = max(pref[i - 1], a[i - 1]);
        }
        int ans = 0;
        while(n > 0) {
            int now = n - 1;
            while(pref[now + 1] != a[now]) {
                --now;
            }
            if(now == n - 1) {
                ++ans;
                --n;
                continue;
            }
            int mn = 1000000;
            for(int i = now; i < n; i++) {
                mn = min(mn, a[i]);
            }
            a[now] = mn;
            pref[now + 1] = max(pref[now], a[now]);
            n = now + 1;
        }
        cout << ans << '\n';
    }
}