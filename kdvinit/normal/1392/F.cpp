/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
using namespace std;

bool check(long long int a[],long long int n)
{
    for(long long int i=1;i<=n;i++)
    {
        if(a[i]>=2) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    long long int n;
    cin>>n;

    long long int h[n+1];
    for(long long int i=1;i<=n;i++) cin>>h[i];

    long long int diff[n];
    for(long long int i=1;i<n;i++)
    {
        diff[i]=h[i+1]-h[i];
    }

    long long int ans1=0,ans2=0,sumn=((n)*(n-1))/2;
    for(long long int i=1;i<n;i++)
    {
        ans1+=(i*diff[i]);
        ans2+=((n-i)*diff[i]);
    }

    if(ans1<=sumn || ans2<=sumn)
    {
        while(check(diff,n-1))
        {
            long long int cnt[n+1]={0};
            for(long long int i=1;i<n;i++)
            {
                if(diff[i]>=2)
                {
                    cnt[i]-=2;
                    cnt[i+1]+=1;
                    cnt[i-1]+=1;
                }
            }
            for(long long int i=1;i<n;i++) diff[i]+=cnt[i];
        }
    }
    else
    {
        long long int x;

        ans2-=sumn;
        x=ans2%n;

        for(long long int i=1;i<n;i++) diff[i]=1;
        diff[x]=0;
    }

    diff[0]=0;
    long long int a[n+1];
    a[0]=0;
    for(long long int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+diff[i-1];
    }

    long long int y=0;
    for(long long int i=1;i<=n;i++) y+=a[i];

    long long int z=0;
    for(long long int i=1;i<=n;i++) z+=h[i];

    z-=y;
    z/=n;

    for(long long int i=1;i<=n;i++) cout<<z+a[i]<<" ";
    cout<<endl;

    return 0;
}