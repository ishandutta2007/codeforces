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
        ll hc, dc, hm, dm;
        cin >> hc >> dc >> hm >> dm;
        int k;
        ll w, a;
        cin >> k >> w >> a;
        bool ok = false;
        for(int i = 0; i <= k; i++) {
            ll h1 = hc + a * i;
            ll d1 = dc + w * (k - i);
            ll need1 = (hm - 1) / d1 + 1;
            ll need2 = (h1 - 1) / dm + 1;
            if(need1 <= need2) {
                ok = true;
                break;
            }
        }
        if(ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}