/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void do_gchi(vector< vector<int> >& adj,int par,int chi,int gchi[]) // '&' is veru Important here;
{
    int ans=1;
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        do_gchi(adj,chi,adj[chi][i],gchi);
        ans+=gchi[adj[chi][i]];
    }
    gchi[chi]=ans;
}

int centroid(vector< vector<int> >& adj,int par,int chi,int gchi[],int n)
{
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        if(2*gchi[adj[chi][i]]>=n) return centroid(adj,chi,adj[chi][i],gchi,n);
    }
    return chi;
}

void make_arr(vector< vector<int> >& adj,int par,int chi,vector<int>& arr) // '&' is veru Important here;
{
    arr.push_back(chi);
    for(int i=0;i<adj[chi].size();i++)
    {
        if(adj[chi][i]==par) continue;
        make_arr(adj,chi,adj[chi][i],arr);
    }
}

void solve()
{
    int n,x,y;
    cin>>n;

    int gchi[n+1],gchi2[n+1];
    vector< vector<int> > adj(n+1);

    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    do_gchi(adj,0,1,gchi);
    int centr=centroid(adj,0,1,gchi,n);
    do_gchi(adj,0,centr,gchi2);

    int ans=0,mx=0;
    for(int i=1;i<=n;i++)
    {
        if(i==centr) continue;
        ans+=2*gchi2[i];
    }
    cout<<ans<<endl;

    for(int i=1;i<=n;i++)
    {
        if(i==centr) continue;
        mx=max(mx,gchi2[i]);
    }

    vector<int> arr;
    make_arr(adj,0,centr,arr);

    int new_house[n+1];
    for(int i=0;i<n;i++) new_house[arr[i]]=arr[(i+mx)%n];

    for(int i=1;i<=n;i++) cout<<new_house[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}