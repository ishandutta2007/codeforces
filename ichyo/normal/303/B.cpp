#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int gcd(int x, int y){
  if(x % y == 0) return y;
  return gcd(y, x % y);
}

int main(){
  int n, m, x, y, a, b;
  while(cin >> n >> m >> x >> y >> a >> b){
    int G = gcd(a, b);
    a /= G; b /= G;
    int k = min(n / a, m / b);
    a *= k; b *= k;
    int x2 = x + a / 2;
    int y2 = y + b / 2;
    int x1 = x2 - a;
    int y1 = y2 - b;
    if(x2 > n){
      x1 -= x2 - n;
      x2 = n;
    }
    if(y2 > m){
      y1 -= y2 - m;
      y2 = m;
    }
    if(x1 < 0){
      x2 += 0 - x1;
      x1 = 0;
    }
    if(y1 < 0){
      y2 += 0 - y1;
      y1 = 0;
    }
    printf("%d %d %d %d\n", x1, y1, x2, y2);
  }
  return 0;
}