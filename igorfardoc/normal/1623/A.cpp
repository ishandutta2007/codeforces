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
        int x, y;
        cin >> x >> y;
        int r, c;
        cin >> r >> c;
        --x;
        --y;
        --r;
        --c;
        int ans = 0;
        int dx = 1;
        int dy = 1;
        while(x != r && y != c) {
            int xnew = x + dx;
            int ynew = y + dy;
            if(xnew < 0 || xnew >= n) {
                dx = -dx;
            }
            if(ynew < 0 || ynew >= m) {
                dy = -dy;
            }
            x = x + dx;
            y = y + dy;
            ++ans;
        }
        cout << ans << '\n';
    }
}