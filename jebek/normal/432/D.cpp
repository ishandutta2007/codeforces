#include <iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int dp[2000000];
string s;
bool mark[2000000];
int f[2000000];
vector<int>G[2000000],ans;

void dfs(int v)
{
    dp[v]=1;
   // cout<<v<<endl;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        dfs(u);
        dp[v]+=dp[u];
        mark[v]|=mark[u];
    }
    if(mark[v] && v<s.size())
        ans.push_back(v+1);
}

int main()
{
    cin>>s;
    f[0]=0;
    G[s.size()].push_back(0);
    for(int i=1,k=0;i<s.size();i++)
    {
        while(k && s[i]!=s[k]) k=f[k-1];
        if(s[i]==s[k])  k++;
        f[i]=k;
       // cout<<i<<" "<<f[i]<<endl;
        if(k!=0)
            G[k-1].push_back(i);
        else
            G[s.size()].push_back(i);
    }
    mark[s.size()-1]=true;
    dfs(s.size());
    cout<<ans.size()<<endl;
    for(int i=ans.size()-1;i>-1;i--)
        cout<<ans[i]<<" "<<dp[ans[i]-1]<<endl;
}