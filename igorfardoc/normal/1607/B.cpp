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
        ll x, n;
        cin >> x >> n;
        ll now = x;
        for(ll i = n / 4 * 4 + 1; i <= n; i++) {
            if(now % 2 == 0) {
                now -= i;
            } else {
                now += i;
            }
        }
        cout << now << '\n';
    }
}