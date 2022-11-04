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
        int ans = 0;
        for(int l = 0; l < n; l++) {
            for(int r = l; r < n; r++) {
                for(int i = l; i <= r; i++) {
                    if(a[i] == 0) {
                        ans += 2;
                    } else {
                        ++ans;
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}