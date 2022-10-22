#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1009][1009];
bool vis[1009][1009];
int n,m;
int ch(int x,int y)
{
    if(x<0||x>n-2 || y<0 || y>m-2)return 0;
    int mn=1e9,mx=a[x][y];
    for(int i=x;i<x+2;i++)
        for(int j=y;j<y+2;j++)if(a[i][j]!=0)mn=min(a[i][j],mn),mx=max(a[i][j],mx);
        if(mx!=mn)return 0;
        return mx;

}
int main()
{
    scanf("%d%d",&n,&m);

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)scanf("%d",&a[i][j]);
           // cin>>a[i][j];
    vector<pair<pair<int,int>,int> > ans;
    queue<pair<int,int> >q;
    for(int i=0;i+1<n;i++)
        for(int j=0;j<m;j++)
    if(ch[i][j])q.push({i,j});
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;
        q.pop();
        int u=ch(x,y);
        if(u==0)continue;
        vis[x][y]=true;
        ans.push_back({{x,y},u});
        a[x][y]=a[x+1][y]=a[x][y+1]=a[x+1][y+1]=0;

        for(int i=x-1;i<=x+1;i++)
            for(int j=y-1;j<=y+1;j++)
        if(!vis[i][j] && ch(i,j)!=0)q.push({i,j});
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)if(a[i][j]>0){cout<<-1;return 0;}
    reverse(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        //cout<<ans[i].first.first+1<<" "<<ans[i].first.second+1<<" "<<ans[i].second<<endl;
    printf("%d %d %d\n",ans[i].first.first+1,ans[i].first.second+1,ans[i].second);
    return 0;
}