// KALAM
# include<bits/stdc++.h>

using namespace std;

const int N = 500000 + 77;
int T;
long long dp[N][2];
int n , k;
vector < pair < int , int > > adj[N];
bool CMP(pair < int , int > x , pair < int , int > y) {
   return dp[x.first][1] + x.second - dp[x.first][0] > dp[y.first][1] + y.second - dp[y.first][0];
}
void dfs(int v , int prev = - 1) {
   vector < pair < int , int > > Ch;
   for(auto x : adj[v])
      if(x.first != prev)
         dfs(x.first , v) , Ch.push_back(x);
   sort(Ch.begin() , Ch.end() , CMP);
   // dp[v][1]
   int f = k - 1;
   for(auto x : Ch) {
      if(f > 0) dp[v][1] += max(dp[x.first][1] + x.second , dp[x.first][0]);
      else dp[v][1] += dp[x.first][0];
      -- f;
   }
   // dp[v][0]
   f = k;
   for(auto x : Ch) {
      if(f > 0) dp[v][0] += max(dp[x.first][1] + x.second , dp[x.first][0]);
      else dp[v][0] += dp[x.first][0];
      -- f;
   }
}
inline void Test() {
   scanf("%d %d" , & n , & k);
   for(int v , u , w , i = 1;i < n;++ i)
      scanf("%d %d %d" , & v , & u , & w) , adj[v].push_back(make_pair(u , w)) , adj[u].push_back(make_pair(v , w));
   dfs(1);
   printf("%lld\n" , dp[1][0]);
   for(int i = 1;i <= n;++ i) adj[i].clear();
   for(int i = 1;i <= n;++ i) dp[i][0] = dp[i][1] = 0;
}
int main() {
   scanf("%d" , & T);
   while(T --) Test();
   return 0;
}