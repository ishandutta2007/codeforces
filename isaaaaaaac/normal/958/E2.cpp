#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#define int long long
using namespace std;
#define N 500010
priority_queue<pair<int,int> >q;
int n,m,x,y,z,ans,a[N],pre[N],ne[N],b[N];
void del(int x) {
  pre[ne[x]]=pre[x];ne[pre[x]]=ne[x];b[x]=1;
}
signed main() {
  scanf("%lld%lld",&m,&n);
  for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
  sort(a+1,a+n+1);
  for (int i=1;i<n;++i) {
    pre[i]=i-1; ne[i]=i+1;
    a[i]=a[i+1]-a[i];
    a[i]=-a[i];
    q.push(make_pair(a[i],i));
  }
  a[0] = a[n] = -1e9;
  while (m--) {
    while (b[q.top().second]) q.pop();
    int val=q.top().first;
    int pos=q.top().second;
    q.pop();
    ans+=val;
    a[pos]=a[pre[pos]]+a[ne[pos]]-val;
    q.push(make_pair(a[pos],pos));
    del(pre[pos]);del(ne[pos]);
  }
  printf("%lld\n",-ans);
  return 0;
}