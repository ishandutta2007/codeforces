#include <iostream>
#include<algorithm>
#include<set>
#include<cstring>

using namespace std;

int MIN[600000],n,s,l,MIN1,MAX,ans,dp[200000],a[200000],p;
multiset<int>s1;

void make(int node,int l,int r)
{
    MIN[node]=1000000000;
    if(l+1>=r)
        return;
    int mid=(l+r)/2;
    make(2*node,l,mid);
    make(2*node+1,mid,r);
}

void add(int node,int l,int r,int x)
{
    if(l+1>=r)
    {
        MIN[node]=dp[x];
        return;
    }
    int mid=(l+r)/2;
    if(x<mid)   add(2*node,l,mid,x);
    else    add(2*node+1,mid,r,x);
    MIN[node]=min(MIN[2*node],MIN[2*node+1]);
}

void m(int node,int l,int r,int beg,int en)
{
    if(beg<=l && r<=en)
    {
        ans=min(ans,MIN[node]);
        return;
    }
    int mid=(l+r)/2;
    if(beg<mid) m(2*node,l,mid,beg,min(mid,en));
    if(mid<en)  m(2*node+1,mid,r,max(beg,mid),en);
}

int main()
{
    cin>>n>>s>>l;
    for(int i=0;i<n;i++)
        cin>>a[i];
    MIN1=1000000000;
    MAX=-1000000000;
    for(int i=0;i<l;i++)
    {
        s1.insert(a[i]);
        MIN1=min(MIN1,a[i]);
        MAX=max(MAX,a[i]);
    }
    if(MAX-MIN1>s)
    {
        cout<<-1<<endl;
        return 0;
    }
    memset(dp,127,sizeof dp);
    make(1,0,n);
    dp[l-1]=1;
    add(1,0,n,l-1);
    //cout<<dp[l-1]<<endl;
    for(int i=l;i<n;i++)
    {
        s1.insert(a[i]);
        while(s1.size()>=l && *(--s1.end())-(*(s1.begin()))>s)
        {
            multiset<int>::iterator it=s1.lower_bound(a[p]);
            s1.erase(it);
            p++;
        }
        if(s1.size()<l)
            continue;
        ans=100000000;
        m(1,0,n,max(p-1,0),i-l+1);
        dp[i]=ans+1;
        if(p==0)
            dp[i]=1;
        add(1,0,n,i);
      //  cout<<i<<" "<<dp[i]<<" "<<p<<" "<<ans<<endl;
    }
    if(dp[n-1]<100000000)
        cout<<dp[n-1]<<endl;
    else
        cout<<-1<<endl;
}