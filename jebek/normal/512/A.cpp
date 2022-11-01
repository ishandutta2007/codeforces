#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool mark[300];
vector<int>G[300],topo;
int n,f[300];
string s[200];

void dfs(int v)
{
    mark[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
        if(!mark[u])
            dfs(u);
    }
    topo.push_back(v);
    f[v]=26-topo.size();
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>s[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int p=0;
            while(p<min(s[i].size(),s[j].size()) && s[i][p]==s[j][p])
                p++;
            if(p<min(s[i].size(),s[j].size()))
            {
                int v=int(s[i][p]-'a'),u=int(s[j][p]-'a');
                G[u].push_back(v);
            }
            else if(s[i].size()<s[j].size())
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
        }
    }
    for(int i=0;i<26;i++)
        if(!mark[i])
            dfs(i);
    for(int i=0;i<26;i++)
        for(int j=0;j<G[i].size();i++)
            if(f[i]>f[G[i][j]])
            {
                cout<<"Impossible"<<endl;
                return 0;
            }
    for(int i=topo.size()-1;i>-1;i--)
        cout<<char(topo[i]+int('a'));
    cout<<endl;
}