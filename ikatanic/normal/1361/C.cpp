#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

void euler_tour(int x, vector<vector<pair<int, int>>>& E, vector<bool>& used,
                vector<int>& ret) {
  while (E[x].size()) {
    auto p = E[x].back();
    E[x].pop_back();
    if (used[p.second / 2]) continue;

    used[p.second / 2] = true;

    euler_tour(p.first, E, used, ret);
    ret.push_back(p.second);
    ret.push_back(p.second ^ 1);
  }
}

vector<int> solve(vector<pair<int, int>>& A, int K) {
  int N = 1 << K;
  vector<vector<pair<int, int>>> E(N);
  for (int i = 0; i < (int)A.size(); ++i) {
    int x = A[i].first & ((1 << K) - 1);
    int y = A[i].second & ((1 << K) - 1);
    E[x].emplace_back(y, 2 * i + 1);
    E[y].emplace_back(x, 2 * i);
  }

  for (int i = 0; i < N; ++i)
    if (E[i].size() % 2) return {};

  int start = -1;
  for (int i = 0; i < N; ++i)
    if (E[i].size()) start = i;
  assert(start != -1);

  vector<int> ret;
  vector<bool> used(A.size(), false);
  euler_tour(start, E, used, ret);

  for (int i = 0; i < N; ++i)
    if (E[i].size()) return {};
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<pair<int, int>> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i].first >> A[i].second;
  }

  int k = 21;
  vector<int> ans;
  while (ans.empty()) {
    k--;
    ans = solve(A, k);
  }

  cout << k << "\n";
  for (int x : ans) cout << x + 1 << " ";
  cout << "\n";

  return 0;
}