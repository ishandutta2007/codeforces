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
        string s;
        cin >> s;
        int prev = -1;
        int res = 0;
        int amfir = -1;
        for(int i = 0; i < n; i++) {
            if(i == n || s[i] == '1') {
                if(prev == -1) {
                    prev = i;
                    amfir = i;
                    continue;
                }
                int am = i - prev - 1;
                if(am > k) {
                    res += (am - k) / (k + 1);
                }
                prev = i;
            }
        }
        if(amfir == -1) {
            res += 1 + (n - 1) / (k + 1);
        } else {
            res += amfir / (k + 1);
            res += (n - 1 - prev) / (k + 1);
        }
        cout << res << '\n';
    }
}