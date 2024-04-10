#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
int f[N], indeg[N], outdeg[N], vis[N];
long long lcm(long long a, long long b){
  return a * (b / __gcd(a, b));
}
int main(){
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &f[i]);
    indeg[f[i]]++;
  }
  for(int i = 1; i <= n; i++){
    if(indeg[i] != 1){
      printf("-1");
      return 0;
    }
  }
  long long ans = 1;
  for(int i = 1; i <= n; i++){
    if(!vis[i]){
      int l = 0;
      int u = i;
      while(!vis[u]){
        vis[u] = 1;
        l++;
        u = f[u];
      }
      if(l & 1){
        ans = lcm(ans, l);
      }
      else ans = lcm(ans, l >> 1);
    }
  }
  printf("%lld", ans);
}