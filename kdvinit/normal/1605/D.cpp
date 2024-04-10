/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 100;

vector<int> adj[N], bp1, bp2;

void DFS(int chi, int par, int dep)
{
    if(dep%2==0) bp1.push_back(chi);
    else bp2.push_back(chi);

    for(auto x: adj[chi])
    {
        if(x==par) continue;
        DFS(x, chi, dep+1);
    }
}

int n;
void print_ans(vector<int> bp)
{
    int m = bp.size();

    vector<int> num;
    set<int> lft;
    for(int i=1; i<=n; i++) lft.insert(i);

    int cnt=1;

    while(m!=0)
    {
        if(m%2==1)
        {
            int lst = min((2*cnt-1), n);
            for(int i=cnt; i<=lst; i++)
            {
                num.push_back(i);
                lft.erase(i);
            }
        }
        m/=2;
        cnt*=2;
    }

    int ans[n+1]={0};

    m = bp.size();
    for(int i=0; i<m; i++) ans[bp[i]]=num[i];

    bp.clear(); num.clear();
    for(int i=1; i<=n; i++) if(ans[i]==0) bp.push_back(i);
    for(int x: lft) num.push_back(x);

    m = bp.size();
    for(int i=0; i<m; i++) ans[bp[i]]=num[i];

    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

void solve()
{
    cin>>n;

    for(int i=1; i<=n; i++) adj[i].clear();
    bp1.clear();    bp2.clear();

    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1, 0);

    int s1 = bp1.size();
    int s2 = bp2.size();

    if(s1<s2) print_ans(bp1);
    else print_ans(bp2);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}