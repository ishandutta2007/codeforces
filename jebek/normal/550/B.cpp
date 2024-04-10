#include <iostream>
#include<algorithm>

using namespace std;

int n,l,r,x,a[20],MIN,MAX,sum,ans;

int main()
{
    cin>>n>>l>>r>>x;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<(1<<n);i++)
    {
        if(__builtin_popcount(i)<2)
            continue;
        MIN=2000000000,MAX=sum=0;
        for(int j=0;j<n;j++)
            if(i&(1<<j))
            {
                MIN=min(MIN,a[j]);
                MAX=max(MAX,a[j]);
                sum+=a[j];
            }
        if(MAX-MIN>=x && l<=sum && sum<=r)
            ans++;
    }
    cout<<ans<<endl;
}