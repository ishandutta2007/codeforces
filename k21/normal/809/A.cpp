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

const int MAXN = 300300;
const int MOD = 1000000007;

int N;
ll A[MAXN];

int main() {
  cin >> N;
  REP(i,N) {
    cin >> A[i];
  }
  sort(A, A+N);
  ll res = 0;
  ll acc = 0;
  ll mul = 1;
  FOR(i,1,N-1) {
    acc *= 2;
    acc += mul * (A[i] - A[i-1]);
    acc %= MOD;
    res += acc;
    if (res >= MOD) res -= MOD;
    mul *= 2;
    mul += 1;
    if (mul >= MOD) mul -= MOD;
  }
  
  cout << res << endl;

  return 0;
}