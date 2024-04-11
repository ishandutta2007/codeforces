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

int mods[] = {1000000007, 1000000009};
int pr = 1000033;
vector<vector<int>> powers;

int tmp_hash[2];

struct Block {
  int l, r;
  vector<int>& a;
  array<vector<int>, 2> lists;
  array<vector<array<int, 2>>, 2> hashes;
  bool is_good;
  Block(vector<int>& A, int L, int R): a(A), l(L), r(R) {
    is_good = true;
    for (int i = 0; i < 2; ++i) {
      lists[i].reserve(R - L);
      hashes[i].resize(R - L);
    }
  }
  void recalc() {
    is_good = true;
    for (int i = 0; i < 2; ++i) {
      lists[i].clear();
      hashes[i].clear();
    }
    for (int i = l; i < r; ++i) {
      if (a[i] > 0) {
        lists[1].push_back(a[i]);
      } else {
        if (lists[1].empty()) {
          lists[0].push_back(-a[i]);
          continue;
        }
        if (lists[1].back() != -a[i]) {
          is_good = false;
          return;
        }
        lists[1].pop_back();
      }
    }
    //cout << "recalc " << lists[0].size() << " " << lists[1].size() << endl;
    reverse(all(lists[0]));
    for (int i = 0; i < 2; ++i) {
      hashes[i].resize(lists[i].size() + 1);
      memset(tmp_hash, 0, sizeof(tmp_hash));
      hashes[i][0].fill(0);
      for (int j = 0; j < lists[i].size(); ++j) {
        for (int w = 0; w < 2; ++w) {
          hashes[i][j + 1][w] = (hashes[i][j][w] * 1LL * pr + lists[i][j]) % mods[w];
        }
      }
    }
  }

  li get_hash(int type, int L, int R) {
    for (int w = 0; w < 2; ++w) {
      tmp_hash[w] = (hashes[type][R][w] - hashes[type][L][w] * 1LL * powers[w][R - L]) % mods[w];
      if (tmp_hash[w] < 0) {
        tmp_hash[w] += mods[w];
      }
    }
    return tmp_hash[0] * (1LL << 32) + tmp_hash[1];
  }

};

struct Piece {
  int type;
  int block_num;
  int pref;
};

