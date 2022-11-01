#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>
#include <bitset>

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)

#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MAX = 505;

int n;
int dist[MAX][MAX], e[MAX][MAX];
bitset <MAX> B[MAX][MAX];

void fw() {
  REP(i, MAX) REP(j, MAX) dist[i][j] = 1e9;
  REP(i, MAX) dist[i][i] = 0;
  REP(i, MAX) REP(j, MAX) if (e[i][j]) dist[i][j] = dist[j][i] = 1;
  REP(i, MAX) REP(j, MAX) REP(k, MAX)
    dist[j][k] = min(dist[j][k], dist[k][i] + dist[i][j]);
}

void input_graph() {
  int m;
  scanf("%d%d", &n, &m);

  REP(i, m) {
    int x;
    int p[MAX];
    scanf("%d", &x);
    REP(j, x) { scanf("%d", &p[j]); p[j]--; }
    REP(j, x-1) e[p[j]][p[j+1]] = e[p[j+1]][p[j]] =1 ;    
  }
}

int n_guess;

char ss[10];
int q(int nod) {
  assert(n_guess++ < 10);
  printf("%d\n", nod+1);
  fflush(stdout);
  
  scanf(" %s", ss);

  if (ss[0] == 'F') return -1;
  int x;
  scanf(" %d", &x);
  return x-1;
}

bitset <MAX> ziv;
vector <int> V[MAX];

int get_node() {
  int ret = -1, best = 1e6;
  REP(i, n) {
    int mx = 0;
    //    REP(j, n) {
    for (auto j : V[i]) {
      int bio = ziv[i];
      ziv[i] = 0;

      //      bitset <MAX> a = B[j][i] & ziv;
      //      int tmp = (int) a.count();
      //      if (i == 2) TRACE(
      bitset <MAX> A = B[j][i] & ziv;
      mx = max(mx, (int) A.count());

      ziv[i] = bio;
    }

    //    TRACE(i _ mx);

    if (mx < best) {
      ret = i;
      best = mx;
    }
  }

  //  TRACE(ret _ best);
  assert(ret != -1);
  return ret;  
}

void izbaci(int node, int blizi) {
  REP(i, n)
    if (dist[node][i] <= dist[blizi][i]) {
      ziv[i] = 0;
      //      TRACE("van" _ i+1);
    }
}

int main(){
  ios_base::sync_with_stdio(false);

  input_graph();
  REP(i, n) REP(j, n) if (e[i][j]) V[i].push_back(j);
  fw();
  REP(i, n) REP(j, n) REP(k, n)
    if (dist[i][k] < dist[j][k]) B[i][j][k] = 1;
  
  REP(tt, n) {
    n_guess = 0;
    REP(i, n) ziv[i] = 1;
    
    for (;;) {      
      int tmp = get_node();
      int koji = q(tmp);
      if (koji == -1) break;
      
      izbaci(tmp, koji);
    }
  }  
  
  return 0;
}