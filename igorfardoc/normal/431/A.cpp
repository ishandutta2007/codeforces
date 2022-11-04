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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            ans += a;
        } else if(s[i] == '2') {
            ans += b;
        } else if(s[i] == '3') {
            ans += c;
        } else {
            ans += d;
        }
    }
    cout << ans;
}