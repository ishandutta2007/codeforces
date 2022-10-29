#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long n,m,q,a[100005],b[100005],f[100005],aa=0,t=1,bb=0,ans=1e16,l,r,i,x,mn=1e16,mx=-1e16,cur=0,ub;
int main()
{
    io
    cin>>n>>m>>q;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        aa+=t*a[i];
        t*=-1;
    }
    t=1;
    for(i=0;i<m;++i)
    {
        cin>>b[i];
        if(i<n)
        bb+=t*b[i];
        t*=-1;
    }
    f[0]=bb;
    for(i=1;i<=m-n;i++)
    {
        f[i]=-f[i-1]+b[i-1];
        if(n%2==0) f[i]-=b[i+n-1];
        else f[i]+=b[i+n-1];
    }
    for(i=0;i<=m-n;++i)
    {
        f[i]=aa-f[i];
        mn=min(mn,f[i]);
        mx=max(mx,f[i]);
        ans=min(ans,abs(f[i]));
    }
    sort(f,f+m-n+1);
    cout<<ans<<endl;
    while(q--)
    {
        cin>>l>>r>>x;
        l--,r--;
        if((r-l+1)%2)
        {
            if(r%2==0)
            cur+=x;
            else cur-=x;
            ans=1e16;
            ub=upper_bound(f,f+m-n+1,-cur)-f;
            if(ub!=0)
            ans=min(ans,abs(f[ub-1]+cur));
            if(ub!=m-n+1)
            ans=min(ans,abs(f[ub]+cur));
        }
        cout<<ans<<endl;
    }
    return 0;
}