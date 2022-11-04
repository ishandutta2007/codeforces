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
        int ans = 10000000;
        string s;
        cin >> s;
        int prev = -1;
        int b = 0;
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                if(prev == -1) {
                    prev = i;
                    b = 0;
                    c = 0;
                    continue;
                }
                if(2 > b && 2 > c) {
                    ans = min(ans, i - prev + 1);
                }
                prev = i;
                b = 0;
                c = 0;
                continue;
            }
            if(s[i] == 'b') {
                ++b;
            } else {
                ++c;
            }
        }
        int a = 0;
        b = 0;
        c = 0;
        for(int i = 0; i < n - 6; i++) {
            a = 0;
            b = 0;
            c = 0;
            for(int j = 0; j < 7; j++) {
                if(s[i + j] == 'a') {
                    ++a;
                } else if(s[i + j] == 'b') {
                    ++b;
                } else {
                    ++c;
                }
            }
            if(a > b && a > c) {
                ans = min(ans, 7);
            }
        }
        if(ans == 10000000) {
            cout << -1 << '\n';
            continue;
        }
        cout << ans << '\n';
    }
}