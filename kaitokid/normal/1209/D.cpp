#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<pair<int,int> >a;
bool vis[100009];
int n,k,x,y,co[100009],ans;
vector<int > v[100009];
void go(int wh)
{
    vis[wh]=true;
    for(int i=0;i<v[wh].size();i++)
   {

    if(!vis[v[wh][i]])
        {ans++;go(v[wh][i]);}
}}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>k;
for(int i=0;i<k;i++)
{cin>>x>>y;
v[x].push_back(y);
v[y].push_back(x);


}
for(int i=1;i<=n;i++)if(!vis[i])go(i);
    cout<<k-ans;
    return 0;
}