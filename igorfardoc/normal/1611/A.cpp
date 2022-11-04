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
        vi a;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            a.push_back(s[i] - '0');
        }
        if(a[n - 1] % 2 == 0) {
            cout << 0 << '\n';
            continue;
        }
        if(a[0] % 2 == 0) {
            cout << 1 << '\n';
            continue;
        }
        bool there2 = false;
        for(int i = 1; i < n - 1; i++) {
            if(a[i] % 2 == 0) {
                there2 = true;
                break;
            }
        }
        if(there2) {
            cout << 2 << '\n';
        } else {
            cout << "-1\n";
        }
    }
}