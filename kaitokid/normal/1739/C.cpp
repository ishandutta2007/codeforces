#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll c[66][66];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    c[0][0]=1;
    for(int i=1;i<=62;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
    }
    int t;
    cin>>t;
    while(t--)
    {
       int n;
       cin>>n;
       ll g1=0,g2=0;
       for(int i=1;i<=n/2;i++)
       {
           ll d=c[2*(n/2-i)+1][n/2-i];
           ll v=c[2*(n/2-i)][n/2-i+1];
           if((i%2)==0)swap(d,v);
            g1=(g1+d)%mod;
            g2=(g2+v)%mod;
       }
       cout<<g1<<" "<<g2<<" "<<1<<endl;
    }
    return 0;
}