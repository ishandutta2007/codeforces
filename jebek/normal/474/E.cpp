#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

const long long MAXN=1000000;
long long p,p1[MAXN],p2[MAXN],MAX[MAXN],MIN[MAXN],MAX1,d,a[MAXN],ind,par[MAXN],n,ans;
vector<long long>v;

void f(long long node,long long l,long long r,long long val)
{
    if(l+1>=r)
    {
        if(val-d>=MIN[node])
            p=p1[node];
        else
            p=p2[node];
        MAX1=l;
        return;
    }
    long long mid=(l+r)/2;
    if(MAX[node*2+1]>=val+d || MIN[node*2+1]<=val-d) f(2*node+1,mid,r,val);
    else if(MAX[node*2]>=val+d || MIN[node*2]<=val-d) f(2*node,l,mid,val);
    else
    {
        p=-1;
        MAX1=0;
    }
}

void add(long long node,long long l,long long r,long long x,long long i)
{
    if(l+1>=r)
    {
        if(a[i]<MIN[node])
        {
            MIN[node]=a[i];
            p1[node]=i;
        }
        if(a[i]>MAX[node])
        {
            MAX[node]=a[i];
            p2[node]=i;
        }
        return;
    }
    long long mid=(l+r)/2;
    if(x<mid)   add(2*node,l,mid,x,i);
    else    add(2*node+1,mid,r,x,i);
    MIN[node]=min(MIN[node*2],MIN[2*node+1]);
    MAX[node]=max(MAX[node*2],MAX[2*node+1]);
}

int main()
{
    for(long long i=0;i<MAXN;i++)
        MIN[i]=1000000000000000000;
    cin>>n>>d;
    for(long long i=0;i<n;i++)
        cin>>a[i];
    if(n==1)
    {
        cout<<1<<endl<<1<<endl;
        return 0;
    }
    for(long long i=n-1;i>-1;i--)
    {
        MAX1=0;
        p=-1;
        f(1,1,n+1,a[i]);
        par[i]=p;
        add(1,1,n+1,MAX1+1,i);
        if(MAX1+1>ans)
        {
            ans=MAX1+1;
            ind=i;
        }
    }
    cout<<ans<<endl;
    for(long long i=0;i<ans;i++)
    {
        cout<<ind+1<<" ";
        ind=par[ind];
    }
    cout<<endl;
}