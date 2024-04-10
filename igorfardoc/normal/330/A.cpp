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
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool ok = true;
            for(int k = 0; k < n; k++) {
                if(a[k][j] == 'S') {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                ++ans;
                continue;
            }
            ok = true;
            for(int k = 0; k < m; k++) {
                if(a[i][k] == 'S') {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                ++ans;
            }
        }
    }
    cout << ans;
}