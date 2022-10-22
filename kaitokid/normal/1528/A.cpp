#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>ed[200009];
ll l[200009],r[200009];
ll dp[200009][2];
ll go(int x,int y,int pr)
{
    ll &res=dp[x][y];
    if(res!=-1)return res;
    res=0;
    ll d;
    if(y==0)d=l[x];
    else d=r[x];
    for(int i=0;i<ed[x].size();i++)
    {
        int u=ed[x][i];
        if(u==pr)continue;
        res+=max(go(u,0,x)+abs(d-l[u]),go(u,1,x)+abs(d-r[u]));
    }
    return res;
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
    for(int i=1;i<=n;i++){cin>>l[i]>>r[i];ed[i].clear();dp[i][0]=dp[i][1]=-1;}
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        ed[x].push_back(y);
        ed[y].push_back(x);

    }
cout<<max(go(1,0,0),go(1,1,0))<<endl;

}
    return 0;
}