// Hydro submission #619f4a74a76fd5537b89e080@1637829237234
#include<bits/stdc++.h>
using namespace std;
int a[3009],f[3009][3009],g[3009][3009];
int main(){
 ios::sync_with_stdio(0),cin.tie(0);
 int T,n,i,j;long long z=0;
 for(cin>>T;T--;cout<<z<<'\n'){
  for(cin>>n,i=1;i<=n;++f[i][a[i]],++i)cin>>a[i],memcpy(f[i],f[i-1],n+1<<2);
  for(memset(g[n+1],0,n+1<<2),i=n;i;++g[i][a[i]],--i)memcpy(g[i],g[i+1],n+1<<2);
  for(z=0,i=2;i<n;++i)for(j=i+1;j<n;++j)z+=1ll*f[i-1][a[j]]*g[j+1][a[i]];
 }
}