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
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(n == 1) {
            cout << s << s << '\n';
            continue;
        }
        if(s[0] == s[1]) {
            cout << s[0] << s[0] << '\n';
            continue;
        }
        string ans = "";
        ans += s[0];
        int end = 0;
        for(int i = 1; i < n; i++) {
            if(s[i] <= s[i - 1]) {
                ans += s[i];
                end = i;
            } else {
                break;
            }
        }
        for(int i = end; i >= 0; i--) {
            ans += s[i];
        }
        cout << ans << '\n';
    }
}