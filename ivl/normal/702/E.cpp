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

class Node{
public:
  int id;
  ll w;
  int mini;
  Node(int _id = -1, ll _w = 0, int _mini = 1e9) : id(_id), w(_w), mini(_mini){}
};

Node operator+(Node a, Node b){return {b.id, a.w + b.w, min(a.mini, b.mini)};}

int n; ll k;
int f[100005];
int w[100005];

Node LCA[50][100005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> k;
  REP(i,n) cin >> f[i], LCA[0][i].id = f[i];
  REP(i,n) cin >> w[i], LCA[0][i].w = LCA[0][i].mini = w[i];

  FOR(i,1,50) REP(j,n) LCA[i][j] = LCA[i-1][j] + LCA[i-1][LCA[i-1][j].id];

  REP(i,n){
    Node R(i);
    REP(j,50) if ((k>>j)&1) R = R + LCA[j][R.id];
    cout << R.w << " " << R.mini << endl;
  }

  return 0;
}