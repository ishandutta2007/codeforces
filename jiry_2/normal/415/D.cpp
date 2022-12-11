#include<iostream>
#include<cstring>
using namespace std;
long long modd=1000000007,f[2010][2010],n,k;
int main()
{
    cin>>n>>k;
    memset(f,0x00,sizeof f);
    for (int i=1;i<=n;i++) f[1][i]=1;
    for (int i=2;i<=k;i++)
        for (int j=1;j<=n;j++)
            for (int k1=1;k1*j<=n;k1++)
                f[i][j*k1]=(f[i][j*k1]+f[i-1][j])%modd;
    long long ans=0;
    for (int i=1;i<=n;i++) ans=(ans+f[k][i])%modd;
    cout<<ans;
    return 0;
}