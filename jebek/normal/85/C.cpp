#include <iostream>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

typedef pair<int,int> pii;
const int MAXN=200000;
long double dp[MAXN],t[MAXN];
int par[MAXN],l[MAXN],r[MAXN],MIN[MAXN],MAX[MAXN],a[MAXN],q,n,root;
vector<pii>v;

void dfs1(int v)
{
 //   cout<<v<<" "<<t[v]<<" "<<dp[v]<<endl;
    if(l[v]==0)
        return;
    t[l[v]]=t[v]+1;
    t[r[v]]=t[v]+1;
    dp[l[v]]=dp[v]+MIN[r[v]];
    dp[r[v]]=dp[v]+MAX[l[v]];
    dfs1(l[v]);
    dfs1(r[v]);
}

void dfs(int v)
{
    if(l[v]==0)
    {
        MIN[v]=MAX[v]=a[v];
        return;
    }
    dfs(l[v]);
    dfs(r[v]);
    MIN[v]=MIN[l[v]];
    MAX[v]=MAX[r[v]];
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>par[i]>>a[i];
        v.push_back(pii(a[i],i));
    }
    for(int i=1;i<=n;i++)
    {
        if(par[i]==-1)
        {
            root=i;
            continue;
        }
        if(a[i]<a[par[i]])
            l[par[i]]=i;
        else
            r[par[i]]=i;
    }
    dfs(root);
    dfs1(root);
    sort(v.begin(),v.end());
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        int k=lower_bound(v.begin(),v.end(),pii(x,0))-v.begin();
      //  cout<<k<<endl;
        if(k!=0 && (k==v.size() || l[v[k].second]!=0))
            k--;
        k=v[k].second;
        cout<<fixed<<setprecision(9)<<dp[k]/t[k]<<endl;
    }
}