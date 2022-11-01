#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
string s[N];
vector<pair<int,int> >v;
bool vis[N];
bool judge(int x,int y)
{
    for(int i=0,j=m-1;i<m;i++,j--)
        if(s[x][i]!=s[y][j]) return false;
    return true;
}
bool judge(int x)
{
    for(int i=0,j=m-1;i<m;i++,j--)
        if(s[x][i]!=s[x][j]) return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        cin>>s[i];
    for(int i=1;i<=n;i++)
        if(!vis[i])
    {
        for(int j=i+1;j<=n;j++)
            if(!vis[j]&&judge(i,j))
        {
            vis[i]=true;vis[j]=true;
            v.push_back({i,j});
        }
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]&&judge(i))
    {
        cout<<v.size()*m*2+m<<endl;
        for(int j=0;j<v.size();j++)
            cout<<s[v[j].first];
        cout<<s[i];
        for(int j=v.size()-1;j>=0;j--)
            cout<<s[v[j].second];
        return 0;
    }
    cout<<v.size()*m*2<<endl;
    for(int j=0;j<v.size();j++)
        cout<<s[v[j].first];
    for(int j=v.size()-1;j>=0;j--)
        cout<<s[v[j].second];
    if(v.size()==0) cout<<endl;
}