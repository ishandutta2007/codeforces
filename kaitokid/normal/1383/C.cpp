#include <bits/stdc++.h>

using namespace std;
int pp,n;
string s,t;
vector<int>a[21];
vector<int>v;
bool vis[25];
bool nd[22][22];
int to[22];
int g[22];
int bt[3000008];
int dp[3000008];
int rs[3000008];
void go(int x)
{
    v.push_back(x);
    vis[x]=true;
    for(int i=0;i<a[x].size();i++)
        if(!vis[a[x][i]])go(a[x][i]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin>>pp;
    for(int i=1;i<(1<<20);i++)
        for(int j=0;j<20;j++)
        if(i&(1<<j))bt[i]++;
    while(pp--)
    {
        int ans=0;
        cin>>n>>s>>t;
        for(int i=0;i<20;i++){a[i].clear();vis[i]=false;to[i]=0;g[i]=0;
        for(int j=0;j<20;j++)nd[i][j]=false;
        }
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i])continue;
a[s[i]-'a'].push_back(t[i]-'a');
a[t[i]-'a'].push_back(s[i]-'a');
if(!nd[s[i]-'a'][t[i]-'a'])
{


    nd[s[i]-'a'][t[i]-'a']=true;
    to[t[i]-'a']++;
    g[t[i]-'a']|=(1<<(s[i]-'a'));
}
    }
for(int i=0;i<20;i++)
{
    if(vis[i])continue;
    v.clear();
    go(i);
    int u=v.size();
    ans+=u-1;
//cout<<u<<endl;
    dp[0]=0;
    rs[0]=0;
    for(int j=1;j<(1<<u);j++)
    {
        dp[j]=50;
        for(int q=0;q<u;q++)
        {
            if((j&(1<<q))==0)continue;
            int f=(j^(1<<q));
            int res=dp[f]+((to[v[q]]-bt[(rs[f]&g[v[q]])])>0);
            rs[j]=rs[f]|(1<<v[q]);
            //cout<<j<<" "<<rs[j]<<" "<<res<<endl;
            dp[j]=min(dp[j],res);
        }
    }
    ans+=dp[(1<<u)-1];

}
cout<<ans<<endl;
    }
    return 0;
}