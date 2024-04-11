#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
//#include "testlib.h"
#include <bits/stdc++.h>
#ifdef AIM
#include <sys/resource.h>
#endif
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

#ifdef AIM
  const rlim_t kStackSize = 256 * 1024 * 1024;
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0) {
    if (rl.rlim_cur < kStackSize) {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0) {
        fprintf(stderr, "setrlimit returned result = %d\n", result);
      }
    }
  }
#endif

  start = clock();
  int t = 1;
#ifndef AIM
  cout.sync_with_stdio(0);
  cin.tie(0);
#endif
  cout.precision(20);
  cout << fixed;
  //cin >> t;
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

mt19937 rng((unsigned long long)chrono::steady_clock::now().time_since_epoch().count());

void precalc() {

}

//#define int li
//const li mod = 1000000007;
//const int mod = 998244353;
//using ull = unsigned long long;

void solve(__attribute__((unused)) bool read) {
  int n, k;
  //read = false;
  if (read) {
    cin >> n >> k;
  } else {
    n = 200000;
    //n /= 10;
    k = 5;
  }
  vector<vector<int>> perms;
  {
    vector<int> perm(k);
    iota(all(perm), 0);
    do {
      perms.push_back(perm);
    } while (next_permutation(all(perm)));
    sort(all(perms));
  }
  auto get_index = [&] (vector<int>& perm) {
    auto it = lower_bound(all(perms), perm);
    assert(*it == perm);
    return (it - perms.begin());
  };
  vector<vector<int>> matrix(perms.size(), vector<int>(perms.size()));
  for (int i = 0; i < perms.size(); ++i) {
    for (int j = 0; j < perms.size(); ++j) {
      vector<int> perm(k);
      for (int r = 0; r < k; ++r) {
        perm[r] = perms[i][perms[j][r]];
      }
      matrix[i][j] = get_index(perm);
    }
  }

  vector<vector<int>> subgroups;
  vector<int> id_perm(perms.size(), 0);
  id_perm[0] = 1;
  subgroups.push_back(id_perm);

  auto get_new_subgroup = [&] (vector<int> subgroup, vector<int> have, int x) {
    auto cur_have = have;
    queue<int> q;
    vector<int> new_subgroup = subgroup;
    new_subgroup[x] = 1;
    cur_have.push_back(x);
    q.push(x);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      int old_size = cur_have.size();
      for (int j = 0; j < old_size; ++j) {
        int i = cur_have[j];
        for (int t = 0; t < 2; ++t) {
          int new_v = (t == 0 ? matrix[i][v] : matrix[v][i]);
          if (!new_subgroup[new_v]) {
            new_subgroup[new_v] = 1;
            q.push(new_v);
            cur_have.push_back(new_v);
          }
        }
      }
    }
    return new_subgroup;
  };

  while (true) {
    make_unique(subgroups);
    //cout << "cur_size: " << subgroups.size() << endl;
    vector<vector<int>> new_subgroups;
    for (auto subgroup : subgroups) {
      vector<int> have;
      for (int x = 0; x < perms.size(); ++x) {
        if (subgroup[x]) {
          have.push_back(x);
        }
      }
      for (int x = 0; x < perms.size(); ++x) {
        if (subgroup[x]) {
          continue;
        }
        auto new_subgroup = get_new_subgroup(subgroup, have, x);
        auto it = lower_bound(all(subgroups), new_subgroup);
        if (it == subgroups.end() || *it != new_subgroup) {
          new_subgroups.push_back(new_subgroup);
        }
      }
    }
    if (new_subgroups.empty()) {
      break;
    }
    make_unique(new_subgroups);
    for (auto item : new_subgroups) {
      subgroups.push_back(item);
    }
  }
  make_unique(subgroups);

  vector<vector<int>> sub_matrix(subgroups.size(), vector<int>(perms.size()));
  vector<int> bit_count(subgroups.size(), 0);
  for (int i = 0; i < subgroups.size(); ++i) {
    vector<int> have;
    for (int j = 0; j < perms.size(); ++j) {
      if (subgroups[i][j]) {
        have.push_back(j);
        ++bit_count[i];
      }
    }
    for (int j = 0; j < perms.size(); ++j) {
      auto new_sub = get_new_subgroup(subgroups[i], have, j);
      auto it = lower_bound(all(subgroups), new_sub);
      assert(it != subgroups.end() && *it == new_sub);
      sub_matrix[i][j] = (it - subgroups.begin());
    }
  }

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    vector<int> perm(k);
    for (int j = 0; j < k; ++j) {
      if (read) {
        cin >> perm[j];
        --perm[j];
      } else {
        perm[j] = j;
      }
    }
    if (!read) {
      random_shuffle(all(perm));
    }
    a[i] = get_index(perm);
  }

  li res = 0;
  vector<int> last_pos(perms.size(), -1);
  vector<int> next_occurence;
  vector<int> cur_iterate;
  cur_iterate.reserve(perms.size());

  for (int i = n - 1; i >= 0; --i) {
    if (last_pos[a[i]] != -1) {
      for (int j = 0; j < next_occurence.size(); ++j) {
        if (next_occurence[j] == last_pos[a[i]]) {
          next_occurence.erase(next_occurence.begin() + j);
          break;
        }
      }
    }
    last_pos[a[i]] = i;
    next_occurence.push_back(i);
    cur_iterate = next_occurence;
    reverse(all(cur_iterate));

    int current_group = 0;
    int border = i;

    for (int pos : cur_iterate) {
      if (subgroups[current_group][a[pos]]) {
        continue;
      }
      res += (pos - border) * 1LL * bit_count[current_group];
      current_group = sub_matrix[current_group][a[pos]];
      border = pos;
    }

    res += (n - border) * 1LL * bit_count[current_group];
    //cout << "calc: " << i << endl;

  }
  cout << res << "\n";
}