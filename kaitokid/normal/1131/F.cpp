#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n,x,y;

vector<int>q[150009];
int wh[150009];
void go(int x,int y)
{
    if(q[x].size()>q[y].size())swap(x,y);
    for(int i=0;i<q[x].size();i++){wh[q[x][i]]=y;q[y].push_back(q[x][i]);}
    q[x].clear();
}
int main()
{
    ios::sync_with_stdio(0);
   cin>>n;
   for(int i=1;i<=n;i++){q[i].push_back(i);wh[i]=i;}
   for(int i=1;i<n;i++){

    cin>>x>>y;
    x=wh[x];
    y=wh[y];
    if(x==y)continue;
    go(x,y);
   }
  for(int i=1;i<=n;i++)
    for(int j=0;j<q[i].size();j++)
    cout<<q[i][j]<<" ";
    return 0;
}