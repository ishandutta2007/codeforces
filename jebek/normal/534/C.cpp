#include <iostream>
#include<algorithm>

using namespace std;

long long n,sum,sum1,ans,a[300000];

int main()
{
    cin>>n>>sum;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum1+=a[i];
    }
    for(int i=0;i<n;i++)
    {
        ans=0;
        if(sum1-a[i]+1<sum)
            ans=sum-sum1+a[i]-1;
        if(n-1+a[i]>sum)
            ans+=a[i]-(sum-n+1);
        cout<<ans<<" ";
    }
    cout<<endl;
}