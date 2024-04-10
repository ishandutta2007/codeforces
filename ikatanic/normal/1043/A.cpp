#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

int main(void) {
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  int sum = 0, lo = 0;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    sum += x;
    lo = max(lo, x);
  }

  while (N*lo - sum <= sum) lo++;

  cout << lo << "\n";

  return 0;
}