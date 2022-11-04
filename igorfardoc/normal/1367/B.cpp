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
        vi a(n);
        int am0 = 0;
        int am1 = 0;
        int a0 = 0;
        int a1 = 0;
        int badpos = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                ++a0;
            } else {
                ++a1;
            }
            cin >> a[i];
            if(a[i] % 2 == 0) {
                ++am0;
            } else {
                ++am1;
            }
            if(i % 2 != a[i] % 2) {
                ++badpos;
            }
        }
        if(am0 != a0) {
            cout << -1 << '\n';
            continue;
        }
        cout << badpos / 2 << '\n';
    }
}