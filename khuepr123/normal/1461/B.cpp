#include<bits/stdc++.h>
using namespace std;

#define sadasdads long long
#define pb push_back
#define fi first
#define se second
#define fir fi.fi
#define sec fi.se
#define endl "\n"
#define PI 3.141592653589793238462643383279502884
#define ll long long
const ll mod = 1e9 + 7;
const int maxN = 100005;
const ll oo = 1e18 + 7;
int n, m; char a[505][505];
int dp[505][505];
int reper[505][505];
int cnt;
// step and coordinate

signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> m; cnt = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){ cin >> a[i][j];
            if(a[i][j] == '*'){ dp[i][j] = 1; cnt++;}
            else dp[i][j] = 0;
            }
        }
        for(int dis = 1; dis < n; dis++){
            // distance from top to down
            for(int i = 1; i <= n - dis + 1; i++){
                for(int j = dis; j <= m - dis + 1; j++){
                    if(
                    dp[i][j] && 
                    dp[i + 1][j] && 
                    dp[i + 1][j + 1] && 
                    dp[i + 1][j - 1] 
                    ){
                        reper[i][j] = 1; cnt++;
                    }
                    else reper[i][j] = 0;
                }
            }
            for(int i = 1; i <= n - dis + 1; i++){
                for(int j = dis; j <= m - dis + 1; j++){
                    dp[i][j] = reper[i][j];
                }
            }
            
        }
        cout << cnt << endl;
    }
}