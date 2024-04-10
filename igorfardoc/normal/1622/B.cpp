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
        vi p(n);
        for(int i = 0; i < n; i++) {
            cin >> p[i];
        }
        string s;
        cin >> s;
        int am1 = 0;
        for(int i = 0; i < n; i++) {
            am1 += s[i] == '1';
        }
        int am0 = n - am1;
        int now0 = 1;
        int now1 = am0 + 1;
        vi where(n + 1);
        for(int i = 0; i < n; i++) {
            where[p[i]] = i;
        }
        vi ans(n);
        for(int i = 1; i <= n; i++) {
            if(s[where[i]] == '1') {
                ans[where[i]] = now1++;
            } else {
                ans[where[i]] = now0++;
            }
        }
        for(const auto& el : ans) {
            cout << el << ' ';

        }
        cout << '\n';
    }
}