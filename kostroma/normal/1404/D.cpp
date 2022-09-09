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
#ifdef AIM
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

//#define int li
//const int mod = 1000000007;

void solve(__attribute__((unused)) bool read) {
  //read = false;

  int n;
  if (read) {
    cin >> n;
  } else {
    n = 499999;
  }
  if (n % 2 == 1) {
    cout << "Second" << endl;
    vector<vector<int>> data(n);
    n *= 2;
    vector<int> which(n + 1, -1);

#if 1
    vector<int> perm(n);
    for (int i = 0; i < n; ++i) {
      perm[i] = i / 2;
    }
    random_shuffle(all(perm));
#endif

    for (int i = 0; i < n; ++i) {
      int pos;
      if (read) {
        cin >> pos;
        --pos;
      } else {
        pos = perm[i];
      }
      which[i + 1] = pos;
      data[pos].push_back(i + 1);
    }
    vector<char> used(n / 2, false);
    vector<int> res;
    for (int ii = 0; ii < n / 2; ++ii) {
      int i = ii;
      if (used[i]) {
        continue;
      }
      used[i] = true;
      do {
        int a = data[i][0], b = data[i][1];
        res.push_back(a);
        if (b > n / 2) {
          b -= n / 2;
        } else {
          b += n / 2;
        }
        int next_pair = which[b];
        if (b != data[next_pair][0]) {
          swap(data[next_pair][0], data[next_pair][1]);
        }
        //cout << "i: " << i << " next: " << next_pair << " a: " << a << endl;
        i = next_pair;
        used[i] = true;
      } while (i != ii);
    }

    int sum = 0;
    for (int x : res) {
      sum = (sum + x) % n;
    }
    if (sum != 0) {
      vector<char> have(n + 1, false);
      for (int x : res) {
        have[x] = true;
      }
      res.clear();
      for (int i = 1; i <= n; ++i) {
        if (!have[i]) {
          res.push_back(i);
        }
      }
    }
    for (int x : res) {
      cout << x << " ";
    }
    cout << endl;
    return;
  }

  cout << "First" << endl;
  n *= 2;
  int k = 0;
  int s = n;
  while (s % 2 == 0) {
    ++k;
    s /= 2;
  }
  s *= 2;
  --k;

  vector<int> res;
  if (k > 0) {
    int step = (1 << (k - 1));
    for (int m = 1; m * step < n; m += 2) {
      res.push_back(step * m);
    }
  }
  int step = (1 << k);
  for (int val = step; val <= n; val += step) {
    res.push_back(val);
  }
  if (k > 0) {
    vector<char> used(n, false);
    for (int val = 1; val <= n; ++val) {
      if (val % step == 0 || val % step == (1 << (k - 1))) {
        continue;
      }
      if (!used[val]) {
        res.push_back(val);
        res.push_back(val + (1 << k));
        used[val]  =used[val + (1 << k)] = true;
      }
    }
  }

  vector<int> pos(n, -1);
  for (int i = 0; i < res.size(); ++i) {
    pos[res[i] - 1] = i / 2 + 1;
  }
  for (int x : pos) {
    cout << x << " ";
  }
  cout << endl;

  int ok;
  cin >> ok;

}