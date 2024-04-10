#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll niz[100];
int n, k;
bool dp[100][100];

bool moze(ll br){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++) dp[i][j] = 0;
    }
    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        ll zbir=niz[i];
        for(int j=i-1; j>=0; j--){
            for(int x=0; x<k; x++){
                if(dp[j][x]){
                    if(!((zbir & br)^br)) dp[i][x+1] = 1;
                }
            }
            zbir += niz[j];
        }
    }
    return dp[n][k];
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> niz[i];
    ll x = 1LL << 60;
    ll res=0;
    while(x){
        if(moze(res+x)) res += x;
        x >>= 1;
    }
    cout << res;
    return 0;
}