#include<bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define np make_pair
#define pb push_back
#define fi first
#define se second
 
int n, m;
char a[505][505];
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    int o; cin >> o;
    while(o--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cin >> a[i][j];
            }
        }
        for(int i = 1; i <= n; i+=3){
            for(int j = 1; j <= m; j++){
                a[i][j] = 'X';
            }
        }
        for(int i = 4; i <= n; i+=3){
            for(int j = 1; j <= m; j++){
                if(a[i - 1][j + 1] != 'X' && a[i - 2][j + 1] != 'X'
                && a[i - 1][j - 1] != 'X' && a[i - 2][j - 1] != 'X'){
                    a[i - 1][j] = 'X';
                    a[i - 2][j] = 'X';
                    break;
                }
            }
        }
        if(n % 3 == 0){
            for(int j = 1; j <= m; j++){
                if(a[n][j] == 'X') a[n - 1][j] = 'X';
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cout << a[i][j];
            }
            cout << endl;
        }
    }
}