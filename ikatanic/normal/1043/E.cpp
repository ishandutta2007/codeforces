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

  int N, M;
  cin >> N >> M;

  vector<llint> X(N), Y(N);
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> X[i] >> Y[i];
    a[i] = i;
  }

  sort(a.begin(), a.end(), [&] (const int &i, const int &j) {
    return X[i] - Y[i] < X[j] - Y[j];
  });

  vector<llint> ret(N);
  llint curr = 0;
  for (int i = 0; i < N; ++i) {
    curr += Y[a[i]];
  }

  for (int i = 0; i < N; ++i) {
    curr -= Y[a[i]];
    ret[a[i]] = curr + i * Y[a[i]] + (N-i-1) * X[a[i]];
    curr += X[a[i]];
  }

  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;

    llint c = min(X[a] + Y[b], X[b] + Y[a]);
    ret[a] -= c;
    ret[b] -= c;
  }

  for (int i = 0; i < N; ++i) {
    cout << ret[i] << " ";
  }
  cout << "\n";
  return 0;
}