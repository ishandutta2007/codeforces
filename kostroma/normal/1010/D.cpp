#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
  freopen("/home/alexandero/CLionProjects/ACM/input.txt", "r", stdin);
//freopen("/home/alexandero/CLionProjects/ACM/output.txt", "w", stdout);
//freopen("out.txt", "w", stdout);
#else
  //freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#endif
  start = clock();
  int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif
  cout.precision(20);
  cout << fixed;
//cin  t;
  precalc();
  while (t--) {
    solve(true);
  }
  cout.flush();

#ifdef AIM1
  while (true) {
solve(false);
}
#endif

#ifdef AIM
  cerr << "\n\n time: " << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif
  return 0;
}

//BE CAREFUL: IS INT REALLY INT?

template<typename T>
T binpow(T q, T w, T mod) {
  if (!w)
    return 1 % mod;
  if (w & 1)
    return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template<typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}

template <typename T>
void make_unique(vector<T>& vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
}

template<typename T>
void relax_min(T& cur, T val) {
  cur = min(cur, val);
}

template<typename T>
void relax_max(T& cur, T val) {
  cur = max(cur, val);
}

void precalc() {

}

//#define int li
//const li mod = 1000000007;

//using ull = unsigned long long;

enum Type {
  AND,
  OR,
  XOR,
  NOT,
  IN
};

vector<Type> types;
vector<vector<int>> g;
vector<int> val;
vector<int> val_changed;
vector<int> parent;

int dfs(int v, int p) {
  parent[v] = p;
  if (types[v] == IN) {
    return val[v];
  }
  if (types[v] == NOT) {
    return val[v] = !dfs(g[v][0], v);
  }
  if (types[v] == AND) {
    return val[v] = dfs(g[v][0], v) & dfs(g[v][1], v);
  }
  if (types[v] == OR) {
    return val[v] = dfs(g[v][0], v) | dfs(g[v][1], v);
  }
  if (types[v] == XOR) {
    return val[v] = dfs(g[v][0], v) ^ dfs(g[v][1], v);
  }
}

void dfs_ans(int v) {
  if (v == 0) {
    val_changed[v] = val[v] ^ 1;
  } else {
    int p = parent[v];
    int new_val = (val[v] ^ 1);
    if (types[p] == NOT) {
      val_changed[v] = val_changed[p];
    } else {
      int diff_val = ((g[p][0] == v) ? val[g[p][1]] : val[g[p][0]]);
      int parent_val = val[p];
      if (types[p] == AND) {
        parent_val = diff_val & new_val;
      }
      if (types[p] == OR) {
        parent_val = diff_val | new_val;
      }
      if (types[p] == XOR) {
        parent_val = diff_val ^ new_val;
      }
      if (parent_val != val[p]) {
        val_changed[v] = val_changed[p];
      } else {
        val_changed[v] = val[0];
      }
    }
  }
  for (int to : g[v]) {
    dfs_ans(to);
  }
}

void solve(bool read) {
  int n;
  cin >> n;
  types.resize(n);
  g.clear();
  g.resize(n);
  val.resize(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "IN") {
      types[i] = IN;
      cin >> val[i];
    } else if (s == "NOT") {
      types[i] = NOT;
      int cur;
      cin >> cur;
      --cur;
      g[i].push_back(cur);
    } else {
      switch(s[0]) {
        case 'A':
          types[i] = AND;
          break;
        case 'O':
          types[i] = OR;
          break;
        case 'X':
          types[i] = XOR;
          break;
        default:
          assert(false);
      }
      g[i].resize(2);
      for (int j = 0; j < 2; ++j) {
        cin >> g[i][j];
        --g[i][j];
      }
    }
  }
  parent.resize(n);
  dfs(0, 0);
  val_changed.resize(n);
  dfs_ans(0);

  for (int i = 0; i < n; ++i) {
    if (types[i] == IN) {
      cout << val_changed[i];
    }
  }
  cout << "\n";

}