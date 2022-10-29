// KINGPONYHEAD
# include<bits/stdc++.h>

using namespace std;

const int N = 200000 + 77;
int n , m , st , cur = 1 , C[N] , d[N] , Top[N] , W[N] , Sz[N];
bool M[N];
long long S[N] , dp[N] , best;
bool alone[N];
vector < int > adj[N] , badj[N];
void dfsPre(int v , int prev = - 1) {
   M[v] = 1;
   Top[v] = v;
   for(int u : adj[v]) {
      if(M[u]) {
         if(d[u] < d[Top[v]] && u != prev)
            Top[v] = u;
         continue ;
      }
      d[u] = d[v] + 1;
      dfsPre(u , v);
      if(d[Top[u]] < d[Top[v]]) Top[v] = Top[u];
   }
}
void dfs(int v) {
   M[v] = 1;
   for(int u : adj[v]) {
      if(M[u]) continue ;
      if(Top[u] != u) C[u] = C[v];
      else C[u] = cur ++;
      dfs(u);
   }
}
void dfsx(int v , int prev = - 1) {
   for(int u : badj[v]) {
      if(u == prev) continue ;
      dfsx(u , v);
      alone[v] &= alone[u];
      if(! alone[u]) dp[v] += dp[u];
   }
   if(alone[v]) {
      dp[v] = 0;
      for(int u : badj[v]) {
         if(u == prev) continue ;
         dp[v] = max(dp[v] , dp[u]);
      }
   }
   dp[v] += S[v];
   if(alone[v] && st != v) best = max(best , dp[v]);
}
int main() {
   scanf("%d %d" , & n , & m);
   for(int i = 1;i <= n;++ i) scanf("%d" , W + i);
   for(int v , u , i = 1;i <= m;++ i)
      scanf("%d %d" , & v , & u) , adj[v].push_back(u) , adj[u].push_back(v);
   scanf("%d" , & st);
   for(int i = 1;i <= n;++ i)
      if(! M[i])
         dfsPre(i);
   memset(M , 0 , sizeof M);
   for(int i = 1;i <= n;++ i)
      if(! M[i])
         C[i] = cur ++ , dfs(i);
   for(int i = 1;i <= n;++ i)
      S[C[i]] += W[i] , ++ Sz[C[i]];
   st = C[st];
   for(int v = 1;v <= n;++ v)
      for(int u : adj[v])
         if(C[v] != C[u])
            badj[C[v]].push_back(C[u]);
   for(int i = 1;i < cur;++ i)
      sort(badj[i].begin() , badj[i].end()) , badj[i].resize(unique(badj[i].begin() , badj[i].end()) - badj[i].begin());
   for(int i = 1;i < cur;++ i)
      if(Sz[i] == 1)
         alone[i] = 1;
   dfsx(st);
   if(alone[st]) best = 0;
   printf("%lld\n" , dp[st] + best);
   return 0;
}