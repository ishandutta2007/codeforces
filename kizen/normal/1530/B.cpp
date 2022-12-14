#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                int f = 0;
                if(n % 2 == 1 && m % 2 == 1) f = (i % 2 && j % 2);
                else if(n % 2 == 1 && m % 2 == 0){
                    if(i != 1 || i != n) f = (i % 2);
                    if(i == 1) f = (j % 2);
                    if(i == n) f = ((m - j + 1) % 2);
                }
                else if(n % 2 == 0 && m % 2 == 1){
                    if(j != 1 || j != m) f = (j % 2);
                    if(j == 1) f = (i % 2);
                    if(j == m) f = ((n - i + 1) % 2);
                }
                else{
                    if(i == 1) f = (j % 2);
                    else if(i == n) f = (j != m && j % 2 == 0);
                    else if(j == 1) f = (i > 2 && i % 2 == 0);
                    else f = i % 2;
                }
                if(!(i == 1 || i == n || j == 1 || j == m)) f = 0;
                cout << f;
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}