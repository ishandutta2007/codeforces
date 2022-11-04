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
        int n, m, r, c;
        cin >> n >> m >> r >> c;
        --r;
        --c;
        vector<string> a(n);
        bool thereb = false;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            for(int j = 0; j < m; j++) {
                if(a[i][j] == 'B') thereb = true;
            }
        }
        if(!thereb) {
            cout << -1 << '\n';
            continue;
        }
        if(a[r][c] == 'B') {
            cout << 0 << '\n';
            continue;
        }
        bool ok = false;
        for(int i = 0; i < n; i++) {
            if(a[i][c] == 'B') ok = true;
        }
        for(int i = 0; i < m; i++) {
            if(a[r][i] == 'B') ok = true;
        }
        if(ok) {
            cout << 1;
        } else {
            cout << 2;
        }
        cout << '\n';
    }
}