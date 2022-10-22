#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ans[10000009];
int pr[10000009];
ll go(int x)
{
    ll res=1;
    while(x>1)
    {
        int p=pr[x];
        ll s=1;
        ll w=p;
       while(x%p==0){s+=w;x/=p;w*=p;}
      res*=s;
    }
   return res;
}
int main()
{
ios::sync_with_stdio(0);
ans[1]=1;
for(int i=2;i<4000;i++)
{
    if(pr[i]!=0)continue;
    for(int j=i*i;j<=10000000;j+=i)pr[j]=i;
}
for(int i=2;i<=10000000;i++)
{
    if(pr[i]==0)pr[i]=i;
    ll u=go(i);
    if(u<=10000000&&ans[u]==0)ans[u]=i;
}

 int t;
 cin>>t;
 while(t--)
 {
     int x;
     cin>>x;
     if(ans[x]==0)cout<<-1<<endl;
     else cout<<ans[x]<<endl;
 }
    return 0;
}