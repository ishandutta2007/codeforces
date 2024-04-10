#include <bits/stdc++.h>
using namespace std;

long long mat[100][100];
long long niz[100];
long long dp[(long long)(pow(2,20))][20];
long long longpow[20];
int main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long long n,m,k,x,y,z,i,mask,j;
    cin>>n>>m>>k;
    longpow[0]=1;
    for(i=1;i<=n;i++)longpow[i]=longpow[i-1]*2;
    for(i=0;i<n;i++){
        cin>>niz[i];
        dp[longpow[i]][i]=niz[i];
    }
    for(i=0;i<k;i++){
        cin>>x>>y>>z;
        mat[x-1][y-1]=z;
    }
    for(mask=0; mask<longpow[n]; mask++){
        for(j=0; j<n; j++){
            if(longpow[j] & mask){
                for(i=0; i<n; i++){
                    if((mask&longpow[i])==0){
                        dp[longpow[i] | mask][i]=max(dp[longpow[i] | mask][i],dp[mask][j]+niz[i]+mat[j][i]);
                    }
                }
            }
        }
    }
    long long maxi=0;
    for(mask=0; mask<longpow[n]; mask++){
        if(__builtin_popcountll(mask)==m){
            for(i=0; i<n; i++){
                maxi=max(maxi,dp[mask][i]);
            }
        }
    }
    cout<<maxi;
    return 0;
}