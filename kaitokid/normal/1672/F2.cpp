#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009],b[200009];
vector<int>ed[200009];
int vis[200009],fr[200009],mx;
bool ans;
void go(int x)
{
    if(x==mx)return;
    if(vis[x]==2)return;
    if(vis[x]==1){ans=false;return;}
    vis[x]=1;
    for(int i=0;i<ed[x].size();i++)go(ed[x][i]);
    vis[x]=2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {

       int n;
       cin>>n;
       for(int i=0;i<=n;i++){ed[i].clear();vis[i]=0;fr[i]=0;}
       for(int i=0;i<n;i++)
       {cin>>a[i];fr[a[i]]++;}

       for(int i=0;i<n;i++)
       {
           cin>>b[i];
           ed[a[i]].push_back(b[i]);
       }
    mx=0;
    ans=true;
    for(int i=1;i<=n;i++)if(fr[i]>fr[mx])mx=i;
    for(int i=1;i<=n;i++)if(vis[i]==0)go(i);
    if(ans)cout<<"AC"<<endl;
    else cout<<"WA"<<endl;


    }
return 0;
}