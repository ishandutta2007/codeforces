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
        int n, x;
        cin >> n >> x;
        vi a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        int now = 0;
        for(int i = n - 1; i >= 0; i--) {
            ++now;
            if((ll)now * a[i] >= x) {
                ++ans;
                now = 0;
            }
        }
        cout << ans << '\n';
    }
}