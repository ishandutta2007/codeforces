#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>

#define TRACE(x) std::cerr << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;
using i64 = int64_t;

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> A[i][j];
        --A[i][j];
      }
    }

    vector<int> order = {0, 1, 2};
    vector<int> shift = {0, 0, 0};

    string C;
    cin >> C;
    for (char c : C) {
      switch (c) {
        case 'R': {
          shift[1] = (shift[1] + 1) % n;
          break;
        }
        case 'L': {
          shift[1] = (shift[1] - 1 + n) % n;
          break;
        }
        case 'D': {
          shift[0] = (shift[0] + 1) % n;
          break;
        }
        case 'U': {
          shift[0] = (shift[0] - 1 + n) % n;
          break;
        }
        case 'I': {
          swap(order[1], order[2]);
          swap(shift[1], shift[2]);
          break;
        }
        case 'C': {
          swap(order[0], order[2]);
          swap(shift[0], shift[2]);
          break;
        }
        default:
          assert(false);
      }
    }

    vector<vector<int>> B(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        vector<int> a = {i, j, A[i][j]};
        int x = (a[order[0]] + shift[0]) % n;
        int y = (a[order[1]] + shift[1]) % n;
        int z = (a[order[2]] + shift[2]) % n;
        B[x][y] = z;
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cout << B[i][j] + 1 << ' ';
      }
      cout << '\n';
    }
  }

  return 0;
}