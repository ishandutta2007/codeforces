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
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char c;
                cin >> c;
                if(i < n - 1 && j < m - 1) {
                    continue;
                }
                if(i == n - 1 && j == m - 1) {
                    continue;
                }
                if((i == n - 1 && c == 'D') || (j == m - 1 && c == 'R')) {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}