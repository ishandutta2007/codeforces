#pragma comment(linker, "/STACK:512000000")
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <memory>
#include <chrono>
#include <cassert>
#include <random>
#include <queue>
#include <set>
#include <map>
#include <array>
#ifdef AIM
#include <sys/resource.h>
#endif
#include <cstdlib>

using namespace std;

#define all(a) a.begin(), a.end()
using li = long long;
using ld = long double;
void solve(bool);
void precalc();
clock_t start;
int main() {
#ifdef AIM
    //freopen("/Users/alexandero/CLionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/Users/alexandero/CLionProjects/cryptozoology/output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;

#ifdef AIM
  const rlim_t kStackSize = 60 * 1024 * 1024;   // min stack size = 16 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
      {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif
#ifndef AIM
    cout.sync_with_stdio(0);
    cin.tie(0);
#endif
    cout.precision(20);
    cout << fixed;
    //cin >> t;
    precalc();
    int test_num = 1;
    while (t--) {
      //cout << "Case #" << test_num++ << ": ";
      solve(true);
    }
    cout.flush();

#ifdef AIM
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

mt19937 rng(100 /*(unsigned long long)chrono::steady_clock::now().time_since_epoch().count()*/);

void precalc() {

}

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

bool local = false;

int n;

vector<int> P;

void generate() {
  n = rand() % 5 + 2;
  P.resize(n);
  iota(all(P), 1);
  shuffle(all(P), rng);
}

int qs = 0;

int get_res(vector<int> a) {
  ++qs;
  assert(qs <= 2 * n);
  for (auto x : a) {
    assert(x >= 1 && x <= n);
  }
  if (local) {
    assert(a.size() == n);
    map<int, int> pos;
    int min_val = n;
    for (int i = 0; i < n; ++i) {
      int s = P[i] + a[i];
      if (pos.count(s)) {
        relax_min(min_val, pos[s]);
      } else {
        pos[s] = i;
      }
    }
    if (min_val == n) {
      return 0;
    }
    return min_val + 1;
  } else {
    cout << "? ";
    for (auto x : a) {
      cout << x << " ";
    }
    cout << endl;
    int res;
    cin >> res;
    return res;
  }
}

void print(vector<int> p) {
  if (local) {
    if (p == P) {
      cout << "ok" << endl;
    } else {
      cout << "bug " << endl;
      cout << "p:" << endl;
      for (int x : P) {
        cout << x << " " ;
      }
      cout << endl;
      cout << "output:" << endl;
      for (int x : p) {
        cout << x << " " ;
      }
      cout << endl;
      exit(0);
    }
  } else {
    cout << "! ";
    for (int x : p) {
      cout << x << " ";
    }
    cout << endl;
  }
}

void solve(__attribute__((unused)) bool read) {
  qs = 0;
  if (local) {
    generate();
  } else {
    cin >> n;
  }
  vector<int> diffs(n, -1);
  vector<int> p(n, -1);
  for (int add = 2; add <= n; ++add) {
    vector<int> query(n, 1);
    query.back() = add;
    int k = get_res(query);
    if (k == 0) {
      query.assign(n, -1);
      vector<int> search;
      query[n - 1] = 1;
      p[n - 1] = n + 2 - add;
      for (int i = 0; i < n - 1; ++i) {
        if (diffs[i] != -1) {
          p[i] = p[n - 1] + diffs[i];
          query[i] = n;
        } else {
          search.push_back(i);
        }
      }
      /*for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
      }
      cout << endl;*/
      for (int need = p[n - 1] - 1; need >= 1; --need) {
        for (int x : search) {
          query[x] = p[n - 1] - need + 1;
        }
        int pos = get_res(query);
        //cout << need << " " << pos << endl;
        assert(pos > 0);
        --pos;
        p[pos] = need;
        //search.erase(find(all(search), pos));
        //query[pos] = n;
      }
      print(p);
      return;
    } else {
      --k;
      diffs[k] = add - 1;
    }
  }
  p[n - 1] = 1;
  for (int i = 0; i + 1 < n; ++i) {
    p[i] = p[n - 1] + diffs[i];
  }
  print(p);

}