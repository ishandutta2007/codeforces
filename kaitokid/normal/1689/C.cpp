#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int sz[300009],dp[300009];
vector<int>v[300009];
int go(int x,int p)
{
    sz[x]=1;
    dp[x]=0;
    vector<int>ch;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=p){ch.push_back(v[x][i]);go(v[x][i],x);sz[x]+=sz[v[x][i]];}
    if(ch.empty())return dp[x]=0;
    if(ch.size()==1)return dp[x]=sz[ch[0]]-1;
    return dp[x]=max(sz[ch[0]]+dp[ch[1]]-1,sz[ch[1]]+dp[ch[0]]-1);

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
    for(int i=1;i<=n;i++)v[i].clear();
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cout<<go(1,0)<<endl;
}

return 0;
}