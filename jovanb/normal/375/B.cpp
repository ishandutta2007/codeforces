#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mat[5005][5005];
int desno[5005][5005];
int niz[10000];

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);
    cout.precision(0);
    cout<<fixed;

    int n, m;
    cin >> n >> m;
    string str;
    for(int i=1; i<=n; i++){
        cin >> str;
        for(int j=1; j<=m; j++){
            mat[i][j] = str[j-1]-'0';
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=m; j>=1; j--){
            if(mat[i][j] == 0) desno[i][j] = 0;
            else desno[i][j] = desno[i][j+1]+1;
        }
    }
    int maxres=0;
    for(int x=1; x<=m; x++){
        for(int j=1; j<=n; j++){
            niz[j] = desno[j][x];
        }
        sort(niz+1, niz+1+n);
        reverse(niz+1, niz+1+n);
        for(int i=1; i<=n; i++){
            maxres = max(maxres, niz[i]*i);
        }
    }
    cout << maxres;
    return 0;
}