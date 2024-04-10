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
        int n, m;
        cin >> n >> m;
        bool ok = true;
        vvi a(n, vi(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i][j];
                int max1 = 4;
                int am = 0;
                if(i == 0 || i == n - 1) {
                    ++am;
                }
                if(j == 0 || j == m - 1) {
                    ++am;
                }
                max1 -= am;
                if(max1 < a[i][j]) {
                    ok = false;
                }
                a[i][j] = max1;
            }
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
    }
}