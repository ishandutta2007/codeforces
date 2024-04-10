#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;

ll res, k;

ll mat[25][25];

map <ll, ll> br[25];

void gen1(int i, int j, ll val){
    val ^= mat[i][j];
    if(i-1+j-1 == (n+m-2)/2){
        br[i][val]++;
        return;
    }
    if(i < n) gen1(i+1, j, val);
    if(j < m) gen1(i, j+1, val);
}

void gen2(int i, int j, ll val){
    val ^= mat[i][j];
    if(i-1+j-1 == (n+m-2)/2+1){
        res += br[i-1][k^val] + br[i][k^val];
        return;
    }
    if(i > 1) gen2(i-1, j, val);
    if(j > 1) gen2(i, j-1, val);
}

int main(){

    cin >> n >> m;
    cin >> k;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> mat[i][j];
        }
    }
    if(n == 1 && m == 1){
        cout << (mat[1][1] == k);
        return 0;
    }
    gen1(1, 1, 0);
    gen2(n, m, 0);
    cout << res;
    return 0;
}