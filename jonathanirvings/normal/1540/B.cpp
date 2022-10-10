#include <bits/stdc++.h>
using namespace std;

constexpr int kMod = 1000000007;

template <typename T>
T pow(T a, int b) {
  if (b == 1) {
    return a;
  }
  T res = pow(a, b >> 1);
  res = res * res;
  if (b & 1) {
    res = res * a;
  }
  return res;
}

template <int MOD>
struct ModularInt {
  ModularInt() {}
  ModularInt(int num): num(num) {}

  void operator+=(const ModularInt& other) {
    num += other.num;
    if (num >= MOD) {
      num -= MOD;
    }
  }

  ModularInt operator+(const ModularInt& other) const {
    int res = num + other.num;
    if (res >= MOD) {
      res -= MOD;
    }
    return res;
  }

  ModularInt operator-(const ModularInt& other) const {
    int res = num - other.num + MOD;
    if (res >= MOD) {
      res -= MOD;
    }
    return res;
  }

  ModularInt operator*(const ModularInt& other) const {
    return (long long)num * other.num % MOD;
  }

  ModularInt operator/(const ModularInt& other) const {
    return (*this) * pow(other, MOD - 2);
  }

  int num;
};

typedef ModularInt<kMod> Int;

int main() {
  int N;
  scanf("%d", &N);

  vector<vector<Int>> prob(N, vector<Int>(N, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i == 0) {
        prob[i][j] = 1;
      } else if (j == 0) {
        prob[i][j] = 0;
      } else {
        prob[i][j] = (prob[i - 1][j] + prob[i][j - 1]) / 2;
      }
    }
  }

  vector<vector<int>> adj(N);
  vector<vector<int>> dist(N, vector<int>(N, INT_MAX >> 1));
  for (int i = 0; i < N; ++i) {
    dist[i][i] = 0;
  }
  for (int i = 0; i < N - 1; ++i) {
    int U, V;
    scanf("%d %d", &U, &V);
    --U; --V;
    adj[U].push_back(V);
    adj[V].push_back(U);
    dist[U][V] = dist[V][U] = 1;
  }
  for (int k = 0; k < N; ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  Int answer = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      function<void (int, int, int)> dfs = [&] (int u, int pt, int lst) {
        if (dist[i][u] + dist[u][j] == dist[i][j]) {
          lst = u;
        }
        answer += prob[dist[lst][j]][dist[lst][i]];
        for (int v : adj[u]) {
          if (v != pt) {
            dfs(v, u, lst);
          }
        }
      };

      dfs(j, INT_MIN, j);
    }
  }
  answer = answer / N;
  printf("%d\n", answer);
}