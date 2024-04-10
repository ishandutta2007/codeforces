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
        vi am(26);
        for(int i = 0; i < 26; i++) {
            am[s[i] - 'a'] = i;
        }
        cin >> s;
        int ans = 0;
        for(int i = 0; i < s.size() - 1; i++) {
            ans += abs(am[s[i] - 'a'] - am[s[i + 1] - 'a']);
        }
        cout << ans << '\n';
    }
}