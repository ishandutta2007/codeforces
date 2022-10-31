// Hydro submission #6218e5c9ae0aafe287eaeb2f@1653750145169
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
map<int, long long> f[N]; vector<int> nxt[N]; int d[N], w[N]; int n, m, k;
void merge(int p, int q){
   if(f[p].size() < f[q].size()) swap(f[p], f[q]);
   for(auto it : f[q]) f[p][it.first] += it.second;
}
void dp(int u){
   f[u][d[u]] += w[u];
   for(int v : nxt[u])
      dp(v);
   for(int v : nxt[u])
      merge(u, v);
   for(auto it = f[u].upper_bound(d[u]); it != f[u].end(); ){
      if(it->second > w[u]){it->second -= w[u]; break;}
      w[u] -= it->second; auto tmp = it; it ++; f[u].erase(tmp);
   }
}
int main(){
   scanf("%d%d%d", &n, &m, &k);
   for(int i = 1; i < n; i ++){int p; scanf("%d", &p); p --; nxt[p].push_back(i);}
   for(int i = 0; i < m; i ++){
      int V, D, W; scanf("%d%d%d", &V, &D, &W); V --, D --; d[V] = D, w[V] = W;
   }
   dp(0);
   long long ans = 0; for(auto it : f[0]) ans += it.second;
   printf("%lld\n", ans);
   return 0;
}