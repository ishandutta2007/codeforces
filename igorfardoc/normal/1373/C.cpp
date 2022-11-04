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
        string s;
        cin >> s;
        int min1 = 0;
        int now = 0;
        ll res = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '+') {
                ++now;
            } else {
                --now;
            }
            if(now < 0 && now < min1) {
                res += (ll)(i + 1) * (min1 - now);
                min1 = now;
            }
        }
        cout << res + s.size() << '\n';
    }
        
}