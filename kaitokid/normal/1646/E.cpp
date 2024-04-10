#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll p[1000009];
int ans[69];
bool bl[69000009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(ll i=2;i<=1000000;i++)
    {
        if(p[i]>0)continue;
        int u=1;
        ll q=i;
        while(q<=1000000)
        {
            if(p[q]==0)p[q]=u;
            u++;
            q*=i;
        }

    }
   cin>>n>>m;

   for(int i=1;i<=60;i++)
   {
       for(int j=1;j<=m;j++)
       {
           if(bl[i*j])continue;
           ans[i]++;

           bl[i*j]=true;
       }
   }
   if(m==1){cout<<n;return 0;}
   ll res=1;
   for(ll i=2;i<=n;i++)
   {
       ll u=p[i];
       res+=ans[u];
     }
   cout<<res<<endl;

    return 0;
}