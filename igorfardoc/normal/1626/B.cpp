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
        int n = s.size();
        bool ok = false;
        for(int i = n - 2; i >= 0; i--) {
            int here = s[i] - '0' + s[i + 1] - '0';
            if(here >= 10) {
                for(int j = 0; j < i; j++) {
                    cout << s[j];
                }
                cout << '1';
                cout << (char)(here % 10 + '0');
                for(int j = i + 2; j < n; j++) {
                    cout << s[j];
                }
                ok = true;
                cout << '\n';
                break;
            }
        }
        if(ok) continue;
        cout << (char)(s[0] - '0' + s[1]);
        for(int i = 2; i < n; i++) {
            cout << s[i];
        }
        cout << '\n';
    }
}