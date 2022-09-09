#pragma comment(linker, "/STACK:512000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#ifdef AIM
#include <sys/resource.h>
#endif
using namespace std;

#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(__attribute__((unused)) bool);
void precalc();
clock_t start;
#define FILENAME ""

int main() {
#ifdef AIM
  string s = FILENAME;
//    assert(!s.empty());
  freopen("/home/alexandero/ClionProjects/cryptozoology/input.txt", "r", stdin);
  //freopen("/home/alexandero/ClionProjects/cryptozoology/output.txt", "w", stdout);
#else
//    freopen(FILENAME ".in", "r", stdin);
//    freopen(FILENAME ".out", "w", stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    start = clock();
    int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif

#ifdef AIM
  const rlim_t kStackSize = 256 * 1024 * 1024;
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

  precalc();
  cout.precision(10);
  cout << fixed;
  //cin >> t;
  int testNum = 1;
  while (t--) {
      //cout << "Case #" << testNum++ << ": ";
      solve(true);
  }
  cout.flush();
#ifdef AIM1
    while (true) {
      solve(false);
  }
#endif

#ifdef AIM
  cout.flush();
  auto end = clock();

  usleep(10000);
  print_stats(end - start);
  usleep(10000);
#endif

    return 0;
}

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
void make_unique(vector<T>& a) {
    sort(all(a));
    a.erase(unique(all(a)), a.end());
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

#define int li
//const int mod = 1000000007;

vector<int> get_stupid(vector<int> a) {
  while (true) {
    bool have = false;
    for (int i = 0; i + 1 < a.size(); ++i) {
      int diff = a[i + 1] - a[i];
      if (diff > 1) {
        a[i] += diff / 2;
        a[i + 1] -= diff / 2;
        have = true;
      }
    }
    if (!have) {
      break;
    }
  }
  return a;
}

void solve(__attribute__((unused)) bool read) {
  int n;
  if (read) {
    cin >> n;
  } else {
    n = rand() % 10 + 1;
  }
  vector<int> a(n);
  if (read) {
    for (int &x : a) {
      cin >> x;
    }
  } else {
    bool good;
    do {
      good = true;
      for (int i = 0; i < n; ++i) {
        a[i] = rand() % 100;
      }
      sort(all(a));
      for (int i = 0; i + 1 < n; ++i) {
        if (a[i] == a[i + 1]) {
          good = false;
          break;
        }
      }
    } while (!good);
  }

  //auto stupid = get_stupid(a);

  int st = a[0], fin = a[0];
  int selected = -1;
  for (int w = 1; w < n; ++w) {
    int next_val = a[w];
    if (selected != -1) {
      int need_steps = fin - selected + 1;
      int have_steps = next_val - fin - 1;
      ++fin;
      if (have_steps >= need_steps) {
        selected = -1;
        next_val -= need_steps;
      } else {
        selected += have_steps;
        continue;
      }
    }
    if (fin == next_val) {
      selected = fin;
      continue;
    }
    int k = (next_val - fin) / (fin - st + 2);
    st += k;
    fin += k;
    next_val -= (fin - st + 1) * k;
    if (next_val == fin) {
      selected = fin;
    } else if (next_val == fin + 1) {
      ++fin;
      selected = -1;
    } else {
      int rest = next_val - fin - 1;
      selected = st + rest;
      ++st;
      ++fin;
    }
  }
  vector<int> res;
  for (int i = st; i <= fin; ++i) {
    res.push_back(i);
    if (i == selected) {
      res.push_back(i);
    }
  }
#if 0
  if (res != stupid) {
    cout << "FOUND" << endl;
    cout << n << endl;
    for (int x : a) {
      cout << x << " ";
    }
    cout << endl;
    cout << "stupid: ";
    for (int x : stupid) {
      cout << x << " ";
    }
    cout << endl;
    cout << "res: ";
    for (int x : res) {
      cout << x << " ";
    }
    cout << endl;
    exit(0);
  } else {
    cout << "ok\n";
  }
#endif

  for (int x : res) {
    cout << x << " ";
  }
  cout << endl;
}