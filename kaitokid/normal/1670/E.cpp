#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
vector<pair<int,int> >ed[300009];
int ans[300009],eg[300009],lvl[300009],pr[300009],ansed[300009];
void go(int x,int p,int id)
{
    pr[x]=p;
    lvl[x]=lvl[p]+1;
    eg[x]=id;
    for(int i=0;i<ed[x].size();i++)
    {
        if(ed[x][i].first==p)continue;
        go(ed[x][i].first,x,ed[x][i].second);
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n=(1<<n);
        for(int i=1;i<=n;i++)ed[i].clear();
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;

            ed[u].push_back({v,i});
            ed[v].push_back({u,i});
        }
        go(n,0,0);
        ans[n]=n;
        for(int i=1;i<n;i++)
        {
            ans[i]=i;
            ansed[eg[i]]=n^i;
            if(lvl[i]%2)swap(ansed[eg[i]],ans[i]);
        }
        cout<<n<<endl;
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;
        for(int i=1;i<n;i++)cout<<ansed[i]<<" ";
        cout<<endl;
    }
    return 0;
}