#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
const int N =4e6+10;
int f[N];
int c[N],n,mod;


int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    //int c1=clock();
    cin>>n>>mod;
    f[n]=1;
    for(int i=n;i>=1;i--)
    {
        f[i]=f[i]+c[i+1]-c[n+1];

        for(int j=i+1,l,r;j<=n;j=r+1)
        {
            l=j,r=(j/i+1)*i-1;
            r=min(r,n);

            f[i]=(f[i]+1ll*j/i*(c[l]-c[r+1])%mod)%mod;
        }
        for(int j=i+1,l,r;j<=n;j=r+1)
        {
            l=j,r=(j/(i+1)+1)*(i+1)-1;
            r=min(r,n);
            f[i]=(f[i]-1ll*j/(i+1)*(c[l]-c[r+1])%mod)%mod;
        }
        c[i]=(c[i+1]+f[i])%mod;
    }
    cout<<(f[1]+mod)%mod<<endl;
    //cerr << "Time Used :" << clock() - c1 << "ms" << endl;
    return 0;
}