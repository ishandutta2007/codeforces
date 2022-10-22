#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
pair<int,int> x[1003][1003];
char ans[1003][1003];
bool vis[1003][1003];
void go(char c,int a,int b)
{
    ans[a][b]=c;
    vis[a][b]++;
    if(a>0&&x[a-1][b]==x[a][b]&&(!vis[a-1][b]))go('D',a-1,b);
    if(b>0&&x[a][b-1]==x[a][b]&&(!vis[a][b-1]))go('R',a,b-1);
    if(a<n-1&&x[a+1][b]==x[a][b]&&(!vis[a+1][b]))go('U',a+1,b);
if(b<n-1&&x[a][b+1]==x[a][b]&&(!vis[a][b+1]))go('L',a,b+1);
}
int main()
{
    ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    cin>>x[i][j].first>>x[i][j].second;
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        if(x[i][j].first==i+1&&x[i][j].second==j+1)go('X',i,j);
        if(x[i][j].first==-1)
        {
            if(i>0&&x[i-1][j].first==-1){vis[i][j]=true;ans[i][j]='U';continue;}
            if(i<n-1&&x[i+1][j].first==-1){vis[i][j]=true;ans[i][j]='D';continue;}
            if(j>0&&x[i][j-1].first==-1){vis[i][j]=true;ans[i][j]='L';continue;}
            if(j<n-1&&x[i][j+1].first==-1){vis[i][j]=true;ans[i][j]='R';continue;}
            cout<<"INVALID";
            return 0;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
    if(!vis[i][j]){cout<<"INVALID";;return 0;}
    cout<<"VALID\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)cout<<ans[i][j];
        cout<<endl;
    }
    return 0;
}