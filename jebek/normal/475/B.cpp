#include <iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int n,m,t;
bool mark[1000];
vector<int>G[1000];
string s1,s2;

void dfs(int v)
{
    t++;mark[v]=true;
    for(int i=0;i<G[v].size();i++)
        if(!mark[G[v][i]])
            dfs(G[v][i]);
}

int main()
{
    cin>>n>>m>>s1>>s2;
    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)
        {
            if(s1[i]=='<')
                G[i*m+j].push_back(i*m+j-1);
            else
                G[i*m+j-1].push_back(i*m+j);
        }
    for(int i=1;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(s2[j]=='^')
                G[i*m+j].push_back(i*m+j-m);
            else
                G[i*m+j-m].push_back(i*m+j);
        }
    for(int i=0;i<n*m;i++)
    {
        memset(mark,false,sizeof mark);
        dfs(i);
        if(t<n*m)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        t=0;
    }
    cout<<"YES"<<endl;
}