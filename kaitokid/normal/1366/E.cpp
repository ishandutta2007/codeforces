#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[200009],b[200009];
map<int,int>ls;
ll mod=998244353;
int main()
{
    ios::sync_with_stdio(0);
    int n,m;

        cin>>n>>m;
for(int i=1;i<=n;i++){cin>>a[i];ls[a[i]]=i;}
for(int i=0;i<m;i++)cin>>b[i];


int u=ls[b[0]];
if(u==0){cout<<0;return 0;}
for(int i=1;i<u;i++)if(a[i]<b[0]){cout<<0;return 0;}
ll ans=1;
int v;
//cout<<u<<endl;
for(int i=1;i<m;i++)
{
    v=ls[b[i]];
    if(v==0){cout<<0;return 0;}
//cout<<4444<<v<<endl;
ll f=u+1;

for(int j=u+1;j<v;j++)
{
    if(a[j]<b[i-1]){cout<<0;return 0;}
    if(a[j]<b[i])f=j+1;
}
ans=(ans*(v-f+1))%mod;
//cout<<ans<<endl;
u=v;
}

u=ls[b[m-1]];
for(int i=u;i<=n;i++)if(a[i]<b[m-1]){cout<<0;return 0;}
cout<<ans;
    return 0;
}