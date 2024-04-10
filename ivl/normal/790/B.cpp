#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, k;
vector<int> E[200005];

class klasa{
public:

  ll sum;
  int num[5];

  klasa() : sum(0), num{0, 0, 0, 0, 0}{}

};

void lift(klasa &A){
  A.sum += A.num[k-1];
  REP(i,k-1) swap(A.num[k-i-1], A.num[k-i-2]);
  // swap(A.num[0], A.num[k-1]);
}

klasa merge(klasa A, klasa B){
  A.sum += B.sum;
  REP(i,k) A.num[i] += B.num[i];
  return A;
}

ll eval(klasa A, klasa B){
  ll sol = 0;
  int N = 0, M = 0;
  REP(i,k) N += A.num[i], M += B.num[i];
  sol += A.sum * M;
  sol += B.sum * N;
  REP(i,k) REP(j,k) sol += (ll)A.num[i] * B.num[j] * ((i+j+k-1) / k);
  return sol;
}

ll sol;

klasa dfs(int id, int p){

  vector<klasa> V;
  for (auto t : E[id]) if (t != p) V.pb(dfs(t, id));
  for (auto &t : V) lift(t);
  V.pb(klasa());
  V.back().num[0] = 1;

  klasa tmp;
  for (auto &t : V){
    sol += eval(tmp, t); // if (id == 1) TRACE(sol);
    tmp = merge(tmp, t);
  } return tmp;
  
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  REP(i,n-1){int u, v; cin >> u >> v; E[u].pb(v); E[v].pb(u);}
  dfs(1, 1);
  cout << sol << endl;
  
  return 0;
}