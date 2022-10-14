#include <bits/stdc++.h>

using namespace std;
int n,a[200000],m,k,ans=361,sum1,sum2;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i],a[i+n]=a[i];
    if(n==1)return cout<<"360",0;
    for(int i=0;i<n;i++)
    {    sum1=360;sum2=0;
        for(int j=i;j<n+i;j++)
        {
            sum2+=a[j];sum1-=a[j];
            ans=min(ans,abs(sum2-sum1));
        }
    }
    cout<<ans;
    return 0;
}