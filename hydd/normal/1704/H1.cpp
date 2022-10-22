#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,Mod; ll pw[5100][5100],fac[5100],C[5100][5100];
int main(){
    cin>>n>>Mod;
    if (n==1){
        cout<<"0\n";
        return 0;
    }
    C[0][0]=1; fac[0]=1;
    for (int i=1;i<=n;i++){
        C[i][0]=1; fac[i]=fac[i-1]*i%Mod; pw[i][0]=1;
        for (int j=1;j<=n;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod,pw[i][j]=pw[i][j-1]*i%Mod;
    }
    ll ans=0;
    for (int i=1;i<=n;i++)//Dead (Number of links)
        for (int j=0;j<=n;j++){//Number of B_i=A_i, B_j!=A_i(j!=i)
            int k=n-i-j; if (k<i) break;
            ll r1=C[n][i]*C[n-i][j]%Mod*fac[k]%Mod;
            ll r2=pw[n-1][i]*pw[k-j+j][j]%Mod*C[k-1][i-1]%Mod;
            ans=(ans+r1*r2)%Mod;
        }
    cout<<ans<<'\n';
    return 0;
}