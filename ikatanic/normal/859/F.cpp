#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;


template <class T>
class MonotonicQueue {
  deque<T> maxQ;
  queue<T> Q;
public:
  void push(T x) {
    while (!maxQ.empty() && x > maxQ.back()) maxQ.pop_back();
    maxQ.push_back(x);
    Q.push(x);
  }

  void pop() {
    if (Q.front() == maxQ.front()) maxQ.pop_front();
    Q.pop();
  }
  
  T getMax() {
    return maxQ.front();
  }
  
  bool empty() {
    return Q.empty();
  }
};


const int MAX = 200200;
const llint inf = 1e18;

llint a[MAX], b[MAX];
llint s[MAX];
llint x[MAX], sx[MAX];

int main(void) {
  int N;
  llint C;
  scanf("%d %lld", &N, &C);
  REP(i, N) {
    scanf("%lld", &a[i]);
    if (i < N-1) scanf("%lld", &b[i]);
  }
  
  REP(i, N) a[i] = min(a[i], C);
  REP(i, N-1) b[i] = min(b[i], C);

  if (N == 1) {
    printf("%lld\n", a[0]);
    return 0;
  }

  s[0] = 0;
  REP(i, N) s[i + 1] = s[i] + a[i] + b[i];
  
  auto f = [&] (llint x0) {
    llint total = x0;
    x[0] = x0;
    sx[1] = x0;
    
    int l = 0;
    MonotonicQueue<llint> Q;
    Q.push(sx[0] - s[0]);
    
    for (int i = 1; i < N; ++i) {
      llint cur = a[i];

      while (l < i && s[i] - s[l] + a[i] >= C) {
        l++;
        Q.pop();
      }

      if (!Q.empty()) {
        cur = max(cur, a[i] + s[i] - sx[i] + Q.getMax());
      }
      if (l-1 >= 0) {
        cur = max(cur, C - (sx[i] - sx[l-1]));
      }
      
      x[i] = cur;
      sx[i + 1] = sx[i] + x[i];
      Q.push(sx[i] - s[i]);
      
      total += cur;
    }
    return total;
  };


  llint x0 = min(C, a[0]);
  printf("%lld\n", f(x0));
  return 0;
}