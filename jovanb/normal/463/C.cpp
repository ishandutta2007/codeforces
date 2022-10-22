#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mat[3000][3000];
ll d1[10000];
ll d2[10000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> mat[i][j];
            d1[i-j+n] += mat[i][j];
            d2[i+j] += mat[i][j];
        }
    }
    ll max1 = -1, max2 = -1;
    int maxi1=0, maxj1=0, maxi2=0, maxj2=0;
    int orgcol=0;
    int col;
    for(int i=1; i<=n; i++){
        orgcol = 1-orgcol;
        col = orgcol;
        for(int j=1; j<=n; j++){
            if(col == 1 && d1[i-j+n]+d2[i+j]-mat[i][j] > max1){
                max1 = d1[i-j+n]+d2[i+j]-mat[i][j];
                maxi1 = i;
                maxj1 = j;
            }
            if(col == 0 && d1[i-j+n]+d2[i+j]-mat[i][j] > max2){
                max2 = d1[i-j+n]+d2[i+j]-mat[i][j];
                maxi2 = i;
                maxj2 = j;
            }
            col = 1-col;
        }
    }
    cout << max1+max2 << "\n";
    cout << maxi1 << " " << maxj1 << " " << maxi2 << " " << maxj2 << "\n";
    return 0;
}