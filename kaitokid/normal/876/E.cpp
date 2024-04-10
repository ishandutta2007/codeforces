#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD =1e9+7;
int n,m,l,x;
bool bl;
bool capital [100009],nocapital [100009];
vector<int> a[100009],too[100009];
bool vis[100009];
void ooof(int i)
{
if(vis[i])return ;
if(nocapital[i]){bl=true;return ;}
capital[i]=true;
vis[i]=true;
for(int j=0;j<too[i].size();j++)ooof(too[i][j]);


}
void go(int w1,int w2,int i)
{
if(a[w1].size()<i+1)return ;
if(a[w2].size()<i+1){bl=true;return ;}
if(a[w2][i]==a[w1][i]){go(w1,w2,i+1);return ;}
int x1=a[w1][i],x2=a[w2][i];
if(x1>x2&&(capital[x2]||nocapital[x1])){bl=true;return;}
if(x1>x2){capital[x1]=true;nocapital[x2]=true;return;}
if(capital[x1])return;
if(nocapital[x2])return ;
if(capital[x2]&&nocapital[x1]){bl=true;return ;}
if(capital [x2]){capital[x1]=true;return ;}
too[x2].push_back(x1);



}
int main()
{
ios::sync_with_stdio(0);
cin>>n>>m;
for(int i=0;i<n;i++)
{
cin>>l;
for(int j=0;j<l;j++)
{cin>>x;
a[i].push_back(x);}
if(i>0)
go(i-1,i,0);
if(bl){cout<<"No";return 0;}
}
for(int i=1;i<=m;i++)
{if(capital[i])ooof(i);
if(bl){cout<<"No";return 0;}
}
int ans=0;
for(int i=1;i<=m;i++)
if(capital[i])ans++;
cout<<"Yes"<<endl<<ans<<endl;
for(int i=1;i<=m;i++)
if(capital[i])cout<<i<<" ";
return 0;}