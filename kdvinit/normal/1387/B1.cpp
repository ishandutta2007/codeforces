/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

int do_tree(vector< vector<int> >& adj,int par,int chi,int new_house[],int not_assign[]) // '&' is veru Important here;
{
    int ans=0;
    vector<int> chi_unass;
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        ans+=do_tree(adj,chi,adj[chi][i],new_house,not_assign);
        if(not_assign[adj[chi][i]]==1) chi_unass.push_back(adj[chi][i]);
    }
    int n=chi_unass.size();
    if(chi_unass.size()==0) { not_assign[chi]=1; return ans; }

    new_house[chi_unass[0]]=chi;
    new_house[chi]=chi_unass[n-1];

    for(int i=1;i<n;i++)
        new_house[chi_unass[i]]=chi_unass[i-1];

    ans+=2*n;
    return ans;
}

void solve()
{
    int n,x,y;
    cin>>n;

    int new_house[n+1]={0},not_assign[n+1]={0};
    vector< vector<int> > adj(n+1);
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans=do_tree(adj,0,1,new_house,not_assign);

    if(new_house[1]==0)
    {
        ans+=2;
        int temp=1;
        while(new_house[temp]!=adj[1][0]) temp++;
        new_house[temp]=1;
        new_house[1]=adj[1][0];

    }

    cout<<ans<<endl;
    for(int i=1;i<=n;i++) cout<<new_house[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}