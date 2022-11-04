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
        int minx = 0;
        int maxx = 0;
        int miny = 0;
        int maxy = 0;
        string s;
        cin >> s;
        int x = 0;
        int y = 0;
        int resx = 0;
        int resy = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'U') {
                --x;
            } else if(s[i] == 'D') {
                ++x;
            } else if(s[i] == 'R') {
                ++y;
            } else {
                --y;
            }
            int miny1 = min(miny, y);
            int maxy1 = max(maxy, y);
            int minx1 = min(minx, x);
            int maxx1 = max(maxx, x);
            if(maxx1 - minx1 >= n || maxy1 - miny1 >= m) {
                resx = -minx;
                resy = -miny;
                break;
            }
            miny = miny1;
            minx = minx1;
            maxx = maxx1;
            maxy = maxy1;
        }
        resx = -minx;
        resy = -miny;
        if(resx >= n) {
            resx = n - 1;
        }
        if(resy >= m) {
            resy = m - 1;
        }
        cout << resx + 1 << ' ' << resy + 1 << '\n';
    }
}