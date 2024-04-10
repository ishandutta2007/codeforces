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
vector<int> A;

int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}

int main() {
  scanf("%d", &N);
  map<int, int> cnt;
  REP(i,N) REP(j,N) {
    int a;
    scanf("%d", &a);
    A.push_back(a);
    auto it = cnt.find(a);
    if (it == cnt.end()) {
      cnt[a] = 1;
    } else {
      ++it->second;
    }
  }
  sort(A.begin(), A.end());
  reverse(A.begin(), A.end());
  vector<int> out;
  for (int n : A) {
    if (cnt[n]) {
      --cnt[n];
      for (int k : out) {
        int g = gcd(k, n);
        cnt[g] -= 2;
      }
      out.push_back(n);
    }
  }
  REP(i,(int)out.size()) {
    printf("%d%c", out[i], i == N-1 ? '\n' : ' ');
  }
  return 0;
}