void solve(__attribute__((unused)) bool read) {
  int n, K;
  //read = false;
  if (read) {
    cin >> n >> K;
  } else {
    n = 100000;
    K = max(1, (int)sqrt(n));

    //n = rand() % 100000 + 1;
    //K = rand() % 100000 + 1;
  }

  if (powers.empty()) {
    powers.assign(2, vector<int>(n + 1, 1));
    for (int w = 0; w < 2; ++w) {
      for (int i = 1; i < powers[w].size(); ++i) {
        powers[w][i] = powers[w][i - 1] * 1LL * pr % mods[w];
      }
    }
  }

  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    if (read) {
      cin >> a[i];
    } else {
      int rem = i % (2 * K);
      if (rem < K) {
        a[i] = rem + 1;
      } else {
        a[i] = -(2 * K - rem);
      }
      //cout << a[i] << " ";
      /*a[i] = rand() % K + 1;
      if (rand() % 2) {
        a[i] = -a[i];
      }*/
    }
  }
  int block_size = max(1, (int)sqrt(n));
  //block_size = 3;
  int n_blocks = (n - 1) / block_size + 1;
  vector<Block> blocks;
  blocks.reserve(n_blocks);
  for (int i = 0; i < n_blocks; ++i) {
    blocks.emplace_back(a, min(i * block_size, n), min((i + 1) * block_size, n));
  }
  for (int i = 0; i < n_blocks; ++i) {
    blocks[i].recalc();
  }
  int Q;
  if (read) {
    cin >> Q;
  } else {
    Q = 100000;
  }
  vector<int> stack;
  stack.reserve(block_size * 4);
  vector<Piece> pieces;
  while (Q--) {
    int type;
    if (read) {
      cin >> type;
    } else {
      type = 2;
      if (rand() % 4 == 0) {
        type = 1;
      }
      type = 1;
    }
    if (type == 1) {
      int pos, val;
      if (read) {
        cin >> pos >> val;
        --pos;
      } else {
        pos = rand() % n;
        int rem = pos % (2 * K);
        if (rem < K) {
          val = rem + 1;
        } else {
          val = -(2 * K - rem);
        }
        /*val = rand() % K + 1;
        if (rand() % 2) {
          val = -val;
        }*/
      }
      a[pos] = val;
      blocks[pos / block_size].recalc();
    } else {
      int L, R;
      if (read) {
        cin >> L >> R;
        --L;
      } else {
        do {
          L = rand() % n; // (n / (2 * K));
          R = rand() % n; //(n / (2 * K));
        } while (L > R);
        /*int len = rand() % min(n, 6);
        L = rand() % (n - len + 1);
        R = L + len;*/
        ++R;
        R = min(R, n);
      }

      auto append_symbol = [&] (int val) {
        if (val > 0) {
          stack.push_back(val);
        } else {
          if (stack.empty() || stack.back() != -val) {
            return false;
          }
          stack.pop_back();
        }
        return true;
      };

      auto stupid_solve_query = [&] (int L, int R) {
        stack.clear();
        for (int i = L; i < R; ++i) {
          if (!append_symbol(a[i])) {
            return false;
          }
        }
        return stack.empty();
      };

      auto solve_query = [&] (int L, int R) {
        int l_block = L / block_size, r_block = R / block_size;
        if (l_block == r_block) {
          return stupid_solve_query(L, R);
        }

        for (int i = l_block + 1; i < r_block; ++i) {
          if (!blocks[i].is_good) {
            return false;
          }
        }

        pieces.clear();
        for (int i = l_block + 1; i < r_block; ++i) {
          auto& block = blocks[i];
          int cur_pref = block.lists[0].size();
          while (cur_pref > 0) {
            auto& back_piece = pieces.back();
            if (pieces.empty() || back_piece.type == 0) {
              pieces.push_back({0, i, cur_pref});
              break;
            }
            int min_len = min(back_piece.pref, cur_pref);
            if (blocks[back_piece.block_num].get_hash(1, back_piece.pref - min_len, back_piece.pref) ==
                block.get_hash(0, cur_pref - min_len, cur_pref)) {
              back_piece.pref -= min_len;
              cur_pref -= min_len;
              if (back_piece.pref == 0) {
                pieces.pop_back();
              }
            } else {
              return false;
            }
          }
          if (!block.lists[1].empty()) {
            pieces.push_back({1, i, (int) block.lists[1].size()});
          }
        }
        int sum_lens = 0;
        for (auto& item : pieces) {
          sum_lens += item.pref;
        }
        if (sum_lens > 2 * block_size) {
          return false;
        }
        stack.clear();
        for (int i = L; i < n && i < (l_block + 1) * block_size; ++i) {
          if (!append_symbol(a[i])) {
            return false;
          }
        }
        for (auto& item : pieces) {
          auto& vec = blocks[item.block_num].lists[item.type];
          if (item.type == 1) {
            for (int i = 0; i < item.pref; ++i) {
              if (!append_symbol(vec[i])) {
                return false;
              }
            }
          } else {
            for (int i = 0; i < item.pref; ++i) {
              if (!append_symbol(-vec[item.pref - i - 1])) {
                return false;
              }
            }
          }
        }
        for (int i = r_block * block_size; i < R; ++i) {
          if (!append_symbol(a[i])) {
            return false;
          }
        }
        return stack.empty();
      };

      int smart_solve = solve_query(L, R);

      //int stupid_solve = stupid_solve_query(L, R);

      //assert(stupid_solve == smart_solve);

      if (read) {
        if (smart_solve) {
          cout << "Yes\n";
        } else {
          cout << "No\n";
        }
      }

    }
  }

  if (!read) {
    cout << "ok\n";
  }

}