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
        int n, m;
        cin >> n >> m;
        vi am(1001, 0);
        for(int i = 0; i < n; i++) {
            int c;
            cin >> c;
            ++am[c];
        }
        int ans = -1;
        for(int i = 0; i < m; i++) {
            int c;
            cin >> c;
            if(am[c] > 0) {
                ans = c;
            }
        }
        if(ans == -1) {
            cout << "NO\n";
        } else {
            cout << "YES\n1 " << ans << '\n';
        }
    }
}