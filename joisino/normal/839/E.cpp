#include <bits/stdc++.h>
      
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); i++)
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)

#define pb emplace_back

using namespace std;

using ll = long long int;

int cnt;

struct MaxClique{
  vector<vector<int>> G;
  vector<int> cand;
  int n;
  void init(int arg_n){
    n = arg_n;
    G.assign(n, vector<int>(0));
  }
  void add_edge(int a, int b){
    G[a].pb(b);
    G[b].pb(a);
  }
  vector<int> diff(vector<int> a, vector<int> b){
    int ib = 0;
    vector<int> res(0);
    for(int x: a){
      while(ib < b.size() && b[ib] < x){
        ib++;
      }
      if(ib == b.size() || x != b[ib]){
        res.push_back(x);
      }
    }
    return res;
  }
  vector<int> uni(vector<int> a, vector<int> b){
    int ib = 0;
    vector<int> res(0);
    for(int x: a){
      while(ib < b.size() && b[ib] < x){
        res.push_back(b[ib]);
        ib++;
      }
      res.push_back(x);
    }
    for(int i = ib; i < b.size(); i++){
      res.pb(b[ib]);
    }
    return res;
  }
  vector<int> intersect(vector<int> a, vector<int> b){
    int ib = 0;
    vector<int> res(0);
    for(int x: a){
      while(ib < b.size() && b[ib] < x){
        ib++;
      }
      if(ib < b.size() && x == b[ib]){
        res.push_back(x);
      }
    }
    return res;
  }
  void dfs(vector<int> R, vector<int> P, vector<int> X){
    /*
    cout << "R ";
    for(int i = 0; i < R.size(); i++){
      cout << R[i] << " ";
    }
    cout << endl;
    cout << "P ";
    for(int i = 0; i < P.size(); i++){
      cout << P[i] << " ";
    }
    cout << endl;
    cout << "X ";
    for(int i = 0; i < X.size(); i++){
      cout << X[i] << " ";
    }
    cout << endl;
    */    
    cnt++;
    if(P.empty()){
      if(X.empty() && R.size() >= cand.size()){
        cand = R;
      }
      return;
    }
    int piv = P[0];
    for(int v: P){
      if(diff(P, G[v]).size() < diff(P, G[piv]).size()){
        piv = v;
      }
    }
    vector<int> search = diff(P, G[piv]);
    for(int v: search){
      // cout << "v " << v << endl;
      vector<int> nR = uni(R, {v});
      vector<int> nP = intersect(P, G[v]);
      vector<int> nX = intersect(X, G[v]);
      dfs(nR, nP, nX);
      P = diff(P, {v});
      X = uni(X, {v});
    }
  }
  vector<int> max_clique(){
    cand.clear();
    vector<int> R(0);
    vector<int> P(0);
    vector<int> X(0);
    for(int i = 0; i < n; i++){
      P.push_back(i);
    }
    for(int i = 0; i < n; i++){
      sort(G[i].begin(), G[i].end());
    }
    dfs(R, P, X);
    return cand;
  }
};

MaxClique mc;

int n, m;

int main(){

  /*
  cin >> n >> m;
  mc.init(n);
  REP(i, m){
    int a, b;
    cin >> a >> b;
    mc.add_edge(a, b);
  }
  */

  int k;
  cin >> n >> k;
  mc.init(n);
  REP(i, n){
    REP(j, n){
      int a;
      cin >> a;
      if(i < j && a == 1){
        mc.add_edge(i, j);
      }
    }
  }
  
  vector<int> ans = mc.max_clique();
  double x = ans.size();
  double ret = (x - 1) / (2 * x) * k * k;
  printf("%.18lf\n", ret);
  
  // cout << cnt << endl;

  return 0;
}