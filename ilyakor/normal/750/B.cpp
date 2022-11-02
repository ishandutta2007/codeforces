#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cassert>
#include <functional>
#include <sstream>
#include <cmath>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define sz(v) ((int)(v).size())

template<class T> T abs(T x) { return x >= 0 ? x : -x; }
template<class T> T sqr(T x) { return x * x; }

int main() {
  int n;
  cin >> n;
  int x = 0;
  int l = 20000;
  for (int i = 0; i < n; ++i) {
    int t;
    string dir;
    cin >> t >> dir;
    if (dir == "North") {
      if (x - t < 0) {
        printf("NO\n");
        return 0;
      }
      x -= t;
    } else if (dir == "South") {
      if (x + t > l) {
        printf("NO\n");
        return 0;
      }
      x += t;
    } else if (x == 0 || x == l) {
      printf("NO\n");
      return 0;
    }
  }
  if (x != 0) {
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  return 0;
}