#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ans[7009][2];
int los[7009][2];
vector<int>v[2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
memset(ans,-1,sizeof ans);
ans[0][0]=ans[0][1]=0;
int n,k[2];
cin>>n;
for(int q=0;q<2;q++)
{
    cin>>k[q];
    int x;
    for(int i=0;i<k[q];i++){cin>>x;v[q].push_back(x);}
}
queue<pair<int,int> >q;
q.push({0,0});
q.push({0,1});
while(!q.empty())
{
    int u=q.front().first,t=q.front().second;
    q.pop();
    if(ans[u][t]==1)
    {
        for(int i=0;i<k[1-t];i++)
        {
            int r=v[1-t][i];
            r=(u-r+n)%n;
            if(ans[r][1-t]!=-1)continue;
            los[r][1-t]++;
            if(los[r][1-t]==k[1-t]){ans[r][1-t]=0;q.push({r,1-t});}
        }
        continue;
    }
    for(int i=0;i<k[1-t];i++)
        {
            int r=v[1-t][i];
            r=(u-r+n)%n;
            if(ans[r][1-t]!=-1)continue;
            ans[r][1-t]=1;
            q.push({r,1-t});
        }

}
for(int j=0;j<2;j++)
{

    for(int i=1;i<n;i++){
if(ans[i][j]==0)cout<<"Lose ";
if(ans[i][j]==1)cout<<"Win ";
if(ans[i][j]==-1)cout<<"Loop ";


    }
    cout<<endl;}
    return 0;
}