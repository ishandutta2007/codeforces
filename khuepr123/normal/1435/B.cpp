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
#define int long long
const ll mod = 1e9 + 7;
const int maxN = 505;
const ll oo = 1e18 + 7;
int n,m; int a[maxN][maxN]; int b[maxN][maxN]; int mincol[maxN];
pair<int, int> mycol[maxN]; int mincol2[maxN]; pair<int, int> mycol2[maxN];
int rl[maxN][maxN];



signed main(){
    ios_base::sync_with_stdio(0);
    int o; cin >> o;
    while(o--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){ // col are consistent index
                cin >> a[i][j];
                mincol[j] = mod * mod;
            }
        }
        for(int j = 1; j <= m; j++){
            for(int i = 1; i <= n; i++){
                mincol[j] = min(mincol[j], a[i][j]);
            }
        }
        for(int j = 1; j <= m; j++){
            mycol[j].fi = mincol[j]; mycol[j].se = j;
        }
        sort(mycol + 1, mycol + m + 1);
        for(int j = 1; j <= m; j++){
            for(int i = n; i > 0; i--){
                cin >> b[i][j]; // row are consistent index
            }
        }
        
        for(int j = 1; j <= m; j++){
            mincol2[j] = mod * mod;
            for(int i = 1; i <= n; i++){
                mincol2[j] = min(mincol2[j], b[i][j]);
            }
        }
        for(int j = 1; j <= m; j++){
            mycol2[j].fi = mincol2[j]; mycol2[j].se = j;
        }sort(mycol2 + 1, mycol2 + m + 1);
        for(int j = 1; j <= m; j++){
            int x = mycol[j].se; int y = mycol2[j].se; // from 1 to n
            // x is poition of column; y is infomation
            for(int i = 1; i <= n; i++){
                rl[i][x] = b[i][y];
            }
        }
        for(int i = n; i > 0; i--){
            for(int j = 1; j <= m; j++){
                cout << rl[i][j] << " ";
            }
            cout << endl;
        }
    }
}