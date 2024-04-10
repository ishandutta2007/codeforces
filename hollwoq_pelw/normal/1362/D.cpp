#include <bits/stdc++.h>
using namespace std;
const int N=6e5;
#define pb push_back
vector<int> g[N],q[N];int n,x,m,i,u,v,a[N],c[N];int main(){cin>>n>>m;for(i=0;i<m;i++){cin>>u>>v;g[v].pb(u);g[u].pb(v);}for(i=1;i<=n;i++){cin>>u;q[u].pb(i);c[i]=1;}for(i=1;i<=n;i++){for(int j:q[i]){if(c[j]!=i) return cout<<-1,0;for(int y:g[j])if(c[y]==i)c[y]++;a[++x]=j;}}for(i=1;i<=n;i++)cout<<a[i]<<' ';}