#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long n,i,a[300005],l,k,v[300005],ans[300005],f[300005]={0},last,j;
vector < pair < long ,long > > b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        b.pb({a[i],i});
    }
    if(n<3)
    {
        while(n--)
        cout<<max(a[0],a[1])<<" ";
        exit(0);
    }
    for(i=0;i<n;++i)
    {
        l=min(2*(i+1),2*(n-i));
        if(l>n) l-=2;
        k=n-l;
        if(i<=n/2)
        {
            if(a[i]>=a[i+2] && a[i]<=a[i+1])
            {
                f[i]=1;
                k--;
            }
        }
        if(i>n/2)
        {
            if(a[i]>=a[i-2] && a[i]<=a[i-1])
            {
                f[i]=1;
                k--;
            }
        }
        if(i>0 && i<n-1)
        {
            if(a[i]<=max(a[i+1],a[i-1]))
            {
                f[i]=1;
                if(n%2 && i==n/2)
                k--;
            }
        }
        if(k<0) k=0;
        v[i]=k;
    }
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    ans[n-1]=b[0].first;
    for(i=0;i<n;++i)
    {
        if(f[b[i].second])
        for(j=v[b[i].second]+1;j<n;j++,j++)
        {
            if(!ans[j])
            ans[j]=b[i].first;
            else break;
        }
        for(j=v[b[i].second];j<n;j++,j++)
        {
            if(!ans[j])
            ans[j]=b[i].first;
            else break;
        }
    }
    for(i=0;i<n;++i)
    cout<<ans[i]<<" ";
    return 0;
}