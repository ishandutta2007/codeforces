#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool pr[1000009];
int a[200009],pf[200009],suf[200009];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    pr[1]=true;
    for(int i=2;i<1000;i++)
    {
        if(pr[i])continue;
        for(int j=i*i;j<=1000000;j+=i)pr[j]=true;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int n,e;
        cin>>n>>e;
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
           pf[i]=suf[i]=0;
       }
       for(int i=0;i<n;i++)
       {
           if(i>=e)pf[i]+=pf[i-e];
           if(a[i]==1)pf[i]++;else pf[i]=0;
       }
       for(int i=n-1;i>=0;i--)
       {
           if(i+e<n)suf[i]=suf[i+e];
           if(a[i]==1)suf[i]++;
           else suf[i]=0;
       }
       ll ans=0;
     for(int i=0;i<n;i++)
     {
         if(pr[a[i]])continue;
         int u=0,v=0;
         if(i>=e)u=pf[i-e];
         if(i+e<n)v=suf[i+e];
         u++;
         v++;
         ans+=u*1LL*v-1;

     }
     cout<<ans<<endl;

    }
    return 0;
}