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
        vi a(3);
        for(int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if(a[0] + a[1] == a[2]) {
            cout << "YES\n";
            continue;
        }
        if(a[0] == a[1]) {
            if(a[2] % 2 == 0) {
                cout << "YES\n";
                continue;
            }
        }
        if(a[1] == a[2]) {
            if(a[0] % 2 == 0) {
                cout << "YES\n";
                continue;
            }
        }
        cout << "NO\n";
    }
}