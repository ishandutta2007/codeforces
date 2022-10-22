#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,ans[10009];
int main()
{
    ios::sync_with_stdio(0);
   ll t;
   cin>>t;
   while(t--)
   {
    cin>>n;
    ans[0]=1;
    ll sum=n-1;

    int i=1;
    while(sum>0)
    {
        ll p=min(sum,2*ans[i-1]);
        ans[i]=p;
        sum-=p;
        i++;
    }
sort(ans+1,ans+i);
cout<<i-1<<endl;
for(int j=1;j<i;j++)cout<<ans[j]-ans[j-1]<<" ";
cout<<endl;
   }
   return 0;
}