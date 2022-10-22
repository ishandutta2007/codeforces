#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mx[5009];
int a[5009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {

     int n,x;
     cin>>n>>x;
     for(int i=0;i<n;i++)cin>>a[i];
     for(int i=1;i<=n;i++)mx[i]=INT_MIN;
     for(int i=0;i<n;i++)
     {
         int s=0;
         for(int j=i;j<n;j++){s+=a[j];mx[j-i+1]=max(mx[j-i+1],s);}
     }
     for(int i=0;i<=n;i++)
     {
         int ans=INT_MIN;
         for(int j=0;j<=n;j++)ans=max(ans,mx[j]+min(i,j)*x);
         cout<<ans<<" ";
     }
     cout<<endl;

    }
    return 0;
}