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
        int n, k;
        cin >> n >> k;
        vi am(26);
        for(int i = 0; i < n; i++) {
            char c;
            cin >> c;
            am[c - 'a']++;
        }
        int am2 = 0;
        int am1 = 0;
        for(int i = 0; i < 26; i++) {
            am2 += am[i] / 2;
            am1 += am[i] % 2;
        }
        int l = 0;
        int r = n + 1;
        while(r - l > 1) {
            int mid = (l + r) / 2;
            ll needpairs = (ll)(mid / 2) * k;
            if(am2 < needpairs) {
                r = mid;
                continue;
            }
            int am21 = am2 - needpairs;
            if(mid % 2 == 0) {
                l = mid;
                continue;
            }
            int can = am21 * 2 + am1;
            if(can >= k) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << '\n';
    }
}