#include <iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

vector<int>ans;
const int MAXN=1000000+1000;
int n,q,a[MAXN],b[MAXN],dp[MAXN],c[MAXN],MAX[MAXN*5],ans1;
bool mark;

void f(int node,int l,int r,int beg,int en)
{
    if(beg<=l && r<=en)
    {
        ans1=max(MAX[node],ans1);
        return;
    }
    int mid=(l+r)/2;
    if(beg<mid) f(2*node,l,mid,beg,en);
    if(mid<en)  f(2*node+1,mid,r,beg,en);
}

void add(int node,int l,int r,int x)
{
    if(l+1>=r)
    {
        MAX[node]=dp[x];
        return;
    }
    int mid=(l+r)/2;
    if(x<mid)   add(2*node,l,mid,x);
    else    add(2*node+1,mid,r,x);
    MAX[node]=max(MAX[2*node],MAX[2*node+1]);
}

void run(int l,int r)
{
    if(l>r)
        return;
    if(l==r)
    {
        ans.push_back(l);
        return;
    }
    ans1=0;
    if(a[l]==l)
        ans1=l;
    else
        f(1,1,n+1,l+1,a[l]+1);
    int x=ans1;
    if(c[l]<=x || x>r)
        mark=true;
    run(l+1,x);
    ans.push_back(l);
    run(x+1,r);
}

int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        a[i]=b[i]=i,c[i]=n+1;
    for(int i=0;i<q;i++)
    {
        string s;
        int v,u;
        cin>>v>>u>>s;
        if(v>=u)
            mark=true;
        if(s=="LEFT")
            a[v]=max(a[v],u);
        else
            b[v]=max(b[v],u),c[v]=min(c[v],u);
    }
    for(int i=n;i>0;i--)
    {
        dp[i]=i;
        if(a[i]>i || b[i]>i)
        {
            ans1=i;
            f(1,1,n+1,i+1,max(a[i],b[i])+1);
            dp[i]=ans1;
        }
        add(1,1,n+1,i);
    }
    run(1,n);
    if(mark)
    {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}