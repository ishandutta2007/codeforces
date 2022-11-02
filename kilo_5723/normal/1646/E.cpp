#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn=1e6+5,maxk=25;
int res[maxk];
bool vis[maxn];
bool st[maxn*maxk];
int main() {
  int n,m;
  scanf("%d%d",&n,&m);
  ll tmp=0;
  for (int i=1;i<maxk;i++){
    for (int j=1;j<=m;j++){
      tmp+=!st[j*i];
      st[j*i]=1;
    }
    res[i]=tmp;
  }
  ll ans=1;
  for (int i=2;i<=n;i++) if (!vis[i]){
    int cnt=0;
    for (ll val=i;val<=n;val*=i){
      cnt++; vis[val]=true;
    }
    // printf("%d\n",cnt);
    ans+=res[cnt];
  }
  printf("%lld\n",ans);
  return 0;
}