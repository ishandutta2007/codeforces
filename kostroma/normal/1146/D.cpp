#pragma comment(linker, "/STACK:512000000")
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

//#define int li
//const int mod = 1000000007;

const int C = 2000500;
char used[C];
char new_border[C];

void solve(__attribute__((unused)) bool read) {
  int a, b;
  li m;
  if (read) {
    cin >> m >> a >> b;
  } else {
    m = rand() % (int)1e9 + 1;
    a = rand() % (int)1e5 + 1;
    b = rand() % (int)1e5 + 1;
    cout << m << " " << a << " " << b << endl;
  }
  int g = gcd(a, b);
  memset(used, false, sizeof used);
  memset(new_border, false, sizeof new_border);
  used[0] = true;
  new_border[a] = true;
  li cur_res = 1;
  li x = 0;
  li ans = 0;
  queue<int> q;
  for (int pos = 1; pos < C && pos <= m + 1; ++pos) {
    ans += cur_res;
    if (pos > m) {
      x = pos;
      break;
    }
    if (!new_border[pos]) {
      x = pos;
      continue;
    }
    li coord = pos;
    used[coord] = true;
    q.push(coord);
    used[coord] = true;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      if (v + a > coord && v + a < C) {
        new_border[v + a] = true;
      }
      ++cur_res;
      if (v + a <= coord && !used[v + a]) {
        used[v + a] = true;
        q.push(v + a);
      }
      if (v >= b && !used[v - b]) {
        q.push(v - b);
        used[v - b] = true;
      }
    }
    x = coord;
    //cout << x << " " << cur_res << " " << ans << endl;
  }
  if (x <= m) {
    li last_ans = m / g + 1;
    //cout << x << " " << m << " " << ans << " " << last_ans << endl;
    while (m % g) {
      if (x > m) {
        break;
      }
      ans += last_ans;
      --m;
    }
    if (x % g) {
      while (x % g) {
        if (x > m) {
          break;
        }
        ans += cur_res;
        ++x;
      }
      ++cur_res;
    }
    if (x <= m) {
      ans += last_ans;
      //cout << x << " " << cur_res << " " << m << " " << last_ans << endl;
      assert(cur_res == x / g + 1 && cur_res <= last_ans);
      ans += ((last_ans - 1) * last_ans / 2 - (cur_res - 1) * cur_res / 2) * (1LL * g);
    }
  }
  cout << ans << endl;
}