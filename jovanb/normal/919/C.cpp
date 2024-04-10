#include <bits/stdc++.h>
using namespace std;

char mat[2005][2005];
int zbirv[2005][2005], zbirh[2005][2005];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(10);
    cout<<fixed;

    int n, m, k;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++) cin >> mat[i];
    if(k==1){
        int br=0;
        for(int i=0; i<n; i++)for(int j=0; j<m; j++)if(mat[i][j] == '.') br++;
        cout << br;
        return 0;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i == 0){
                if(mat[i][j] == '.') zbirv[i][j] = 1;
                else zbirv[i][j] = 0;
            }
            else zbirv[i][j] = zbirv[i-1][j];
            if(mat[i][j] == '.') zbirv[i][j]++;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(j == 0){
                if(mat[i][j] == '.') zbirh[i][j] = 1;
                else zbirh[i][j] = 0;
            }
            else zbirh[i][j] = zbirh[i][j-1];
            if(mat[i][j] == '.') zbirh[i][j]++;
        }
    }
    int br = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i+k <= n){
                if(zbirv[i][j] == zbirv[i+k-1][j]-k+1 && mat[i][j] == '.') br++;
            }
            if(j+k <= m){
                if(zbirh[i][j] == zbirh[i][j+k-1]-k+1 && mat[i][j] == '.') br++;
            }
        }
    }
    cout << br;
    return 0;
}