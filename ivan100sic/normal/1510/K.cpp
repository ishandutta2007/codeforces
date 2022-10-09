// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void sh(vector<int>& a) {
  int n = a.size();
  for (int i=0; i<n; i+=2) {
    swap(a[i], a[i+1]);
  }
}

void lng(vector<int>& a) {
  int n = a.size() / 2;
  for (int i=0; i<n; i++) {
    swap(a[i], a[i+n]);
  }
}

int rn(vector<int> a, int p) {
  for (int i=0; i<3333; i++) {
    if (is_sorted(begin(a), end(a))) {
      return i;
    }

    if (p) {
      sh(a);
    } else {
      lng(a);
    }

    p ^= 1;
  }

  return 3333;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;

  vector<int> a(2*n);
  for (int& x : a) {
    cin >> x;
  }

  int t1 = rn(a, 1);
  int t2 = rn(a, 0);

  int t = min(t1, t2);
  if (t > 3000) {
    t = -1;
  }
  cout << t << '\n';
}