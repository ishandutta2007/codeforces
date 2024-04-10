#include <bits/stdc++.h>

using namespace std;
long long n,k,t[200001],i,h[200001],l=0,g[200001],an=1,s=0,su=0,w=0;
int main()
{
     cin>>n>>k;
     for(i=0;i<n;++i)
     {
        cin>>t[i];
        if(t[i]>=0)
            h[i]=0;
        else
         {
             h[i]=1;w++;
         }
     }
     if(w>k) {cout<<-1;exit(0);}
     i=0;t[n]=-1;
     while(t[i++]>=0);
     if(i==n+1) {cout<<0;exit(0);}
     for(;i<n;++i)
     {
         if(h[i]==1 && l>0) {g[s++]=l;l=0;}
         else if(h[i]==0) l++;
     }
     i=0;
     while(t[i++]>=0);
     for(;i<n;++i)
     {
         if(h[i]!=h[i-1]) an++;
     }
     sort(g,g+s);
     g[s]=1000000007;
     for(i=0;i<=s;++i)
        {su+=g[i];
     if(su>k-w)break;}
     if(k-w-su+g[i]>=l && l!=0) an--;
     an=an-2*(i);
     cout<<an;
     return 0;
}