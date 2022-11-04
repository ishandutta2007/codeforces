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
        int l, r, k;
        cin >> l >> r >> k;
        int amnechet = 0;
        int amchet = 0;
        if((r - l + 1) % 2 == 0) {
            amchet = (r - l + 1) / 2;
        } else if(l % 2 == 0) {
            amchet = (r - l) / 2 + 1;
        } else {
            amchet = (r - l + 1) / 2;
        }
        amnechet = r - l + 1 - amchet;
        if((r == l && l != 1) || amnechet <= k) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}