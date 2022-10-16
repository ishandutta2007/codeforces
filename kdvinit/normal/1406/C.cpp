/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

int min_con,n;
vector<int> poss;

int find_min(vector< vector<int> >& adj,int par,int chi)
{
    int ans=1,temp,mx_con=0;
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        temp=find_min(adj,chi,adj[chi][i]);
        mx_con=max(mx_con,temp);
        ans+=temp;
    }

    mx_con=max(mx_con,n-ans);
    if(mx_con==min_con)
    {
        poss.push_back(chi);
    }
    if(mx_con<min_con)
    {
        poss.clear();
        poss.push_back(chi);
        min_con=mx_con;
    }

    return ans;
}

void solve()
{
    cin>>n;

    min_con=n;
    poss.clear();
    vector< vector<int> > adj(n+1);
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int xx=find_min(adj,0,1);

    if(poss.size()==1)
    {
        cout<<1<<" "<<adj[1][0]<<endl;
        cout<<1<<" "<<adj[1][0]<<endl;
        return;
    }

    int x,y,z,i=0;
    x=poss[0];
    y=poss[1];

    while(1)
    {
        if(adj[y][i]==x) { i++; continue; }
        z=adj[y][i];
        break;
    }

    cout<<y<<" "<<z<<endl;
    cout<<x<<" "<<z<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}