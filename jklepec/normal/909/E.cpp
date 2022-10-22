#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<


const int MAXN = 1e5 + 5;

int D[MAXN];
vector<int> e[MAXN];
vector<int> tobe;
queue<int> todo;

int type[MAXN];
int solved;

void dfs(int x) {
  D[x] --;
  if(D[x] == 0) {
    solved ++;
    if(!type[x]) {
      todo.push(x);
    }
    else {
      for(auto y: e[x]) {
        dfs(y);
      }
    }
  }
}

int main() {
  int n, m; cin >> n >> m;

  REP(i, n) {
    cin >> type[i];
  }

  REP(i, m) {
    int x, y; cin >> x >> y;

    e[y].push_back(x);
    D[x] ++;
  }

  int K = 0;

  REP(i, n) {
    if(D[i] == 0) {
      if(!type[i]) {
        todo.push(i);
        solved ++;
      }
      else {
        tobe.push_back(i);
      }
    }
  }

  while(solved < n) {
    while(todo.size()) {
      int x = todo.front();
      todo.pop();

      for(auto y: e[x]) {
        D[y] --;
        if(D[y] == 0) {
          if(!type[y]) {
            todo.push(y);
            solved ++;
          }
          else {
            tobe.push_back(y);
          }
        }
      }
    }

    if(solved < n) {
      K ++;
      for(auto x: tobe) {
        D[x] ++;
        dfs(x);
      }
      tobe.clear();
    }
  }

  cout << K;
}