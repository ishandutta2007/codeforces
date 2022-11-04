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
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] < l || a[i] > r) {
                continue;
            }
            if(k >= a[i]) {
                k -= a[i];
                ++ans;
            }
        }
        cout << ans << '\n';
    }
}