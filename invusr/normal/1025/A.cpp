#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using s64 = long long;
using u64 = unsigned long long;

using r32 = double;
using r64 = long double;

template <class T>
inline bool relax(T &a, const T &b) {
  return b > a ? a = b, true : false;
}
template <class T>
inline bool tense(T &a, const T &b) {
  return b < a ? a = b, true : false;
}

const int MaxN = 100000;

int n;
char s[MaxN + 2];

int cnt[26];

int main() {
  cin >> n >> s + 1;
  for (int i = 1; i <= n; ++i) {
    ++cnt[s[i] - 'a'];
  }

  if (n == 1) {
    cout << "Yes\n";
    return 0;
  }

  bool flag = false;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] > 1) {
      flag = true;
      break;
    }
  }

  if (!flag) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }

  return 0;
}