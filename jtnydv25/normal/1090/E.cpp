#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define S2(x,y) scanf("%d%d",&x,&y)
#define P(x) printf("%d\n",x)
#define all(v) v.begin(),v.end()
#define FF first
#define SS second
#define pb push_back
#define mp make_pair

typedef long long int LL;
typedef pair<int, int > pii;
typedef vector<int > vi;

int dx[8] = {  2, 1, -1, -2, -2, -1,  1,  2 }; 
int dy[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
int X[128] = {0,0,2,1,4,2,6,3,7,5,6,7,4,6,2,7,0,6,1,4,3,5,5,6,7,7,6,5,5,7,3,6,1,7,0,5,2,6,4,7,5,5,7,6,6,4,4,5,6,6,5,4,3,3,2,5,3,7,1,6,0,4,1,2,2,4,0,3,1,1,3,0,2,2,1,0,0,2,2,3,4,4,3,2,4,0,6,1,7,3,5,2,7,1,5,0,3,1,4,3,5,1,7,0,6,2,7,4,5,3,7,2,6,0,4,1,2,0,0,1,1,3,3,4,1,5,0,7};

int board[8][8], fix[8][8], P[8][8], req[8][8];
bool vis[8][8];
vector<string > moves;
queue<pii > q;

pii getXY(string s) {
  return mp(s[0] - 'a', s[1] - '1');
}

string getString(pii p) {
  string res;
  res += p.FF + 'a';
  res += p.SS + '1';
  return res;
}

void bfs(int x, int y) {
  memset(vis, 0, sizeof(vis));
  q.push(mp(x, y));
  vis[x][y] = true;
  bool found = false;
  while(q.size()) {
    pii p = q.front();
    int a = p.FF, b = p.SS;
    q.pop();
    if(board[a][b]) {
      board[a][b] = 0;
      found = true;
      while(a != x || b != y) {
        int c = a - dx[P[a][b]];
        int d = b - dy[P[a][b]];
        moves.pb(getString(mp(a,b)) + "-" + getString(mp(c, d)));
        a = c; b = d;
      }
      break;
    }

    rep(i,0,8) {
      int c = a + dx[i];
      int d = b + dy[i];
      if(c < 0 || c >= 8 || d < 0 || d >= 8) continue;
      if(vis[c][d]) continue;
      if(fix[c][d]) continue;
      P[c][d] = i;
      vis[c][d] = true;
      q.push(mp(c, d));
    }
  }

  assert(found);

  while(q.size()) q.pop();

}

vector<pii > path;
bool dfs(int a, int b, int dep) {
  assert(dep < 64);
  P((int)path.size());
  rep(i,0,8) {
    int c = a + dx[i];
    int d = b + dy[i];
    // if(a == 7 && b == 0) printf("yahan %d %d\n",c,d);
    if(c < 0 || c >= 8 || d < 0 || d >= 8) continue;
    if(vis[c][d]) continue;
    vis[c][d] = true;
    path.pb(mp(c, d));
    if(path.size() == 64) return true;
    if(dfs(c, d, dep + 1)) {
      return true;
    }
    path.pop_back();
    vis[c][d] = false;
  }
  return false;
}

int getDist(int a, int b) {
  return min(min(a + b, a + 7 - b), min(7 - a + b, 7 - a + 7 - b));
}

int main() {
  for(int i = 0; i < 128; i += 2) {
    path.pb(mp(X[i], X[i + 1]));
  }

  int n;
  S(n);
  rep(i,0,n) {
    string s;
    cin >> s;
    pii p = getXY(s);
    board[p.FF][p.SS] = 1;
  }
  int cp = n;
  rep(j,0,8) if(cp) {
    rep(i,0,8) if(cp) {
      cp--;
      req[i][j] = 1;
    }
  }

  vector<pii > wait;
  rep(i,0,path.size()) {
    int x = path[i].FF;
    int y = path[i].SS;
    if(req[x][y]) {
      // printf("%d %d\n",x,y);
      bool found = false;
      rep(j,0,path.size()) {
        int a = path[j].FF;
        int b = path[j].SS;
        if(board[a][b]) {
          if(j < i) {
            wait.pb(mp(j, i));
          } else {
            for(int k = j; k > i; k--) {
               moves.pb(getString(path[k]) + "-" + getString(path[k - 1]));
            }
          }
          board[a][b] = 0;
          found = true;
          break;
        }
      }
      assert(found);
    }
  }

  for(int itr = (int)wait.size() - 1; itr >= 0; itr--) {
    int i = wait[itr].SS;
    int j = wait[itr].FF;
    for(int k = j; k < i; k++) {
       moves.pb(getString(path[k]) + "-" + getString(path[k + 1]));
    }
  }

  P((int)moves.size());
  rep(i,0,moves.size()) cout << moves[i] << "\n";
  return 0;
}