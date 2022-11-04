#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int mod = 1000000007;

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
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for(int i = 0; i < m; i++) {
            int l, r, x;
            cin >> l >> r >> x;
            ans |= x;
        }
        ans%=mod;
        for(int i = 0; i < n - 1; i++) {
            ans = ans * 2 % mod;
        }
        cout << ans << '\n';
    }
}