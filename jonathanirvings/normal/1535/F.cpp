#include <bits/stdc++.h>
using namespace std;

constexpr int kMaxN = 200000;
constexpr int kHybridLimit = 10000;
constexpr int kNonAnagramCost = 1337;
constexpr long long kHash = 99999999999999997LL;

string get_string() {
  char tmp[kMaxN + 5];
  scanf("%s", tmp);
  return tmp;
}

int main() {
  int N;
  scanf("%d", &N);

  map<string, vector<string>> sorted;
  for (int i = 0; i < N; ++i) {
    string S = get_string();
    string T = S;
    sort(T.begin(), T.end());
    sorted[T].push_back(S);
  }
  long long ans = 0;
  long long anagram_pairs = 0;
  for (const auto &p : sorted) {
    vector<string> anagram = p.second;
    int R = anagram.size();
    int C = anagram[0].size();
    anagram_pairs += (long long)R * (R - 1) >> 1;

    if (R <= kHybridLimit) {
      vector<vector<long long>> prefix(R, vector<long long>(C));
      for (int i = 0; i < R; ++i) {
        prefix[i][0] = anagram[i][0] - 'a';
        for (int j = 1; j < C; ++j) {
          prefix[i][j] = (prefix[i][j - 1] * 26 + anagram[i][j] - 'a') % kHash;
        }
      }

      vector<vector<long long>> suffix(R, vector<long long>(C));
      vector<vector<int>> increasing_until(R, vector<int>(C));
      for (int i = 0; i < R; ++i) {
        increasing_until[i][C - 1] = C - 1;
        suffix[i][C - 1] = anagram[i][C - 1] - 'a';
        for (int j = C - 2; j >= 0; --j) {
          if (anagram[i][j] <= anagram[i][j + 1]) {
            increasing_until[i][j] = increasing_until[i][j + 1];
          } else {
            increasing_until[i][j] = j;
          }
          suffix[i][j] = (suffix[i][j + 1] * 26 + anagram[i][j] - 'a') % kHash;
        }
      }

      for (int i = 0; i < R; ++i) {
        for (int j = i + 1; j < R; ++j) {
          int pre = -1;
          int L = 0;
          int R = C - 2;
          while (L <= R) {
            int M = (L + R) >> 1;
            if (prefix[i][M] == prefix[j][M]) {
              pre = M;
              L = M + 1;
            } else {
              R = M - 1;
            }
          }
          int suf =
              max(increasing_until[i][pre + 1], increasing_until[j][pre + 1]);
          if (suf == C - 1 || suffix[i][suf + 1] == suffix[j][suf + 1]) {
            ans += 1;
          } else {
            ans += 2;
          }
        }
      }
    } else {
      map<string, int> string_index;
      for (int i = 0; i < anagram.size(); ++i) {
        string_index[anagram[i]] = i;
      }
      set<pair<int, int>> low_cost_pairs;
      for (int i = 0; i < R; ++i) {
        for (int l = 0; l < C; ++l) {
          string s = anagram[i];
          for (int r = l + 1; r < C; ++r) {
            for (int k = r; k > l; --k) {
              if (s[k - 1] > s[k]) {
                swap(s[k - 1], s[k]);
              } else {
                break;
              }
            }
            if (string_index.count(s)) {
              int j = string_index[s];
              if (i != j) {
                low_cost_pairs.insert(make_pair(min(i, j), max(i, j)));
              }
            }
          }
        }
      }
      long long high_cost_pairs =
          ((long long)R * (R - 1) >> 1) - low_cost_pairs.size();
      ans += 2 * high_cost_pairs + low_cost_pairs.size();
    }
  }
  long long nonanagram_pairs = ((long long)N * (N - 1) >> 1) - anagram_pairs;
  ans += nonanagram_pairs * kNonAnagramCost;
  printf("%lld\n", ans);
}