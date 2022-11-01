#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n,m,k;
char c[600][600];
bool mark[300000];
vector<int>G[300000];

void ok(int v,int u)
{
  //  cout<<v<<"->"<<u<<endl;
    G[v].push_back(u);
    G[u].push_back(v);
}

void dfs(int v)
{
    mark[v]=true;
    for(int i=0;i<G[v].size();i++)
    {
        int u=G[v][i];
     //   cout<<v<<" "<<u<<endl;
        if(!mark[u])
            dfs(u);
    }
    if(k>0)
    {
        k--;
        c[v/m][v%m]='X';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>c[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
           // cout<<i<<" "<<j<<" "<<c[i][j]<<" "<<c[i-1][j]<<" "<<c[i][j-1]<<endl;
            if(c[i][j]=='.' && i>0 && c[i-1][j]=='.')
                ok(i*m+j,i*m+j-m);
            if(c[i][j]=='.' && j>0 && c[i][j-1]=='.')
                ok(i*m+j,i*m+j-1);
        }
    for(int i=0;i<n && k>0;i++)
        for(int j=0;j<m && k>0;j++)
            if(c[i][j]=='.' && !mark[i*m+j])
            {
          //      cout<<"#"<<i*m+j<<endl;
                dfs(i*m+j);
            }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<c[i][j];
        cout<<endl;
    }
}