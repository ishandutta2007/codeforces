#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool vis[200009];
vector<int>v[200009];
int ans;
void go(int x,int p)
{
    int r=0;
    for(int i=0;i<v[x].size();i++)
    {
        if(v[x][i]==p)continue;
        go(v[x][i],x);
        if(!vis[v[x][i]])r++;

    }
    if(r==0){if(x==1)ans++;return;}
    ans+=r;
    vis[x]=true;
    if(x!=1)ans--;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){v[i].clear();vis[i]=false;}
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        go(1,0);
       cout<<ans<<endl;
    }
    return 0;
}