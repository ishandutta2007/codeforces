#include <bits/stdc++.h>
using namespace std;

int niz2[105];
int niz1[105];
int niz[105];
int dp[105][105][105];
bool reachable[105][105][105];
int used[105];


int main(){

    int n, m, n1 = 0, n2 = 0;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        string s;
        cin >> s;
        int a;
        cin >> a;
        if(s == "ATK") niz1[++n1] = a;
        else niz2[++n2] = a;
    }
    for(int i=1; i<=m; i++) cin >> niz[i];
    sort(niz+1, niz+1+m);
    sort(niz1+1, niz1+1+n1);
    sort(niz2+1, niz2+1+n2);
    reachable[1][1][1] = 1;
    int mx = 0;
    /*cout << "\nC\n";
    for(int i=1; i<=m; i++){
        cout << niz[i] << endl;
    }
    cout << "\nA\n";
    for(int i=1; i<=n1; i++){
        cout << niz1[i] << endl;
    }
    cout << "\nD\n";
    for(int i=1; i<=n2; i++){
        cout << niz2[i] << endl;
    }*/
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n1+1; j++){
            for(int k=1; k<=n2+1; k++){
                if(!reachable[i][j][k]) continue;
                dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
                reachable[i+1][j][k] = 1;
                if(j <= n1 && niz[i] >= niz1[j]){
                    reachable[i+1][j+1][k] = 1;
                    dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k]+niz[i]-niz1[j]);
                }
                if(k <= n2 && niz[i] > niz2[j]){
                    reachable[i+1][j][k+1] = 1;
                    dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k]);
                }
            }
        }
    }
    for(int i=1; i<=m+1; i++){
        for(int j=1; j<=n1+1; j++){
            for(int k=1; k<=n2+1; k++){
                if(reachable[i][j][k]) mx = max(mx, dp[i][j][k]);
            }
        }
    }
    int sum = 0;
    for(int i=1; i<=n2; i++){
        bool resio = 0;
        for(int j=1; j<=m; j++){
            if(resio) break;
            if(used[j]) continue;
            if(niz[j] > niz2[i]){
                resio = 1;
                used[j] = 1;
            }
        }
        if(!resio){cout << mx; return 0;}
    }
    for(int i=1; i<=n1; i++){
        bool resio = 0;
        for(int j=1; j<=m; j++){
            if(resio) break;
            if(used[j]) continue;
            if(niz[j] >= niz1[i]){
                resio = 1;
                used[j] = 1;
                sum += niz[j]-niz1[i];
            }
        }
        if(!resio){cout << mx; return 0;}
    }
    for(int i=1; i<=m; i++) sum += (1-used[i])*niz[i];
    cout << max(mx, sum);
    return 0;
}