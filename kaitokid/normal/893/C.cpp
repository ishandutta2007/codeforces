#include <bits/stdc++.h>
 using namespace std;
 int par [100009];
 long long ans=0; 
long long a[100009];
 map<int,long long>v; 
int pr(int i)
 { if(par[i]==i)return i;
 par[i]=pr(par[i]); 
return par[i]; }
 int main() {ios::sync_with_stdio(0);
 //memset(v,sizeof v,-1); 
for(int i=1;i<100009;i++)
 {par[i]=i;}
 int n,m;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 cin>>a[i];
 int x,y;
 for(int i=0;i<m;i++)
 {cin>>x>>y; par[pr(x)]=pr(y); } 
for(int i=1;i<=n;i++)
 { if(v[pr(i)]==0){v[par[i]]=a[i]+1;ans+=a[i];continue;} if(a[i]<v[par[i]]-1)
{ans-=(v[par[i]]-1-a[i]);v[par[i]]=a[i]+1; 
 }} 
cout<<ans;
 return 0;}