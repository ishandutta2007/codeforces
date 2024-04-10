#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll ans,res;
ll n,c[3][100009],h[100009];
vector<int>a[100009];
vector <int> v;
void go(int pr,int x)
{
    v.push_back(x);
    if(a[x].size()==1)return;
    if(a[x][0]==pr)go(x,a[x][1]);
    else go(x,a[x][0]);
}
int main()
{
 ios::sync_with_stdio(0);
cin>>n;
for(int i=0;i<3;i++)
for(int j=1;j<=n;j++)cin>>c[i][j];
for(int i=0;i<n-1;i++)
{
    int x,y;
    cin>>x>>y;
    if(a[x].size()==2||a[y].size()==2){cout<<-1;return 0;}
    a[x].push_back(y);
    a[y].push_back(x);
}
for(int i=1;i<=n;i++)
{
    if(a[i].size()==1){v.push_back(i);go(i,a[i][0]);break;}
}
res=0;
for(int i=0;i<n;i++)
{
    if(i%3==0)res+=c[0][v[i]];
    if(i%3==1)res+=c[1][v[i]];
    if(i%3==2)res+=c[2][v[i]];

}
for(int i=0;i<n;i++)
{
    if(i%3==0)h[v[i]]=1;
    if(i%3==1)h[v[i]]=2;
    if(i%3==2)h[v[i]]=3;

}
ans=res;
res=0;
for(int i=0;i<n;i++)
{
    if(i%3==0)res+=c[0][v[i]];
    if(i%3==1)res+=c[2][v[i]];
    if(i%3==2)res+=c[1][v[i]];

}
if(res<ans){
for(int i=0;i<n;i++)
{
    if(i%3==0)h[v[i]]=1;
    if(i%3==1)h[v[i]]=3;
    if(i%3==2)h[v[i]]=2;

}
ans=res;}
res=0;
for(int i=0;i<n;i++)
{
    if(i%3==0)res+=c[1][v[i]];
    if(i%3==1)res+=c[0][v[i]];
    if(i%3==2)res+=c[2][v[i]];

}
if(res<ans){
for(int i=0;i<n;i++)
{
    if(i%3==0)h[v[i]]=2;
    if(i%3==1)h[v[i]]=1;
    if(i%3==2)h[v[i]]=3;

}
ans=res;}
res=0;
for(int i=0;i<n;i++)
{
    if(i%3==0)res+=c[1][v[i]];
    if(i%3==1)res+=c[2][v[i]];
    if(i%3==2)res+=c[0][v[i]];

}
if(res<ans){
for(int i=0;i<n;i++)
{
    if(i%3==0)h[v[i]]=2;
    if(i%3==1)h[v[i]]=3;
    if(i%3==2)h[v[i]]=1;

}
ans=res;}
res=0;
for(int i=0;i<n;i++)
{
    if(i%3==0)res+=c[2][v[i]];
    if(i%3==1)res+=c[0][v[i]];
    if(i%3==2)res+=c[1][v[i]];

}
if(res<ans){
for(int i=0;i<n;i++)
{
    if(i%3==0)h[v[i]]=3;
    if(i%3==1)h[v[i]]=1;
    if(i%3==2)h[v[i]]=2;

}
ans=res;}
res=0;
for(int i=0;i<n;i++)
{
    if(i%3==0)res+=c[2][v[i]];
    if(i%3==1)res+=c[1][v[i]];
    if(i%3==2)res+=c[0][v[i]];

}
if(res<ans){
for(int i=0;i<n;i++)
{
    if(i%3==0)h[v[i]]=3;
    if(i%3==1)h[v[i]]=2;
    if(i%3==2)h[v[i]]=1;

}
ans=res;}
cout<<ans<<endl;
for(int i=1;i<=n;i++)cout<<h[i]<<" ";
    return 0;
}