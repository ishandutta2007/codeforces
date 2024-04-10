#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[10];
int dp[305][305];

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> niz[i];
    if(n == 1){
        if(niz[1]) cout << "BitLGM\n";
        else cout << "BitAryo\n";
        return 0;
    }
    if(n == 2){
        for(int i=0; i<=niz[1]; i++){
            for(int j=0; j<=niz[2]; j++){
                for(int x=i-1; x>=0; x--){
                    if(!dp[x][j]) dp[i][j] = 1;
                }
                for(int x=j-1; x>=0; x--){
                    if(!dp[i][x]) dp[i][j] = 1;
                }
                for(int x=min(i, j); x>=1; x--){
                    if(!dp[i-x][j-x]) dp[i][j] = 1;
                }
            }
        }
        if(dp[niz[1]][niz[2]]) cout << "BitLGM\n";
        else cout << "BitAryo\n";
        return 0;
    }
    if(niz[1] ^ niz[2] ^ niz[3]) cout << "BitLGM\n";
    else  cout << "BitAryo\n";
    return 0;
}