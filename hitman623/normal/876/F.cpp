#include <bits/stdc++.h>
#define ll long long
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
unordered_map<int,int>mp;
const int N = 2e5+1;
int t[2*N],a[200005],n,i,ans1,ans2;
ll ans;

void build() { for(i=n-1;i>0;--i) t[i]=t[i<<1]|t[i<<1|1]; }

int query(int l,int r)
{
    int res = 0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if (l&1) res|=t[l++];
        if (r&1) res|=t[--r];
    }
    return res;
}

int main()
{
    io
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        t[i+n]=a[i];
    }
    ans=(1LL*n*(n-1))/2;
    build();
    for(i=0;i<n;i++)
    {
        int lo=i,hi=n-1,mid;
        while(hi-lo>1)
        {
            mid=(lo+hi)/2;
            if(query(i,mid+1)==a[i])
            lo=mid;
            else hi=mid;
        }
        if(query(i,hi+1)==a[i])
        ans1=hi-i+1;
        else ans1=lo-i+1;

        lo=mp[a[i]],hi=i,mid;
        while(hi-lo>1)
        {
            mid=(lo+hi)/2;
            if(query(mid,i+1)==a[i])
            hi=mid;
            else lo=mid;
        }
        if(query(lo,i+1)==a[i])
        ans2=i-lo+1;
        else ans2=i-hi+1;
        ans-=1LL*ans1*ans2-1;
        mp[a[i]]=i+1;
    }
    cout<<ans;
    return 0;
}