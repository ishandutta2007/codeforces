#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <set>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

void answer(int x) {
  printf("! %d\n", x+1);
  fflush(stdout);
}

int cnt = 0;

map<int, vector<int>> cache;

int DEBUG = 0;

vector<int> E[11111];
int n;

vector<int> query(int x) {
  if (cache.count(x)) return cache[x];
  
  cnt++;

  if (DEBUG) {
    vector<int> ret = E[x+1];
    for (int& x: ret) --x;
    return cache[x] = ret;       
  } 
  printf("? %d\n", x+1);
  fflush(stdout);
  int k;
  scanf("%d", &k);
  if (k == 0) exit(0);
  
  vector<int> ret(k);
  REP(i, k) {
    scanf("%d", &ret[i]);
    --ret[i];
  }
  return cache[x] = ret;       
}

int explore(int x, int prev, int& ret, vector<int>& path) {
  path.push_back(x);
  vector<int> y = query(x);
  if (y.size() == 2) { ret = x; return 0; }
  if (y.size() == 1) return 1;
  return 1 + explore(y[ y[0] == prev ], x, ret, path);
}

int dfs(int x, int k, set<int>& bio) {
  if (cnt == 16 && !cache.count(x)) return x;
  
  vector<int> y = query(x);
  if (y.size() == 2) return x;
  bio.insert(x);

  if (k > 0) {
    for (int yy: y) {
      if (!bio.count(yy)) {
        int r = dfs(yy, k-1, bio);
        if (r != -1) return r;
      }
    }
  }
  return -1;
}

int solve(int h) {
  cnt = 0;
  cache.clear();
  
  int x = 0;
  int ret = -1;
  
  vector<int> y = query(x);
  if (y.size() == 2) return x;

  set<int> bio;
  bio.insert(x);
  
  int d = -1;
  if (y.size() == 1) {
    d = 2;
    x = y[0];
    bio.insert(y[0]);
  } else {
    vector<int> path1, path2;
    int d1 = explore(y[0], x, ret, path1);
    if (ret != -1) return ret;
    int d2 = explore(y[1], x, ret, path2);
    if (ret != -1) return ret;
    
    if (d1 == d2) {
      d = d1 + 2;
      x = y[2];
    } else if (d1 > d2) {
      int gap = (d1 - d2 - 2) / 2;
      d = d2 + 1 + gap + 1;
      assert(gap < (int)path1.size());
      x = path1[gap];
    } else {
      int gap = (d2 - d1 - 2) / 2;
      d = d1 + 1 + gap + 1;
      assert(gap < (int)path2.size());
      x = path2[gap];
    }
    for (int yy: path1) bio.insert(yy);
    for (int yy: path2) bio.insert(yy);

    bio.insert(y[0]);
    bio.insert(y[1]);
    bio.insert(y[2]);
  }
  
  while (true) {
    if (d == h) return x;
    vector<int> y = query(x);
    vector<int> ny;
    for (int yy: y)
      if (!bio.count(yy)) ny.push_back(yy);
    assert(ny.size() > 0);

    
    assert(d < h);
    assert(d > 1);

    if (cnt + ny.size()*((1<<(h-d))-1) - 1 <= 16) {
      ret = dfs(x, h-d, bio);
      assert(ret != -1);
      return ret;
    }


    if (ny.size() == 1) {
      x = ny[0];
      d++;
      bio.insert(x);
    } else {
      assert(ny.size() == 2);
      
      vector<int> path;
      int d1 = explore(ny[0], x, ret, path);
      if (ret != -1) return ret;

      for (int yy: path) bio.insert(yy);
      
      if (d1 == d-1) {
        x = ny[1];
        d++;
        bio.insert(x);
      } else {
        int gap = (d1 - d - 1) / 2;
        d += gap + 1;
        assert(gap < (int)path.size());
        x = path[gap];
      }
    }
  }

  assert(false);
  return 0;
}


int main(void) {
  if (DEBUG) {
    while (true) {
      int h = (rand() % 6) + 2;
      
      n = 1<<h;
      REP(i, n) E[i].clear();
      map<int, int> remap;
      vector<int> idx;
      REP(i, n-1) idx.push_back(i+1);
      random_shuffle(idx.begin(), idx.end());
      FOR(i, 1, n) remap[i] = idx[i-1];
    
      FOR(i, 1, n) REP(j, 2)
        if (i*2+j < n) {
          E[remap[i]].push_back(remap[i*2+j]);
          E[remap[2*i+j]].push_back(remap[i]);
          
        }
      REP(i, n) {
        random_shuffle(E[i].begin(), E[i].end());
      }
      

      assert(solve(h) == idx[0]-1);
      assert(cnt <= 16);
      
    }
  
    return 0;
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int h;
    scanf("%d", &h);
    if (h == 0) return 0;
    
    answer(solve(h));
  }
  
  return 0;
}