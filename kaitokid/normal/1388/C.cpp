#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll n,m;
ll p[100009],h[100008],g[100009],r[100009],f[100009];
vector<ll>a[100008];
bool ans;
void go(int x,int pr)
{if(ans==false)return;
    ll u=0,v=0;
    for(int i=0;i<a[x].size();i++)
    if(a[x][i]!=pr){go(a[x][i],x);p[x]+=p[a[x][i]];u+=g[a[x][i]];v+=r[a[x][i]];}
    g[x]=(p[x]+h[x]);
    if(g[x]<0||(g[x]%2)){ans=false;return;}
g[x]/=2;
if(g[x]<u){ans=false;return;}
r[x]=g[x]-h[x];
if(r[x]+g[x]!=p[x]||r[x]<0){ans=false;return;}
if(r[x]-v>f[x]){ans=false;return;}
ll z=min(r[x],f[x]);
ll s=f[x]-z;
if(g[x]<u+s){ans=false;return;}

}
int main()
{

    ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{

    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        a[i].clear();
        g[i]=0;
        r[i]=0;
    }
for(int i=0;i<n;i++){cin>>p[i];f[i]=p[i];}
for(int i=0;i<n;i++)cin>>h[i];
for(int i=0;i<n-1;i++)
{
    ll x,y;
    cin>>x>>y;
    x--;
    y--;
    a[x].push_back(y);
    a[y].push_back(x);

}
ans=true;
go(0,-1);
if(ans)cout<<"YES\n";else cout<<"NO\n";
}
    return 0;
}