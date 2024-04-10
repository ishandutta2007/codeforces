#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

const int MAXN=5000;
bool mark[MAXN];
int m[MAXN],ind,t[MAXN],ans,r,n,a[MAXN],sum,f[MAXN];
unsigned int l;
vector<int>G[MAXN],W[MAXN],v1;

void dfs(int v,int k)
{
    mark[v]=true;
    m[v]=ind;
    t[ind]++;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u] && W[v][i]<=k)
            dfs(u,k);
    }
}

bool check(int k)
{
    memset(mark,false,sizeof mark);
    ind=0;
    for(int i=1;i<=n;i++)
        if(!mark[i])
        {
            t[ind]=0;
            f[ind]=0;
            dfs(i,k);
            ind++;
        }
    ans=0;
    for(int i=1;i<=n;i++)
        f[m[i]]+=a[i];
    for(int i=0;i<ind;i++)
        if(sum-f[i]<t[i])
            return false;
    for(int i=1;i<=n;i++)
        ans+=max(0,min(a[i],n-t[m[i]]));
   // cout<<k<<" "<<ans<<endl;
    if(ans>=n)
        return true;
    return false;
}

int main()
{
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int v,u,w;
        cin>>v>>u>>w;
        v1.push_back(w);
        G[v].push_back(u);
        G[u].push_back(v);
        W[v].push_back(w);
        W[u].push_back(w);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    sort(v1.begin(),v1.end());
    r=v1.size()-1;
 //   cout<<l<<" "<<r<<endl;
    while(l<r)
    {
        int mid=(l+r+1)/2;
        if(check(v1[mid]))
            l=mid;
        else
            r=mid-1;
    }
    if(l+1>=v1.size())
        cout<<v1.back()<<endl;
    else
        cout<<v1[l+1]<<endl;
}