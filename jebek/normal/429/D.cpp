#include <iostream>
#include<algorithm>

using namespace std;

long long n,a[101000],sum[101000],ans=100000000000000000;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i!=0)
            sum[i]=sum[i-1]+a[i];
    }
    for(int i=1;i<n;i++)
        for(int j=max(0,i-1000);j<i;j++)
            ans=min(ans,(sum[i]-sum[j])*(sum[i]-sum[j])+(i-j)*(i-j));
    cout<<ans<<endl;
}