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
int n; int a[maxN]; bool chk[maxN];

void typre(){
    for(int i = 0; i <= n + 2; i++){
        chk[i] = 0;
    }
}


signed main(){
        ios_base::sync_with_stdio(0);
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int b[n + 5][n + 5]; int mx[n + 5][ n + 5];
        for(int i = 1; i <= n; i++){
            b[0][i] = a[i];
            mx[0][i] = a[i];
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= n - i; j++){
                b[i][j] = (b[i - 1][j] ^ b[i - 1][j + 1]);
                mx[i][j] = max({mx[i - 1][j], mx[i - 1][j + 1], b[i][j]});
            }
        }
        int o; cin >> o; int aa, bb;
        while(o--){
            cin >> aa >> bb;
            cout << mx[bb - aa][aa] << endl;
        }
    
}