#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[109],d[109];
int main()
{
    ios::sync_with_stdio(0);
   ll t;
   cin>>t;
   while(t--)
   {
       ll k,n;
       for(int i=0;i<109;i++)d[i]=0;
       cin>>n>>k;
       vector<int>u;
       for(int i=0;i<n;i++)
       {
           cin>>a[i];
           d[a[i]]++;
           if(d[a[i]]==1)u.push_back(a[i]);
       }
       if(u.size()>k){cout<<-1<<endl;continue;}
while(u.size()<k)u.push_back(1);
      ll ans=k*n;
       cout<<ans<<endl;
       for(int i=0;i<n;i++)
        for(int j=0;j<u.size();j++)cout<<u[j]<<" ";
       cout<<endl;
   }
   return 0;
}