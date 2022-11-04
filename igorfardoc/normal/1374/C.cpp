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
        int min1 = 1;
        int now = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                ++now;
            } else {
                --now;
            }
            min1 = min(now, min1);
        }
        cout << max(0, -min1) << '\n';
    }
}