#include <bits/stdc++.h>

#define DMAX 500005
#define pb push_back
using namespace std;

int n, s;
long long a[DMAX];

long long sol2[DMAX];

int main()
{
cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }

    if(a[n]%3!=0)
    {
        cout<<0;
        return 0;
    }
    long long k=a[n]/3;
     if(a[n]==0)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        if(a[i]==0)
            cnt++;
            cnt--;
        cout<<1LL*cnt*(cnt-1)/2;
        return 0;
    }

    int k2=0;
    long long ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]==k)
        ans+=1LL*k2;
        if(a[i]==2*k)
            k2++;
    }
    cout<<ans;

    return 0;
}