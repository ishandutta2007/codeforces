#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

constexpr int B = 5;

int mod[B];

int64 x[2180], y[2180];
float nx[B][2180], ny[B][2180];
float a[B][2180];
int64 Nx[2180], Ny[2180];
int64 A[2180];

int main() {
  srand(time(0));
  for (int i = 0; i < B; ++i) {
    do {
      mod[i] = rand() % 10000;
    } while (mod[i] < 1000);
  }
  int n;
  int64 S;
  cin >> n >> S;
  S *= 2L;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
//  S = (((int64) rand()) << 32L) + (int64) rand();
//  n = 2000;
//  for (int i = 0; i < n; ++i) {
//    int64 mod = (int64)(2e9);
//    assert(mod > 0);
//    x[i] = rand() % mod - mod / 2;
//    y[i] = rand() % mod - mod / 2;
//  }
  //float _s = S;
  for (int s = 0; s < n; ++s) {
    for (int i = s + 1; i < n; ++i) {
      Nx[i] = x[i] - x[s];
      Ny[i] = y[i] - y[s];
      for (int j = 0; j < B; ++j) {
        nx[j][i] = Nx[i] % mod[j];
        ny[j][i] = Ny[i] % mod[j];
      }
    }
    for (int i = s + 1; i < n; ++i) {
      int Xi = Nx[i], Yi = Ny[i];
      int ind = 0;
      for (int j = i + 1; j < n; ++j) {
        int64 t = Nx[j] * Yi - Ny[j] * Xi;
        if (t == S || t == -S) {
          ind += j;
        }
//        if (A[j] == S || A[j] == -S) {
//           cout << "Yes\n";
//           cout << x[s] << " " << y[s] << "\n";
//           cout << x[i] << " " << y[i] << "\n";
//           cout << x[j] << " " << y[j] << "\n";
//           return 0;
//        }
      }
      if (ind > 0) {
       for (int j = i + 1; j < n; ++j) {
         int64 t = Nx[j] * Yi - Ny[j] * Xi;
         if (t == S || t == -S) {
           cout << "Yes\n";
           cout << x[s] << " " << y[s] << "\n";
           cout << x[i] << " " << y[i] << "\n";
           cout << x[j] << " " << y[j] << "\n";
           return 0; 
         }
        }
      }
    }
//      for (int j = i + 1; j < n; ++j) {
//        if (A[j] == S || A[j] == -S) {
//           cout << "Yes\n";
//           cout << x[s] << " " << y[s] << "\n";
//           cout << x[i] << " " << y[i] << "\n";
//           cout << x[j] << " " << y[j] << "\n";
//           return 0;
//        } 
//      }
//    }
//   for (int i = 0; i < n; ++i) {
//     for (int k = 0; k < B; ++k) {
//        float xi = nx[k][i], yi = ny[k][i];
//        //int64 xi = nx[i], yi = ny[i];
//        int j = 0;
//        float* cx = nx[k];
//        float* cy = ny[k];
//        float* ca = a[k];
//
//        for (; j + 8 <= n; j += 8) {
//          ca[j] = cx[j] * yi - cy[j] * xi;
//          ca[j + 1] = cx[j + 1] * yi - cy[j + 1] * xi;
//          ca[j + 2] = cx[j + 2] * yi - cy[j + 2] * xi;
//          ca[j + 3] = cx[j + 3] * yi - cy[j + 3] * xi;
//          ca[j + 4] = cx[j + 4] * yi - cy[j + 4] * xi;
//          ca[j + 5] = cx[j + 5] * yi - cy[j + 5] * xi;
//          ca[j + 6] = cx[j + 6] * yi - cy[j + 6] * xi;
//          ca[j + 7] = cx[j + 7] * yi - cy[j + 7] * xi;
//        }
//        for (; j < n; ++j) {
//          ca[j] = cx[j] * yi - cy[j] * xi;
//        }
//      }
//    }
//      for (j = 0; j < n; ++j) {
//        float val = (a[j] < 0 ? -a[j] : a[j]);
//        val /= _s;
//        if (val >= 0.99999 && val <= 1.00001) {
//          cout << "Yes\n";
//          cout << x[s] << " " << y[s] << "\n";
//          cout << x[i] << " " << y[i] << "\n";
//          cout << x[j] << " " << y[j] << "\n";
//          return 0;
//        }
//      }
  }
  cout << "No\n";
  return 0;
}