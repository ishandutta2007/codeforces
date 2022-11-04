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
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        int ans = 0;
        int can = min(z1, y2);
        z1 -= can;
        y2 -= can;
        ans += 2 * can;
        ans -= 2 * max(0, z2 - x1 - z1);
        cout << ans << '\n';
    }
}