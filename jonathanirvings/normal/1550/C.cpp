#include <bits/stdc++.h>
using namespace std;

vector<int> get_left_le(const vector<int> &A) {
  vector<int> left_le(A.size());
  stack<pair<int, int>> nondecreasing;
  for (int i = 0; i < A.size(); ++i) {
    while (!nondecreasing.empty() && nondecreasing.top().first > A[i]) {
      nondecreasing.pop();
    }
    left_le[i] = nondecreasing.empty() ? -1 : nondecreasing.top().second;
    nondecreasing.push(make_pair(A[i], i));
  }
  return left_le;
}

vector<int> get_left_ge(const vector<int> &A) {
  vector<int> left_ge(A.size());
  stack<pair<int, int>> nonincreasing;
  for (int i = 0; i < A.size(); ++i) {
    while (!nonincreasing.empty() && nonincreasing.top().first < A[i]) {
      nonincreasing.pop();
    }
    left_ge[i] = nonincreasing.empty() ? -1 : nonincreasing.top().second;
    nonincreasing.push(make_pair(A[i], i));
  }
  return left_ge;
}

vector<int> get_inv(const vector<int> &A) {
  int N = A.size();
  vector<int> inv(N);
  for (int i = 0; i < N; ++i) {
    inv[i] = N - 1 - A[N - 1 - i];
  }
  return inv;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int N;
    scanf("%d", &N);
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &A[i]);
    }
    vector<int> left_le = get_left_le(A);
    vector<int> left_ge = get_left_ge(A);

    reverse(A.begin(), A.end());
    vector<int> right_le = get_inv(get_left_le(A));
    vector<int> right_ge = get_inv(get_left_ge(A));

    vector<int> good_until(N, N);
    for (int i = 0; i < N; ++i) {
      if (left_le[i] >= 0) {
        good_until[left_le[i]] = min(good_until[left_le[i]], right_ge[i]);
      }
      if (left_ge[i] >= 0) {
        good_until[left_ge[i]] = min(good_until[left_ge[i]], right_le[i]);
      }
    }

    long long answer = 0;
    int until = N;
    for (int i = N - 1; i >= 0; --i) {
      until = min(until, good_until[i]);
      answer += until - i;
    }
    printf("%lld\n", answer);
  }
}