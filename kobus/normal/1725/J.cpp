#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int n; 

vector<pair<int,int> > adj[N] ; 
long long dp_down[N], dp2_down[N] ; 

void solve_down(int x, int p){
       vector<long long> big3 = {0, 0, 0} ; 
       for(auto u : adj[x]){
              if(u.first == p)continue ; 
              solve_down(u.first, x) ; 
              dp_down[x] = max(dp_down[x], dp_down[u.first] + u.second) ; 
              dp2_down[x] = max(dp2_down[x], dp2_down[u.first]) ; 
              big3[0] = dp_down[u.first] + u.second;
              sort(big3.begin(), big3.end()) ;  
       }
       dp2_down[x] = max(dp2_down[x], big3[1] + big3[2]) ; 
}

long long solve(int x, int p, long long dp, long long dp2){
       long long ret = 0 ;  
       vector<long long> bigs = {0, 0, 0, 0 } ; 
       multiset<long long> paths, paths2 ; 
       paths.insert(0) ; 
       paths.insert(0) ; 
       paths2.insert(0) ; 

       for(auto u: adj[x]){
              if(u.first == p)continue; 
              paths.insert(dp_down[u.first] + u.second) ; 
              paths2.insert(dp2_down[u.first]) ; 
       }

       auto max2 = [&]() -> long long {
              long long ret1 = (*paths.rbegin()) ; 
              paths.erase(paths.find(ret1)) ; 
              long long ret2 = (*paths.rbegin()) ;
              paths.insert(ret1) ; 
              return ret1 + ret2 ; 
       } ; 

       for(auto u : adj[x]){
              if(u.first == p)continue; 
              paths.erase(paths.find(dp_down[u.first] + u.second)) ; 
              paths2.erase(paths2.find(dp2_down[u.first])) ; 
              bigs[0] = dp_down[u.first] + u.second; 
              
              sort(bigs.begin(), bigs.end()) ;
              ret = max(ret, solve(u.first, x, max(dp, (*paths.rbegin()))  + u.second,
               max({dp2, (*paths2.rbegin()), dp + (*paths.rbegin()), max2() }) )) ; 

              ret = max(ret, dp2_down[u.first] + 2ll * u.second + max({dp2,  dp + (*paths.rbegin()) , max2()}) ) ;              
              ret = max(ret, dp2_down[u.first] + (*paths2.rbegin()) + 2ll * u.second) ;
              paths.insert(dp_down[u.first] + u.second) ; 
              paths2.insert(dp2_down[u.first]) ; 
       }

       ret = max(ret, dp2 + dp2_down[x]);
       ret = max(ret, dp + bigs[1] + bigs[2] + bigs[3] ) ;
       ret = max(ret, bigs[0] + bigs[1] + bigs[2] + bigs[3] ) ;
      
       return ret ; 
}

int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);
#ifndef ONLINE_JUDGE
       freopen("in.in", "r", stdin);
#endif
       cin >> n; 
       long long totW = 0 ; 
       for(int i = 0 ;i < n - 1 ; ++ i){
              int u, v , w ; cin >> u >> v >> w ; 
              adj[u].push_back({v, w}) ; 
              adj[v].push_back({u, w}) ; 
              totW += w ; 
       }
       solve_down(1, 1) ; 

       cout << 2ll * totW -  solve(1, 1, 0, 0) ; 
       return 0;
}