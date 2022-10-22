#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

ll mat[1005][1005];

ll koren(ll a){
    ll r = sqrtl(a);
    while(r*r < a) r++;
    while(r*r > a) r--;
    return r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> mat[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        if(i == 1){
            cout << koren(mat[i][2]*mat[i][3]/mat[2][3]) << " ";
        }
        else if(i == 2){
            cout << koren(mat[i][1]*mat[i][3]/mat[1][3]) << " ";
        }
        else cout << koren(mat[i][1]*mat[i][2]/mat[1][2]) << " ";
    }
    return 0;
}