#include <bits/stdc++.h>

using namespace std;

static void print(const vector<int> &a) {
  for (int i = 0; i < a.size(); ++i)
    cout << a[i] << " ";

  cout << endl;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string p;
  string s;
  cin >> p >> s;

  const int k = p.size();
  const int n = s.size();

  vector<int> a(n + 1, 0);
  vector<int> b(n + 1, 0);

  for (int i = n - 1; i >= 0; --i) {
    a[i] = a[i + 1];
    b[i] = b[i + 1];
    if (s[i] == '1') {
      a[i] += 1;
    } else {
      b[i] += 1;
    }
  }

  //  print(a);
  // print(b);

  uint64_t count = 0;
  uint64_t prevA = 0;
  uint64_t prevB = 0;

  for (int i = k - 1, last = n - 1; i >= 0; --i, --last) {
    if (p[i] == '1') {
      count += b[i] - prevB;
    } else {
      count += a[i] - prevA;
    }
    if (s[last] == '1')
      ++prevA;
    else
      ++prevB;
  }

  cout << count << endl;
  return 0;
}