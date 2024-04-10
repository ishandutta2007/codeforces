#include <bits/stdc++.h>

using namespace std;
int n,k,an1,an2,p1,p2,ans,u,v;
int main()
{
ios::sync_with_stdio(0);
cin>>n>>k;
cout<<"? ";
for(int i=1;i<=k;i++)cout<<i<<" ";
cout<<endl;
fflush(stdout);
cin>>p1>>an1;
cout<<"? ";
for(int i=1;i<=k+1;i++)if(i!=p1)cout<<i<<" ";
cout<<endl;
  fflush(stdout);
  cin>>p2>>an2;
   for(int i=1;i<=k+1;i++)
   {
       if(i==p1||i==p2)continue;
       cout<<"? ";
       for(int j=1;j<=k+1;j++)if(j!=i)cout<<j<<" ";
       cout<<endl;
       fflush(stdout);
       cin>>u>>v;
       if(u!=p2)ans++;
   }
   if(an1>an2)
   cout<<"! "<<ans+1<<endl;
   else cout<<"! "<<k-ans<<endl;
   fflush(stdout);
    return 0;
}