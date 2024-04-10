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
        int start = -1;
        string res = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                start = i;
                res += '0';
            } else {
                break;
            }
        }
        res += '0';
        int end = n;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '1') {
                end = i;
                res += '1';
            } else {
                break;
            }
        }
        if(start == n - 1 || end == 0) {
            cout << s << '\n';
            continue;
        }
        if(end == start + 1) {
            cout << s << '\n';
            continue;
        }
        cout << res << '\n';
    }
}