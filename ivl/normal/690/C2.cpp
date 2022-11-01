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
typedef pair < int, int > pii;

int n, m;
vector < int > E[100005];

int MAX = 0;

int DFS(int id, int p){
  pii tmp = {0, 0};
  for (auto t : E[id]) if (t != p){
      int a = 1+DFS(t, id);
      if (a > tmp.y) tmp.y = a;
      if (a > tmp.x) tmp.y = tmp.x, tmp.x = a;
    }
  MAX = max(MAX, tmp.x + tmp.y);
  return tmp.x;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  REP(i,m){int a, b; cin >> a >> b; E[a].pb(b), E[b].pb(a);}
  DFS(1, 1);
  cout << MAX << endl;
  
  return 0;
}