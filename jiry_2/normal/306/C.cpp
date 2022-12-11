#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int C[8001][6001],mo=1e9+9,n,w,b,A[8001],m,I[8001];
int main(){
    scanf("%d%d%d",&n,&b,&w);
    for (int i=0;i<=w+b;i++){
        C[i][0]=1;
        for (int j=1;j<=n;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
    }
    I[0]=1; for (int i=1;i<=w+b;i++) I[i]=1ll*i*I[i-1]%mo; m=max(w,b);
    for (int i=1;i<=n;i++) A[i]=1ll*C[w-1][i-1]*I[w]%mo;
//  for (int i=1;i<=n;i++) cout<<A[i]<<" "; cout<<endl;
    int ans=0;
//  for (int i=1;i<=n;i++)
//      for (int j=1;j<=n-i-1;j++) cout<<i<<" "<<j<<" "<<I[b]*C[i+j-1][b-2]%mo<<endl;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n-i-1;j++)
            ans=(ans+1ll*I[b]*C[b-1][i+j-1]%mo*A[n-i-j])%mo;
    cout<<ans<<endl; return 0;
}