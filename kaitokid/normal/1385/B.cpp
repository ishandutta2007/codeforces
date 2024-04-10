#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool vis[55];
int main()
{
ios::sync_with_stdio(0);
int t,n,x;
cin>>t;
while(t--)
{

   cin>>n;
   for(int i=1;i<=n;i++)vis[i]=false;
   for(int i=0;i<2*n;i++)
   {
       cin>>x;
       if(!vis[x])cout<<x<<" ";
       vis[x]=true;
   }
   cout<<endl;

}
    return 0;
}