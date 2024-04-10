#include <iostream>

#define DMAX 150007

using namespace std;

int n, k, sum, ans, a[DMAX], smin;

int main()
{
    cin>>n>>k;

    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=k;i++)
        sum+=a[i];

    smin=sum;
    ans=k;

    for(int i=k+1;i<=n;i++)
    {
        sum=sum+a[i]-a[i-k];
        if(sum<smin)
            smin=sum,ans=i;
    }

    cout<<ans-k+1<<'\n';

    return 0;
}