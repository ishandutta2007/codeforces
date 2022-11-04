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
        int a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll res = min((ll)a * max(y, b - n), (ll)b * max(x, a - n));
        if(a - x < n) {
            res = min(res, (ll)x * max(y, b - (n - (a - x))));
        }
        if(b - y < n) {
            res = min(res, (ll)y * max(x, a - (n - (b - y))));
        }
        cout << res << '\n';
    }
}