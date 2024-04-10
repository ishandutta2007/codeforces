#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

int N;
ll L, R;

int popcnt(ll n) {
  int cnt = 0;
  REP(i,63) {
    if (n & (1LL<<i)) ++cnt;
  }
  return cnt;
}

ll smallest(ll n, int bits) {
  int p = popcnt(n);
  int i = 0;
  while (p < bits) {
    if (!(n & (1LL<<i))) {
      ++p;
      n |= (1LL<<i);
    }
    ++i;
  }
  return n;
}

int main() {
  cin >> N;

  REP(i,N) {
    cin >> L >> R;
    FORD(bits,63,0) {
      ll c = smallest(L, bits);
      if (c <= R) {
        cout << c << '\n';
        break;
      }
    }
  }

  return 0;
}