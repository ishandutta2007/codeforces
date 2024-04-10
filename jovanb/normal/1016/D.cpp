#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


ll row[1000];
ll col[1000];
ll mat[105][105];
ll rcol[1000];
ll rrow[1000];

ll x;

int n, m;

void solve(){
    ll sumv=0, sumh=0;
    for(int i=1; i<n; i++){
        if(rrow[i]){sumv ^= 1; mat[i][m] += x;}
    }
    for(int i=1; i<m; i++){
        if(rcol[i]){sumh ^= 1; mat[n][i] += x;}
    }

    if(sumv != sumh && rrow[n] == rcol[m]){cout << "NO"; exit(0);}
    if(sumv == sumh && rrow[n] != rcol[m]){cout << "NO"; exit(0);}
    if(sumh != rrow[n]) mat[n][m] += x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    cin >> n >> m;
    ll maxi=0;
    for(int i=1; i<=n; i++){
        cin >> row[i];
        maxi = max(maxi, row[i]);
    }
    for(int j=1; j<=m; j++){
        cin >> col[j];
        maxi = max(maxi, col[j]);
    }
    x = 1;
    while(x <= maxi) x <<= 1;
    x >>= 1;
    while(x){
        for(int i=1; i<=n; i++){
            if(row[i] & x) rrow[i] = 1;
            else rrow[i] = 0;
        }
        for(int j=1; j<=m; j++){
            if(col[j] & x) rcol[j] = 1;
            else rcol[j] = 0;
        }
        solve();
        x >>= 1;
    }
    cout << "YES\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}