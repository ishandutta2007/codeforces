#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(int i) {
  cout << "? " << i+1 << endl;
  int ans;
  cin >> ans;
  return ans;
}

void answer(int i) {
  cout << "! " << i+1 << endl;
  exit(0);
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  n /= 2;
  if (n%2) {
    cout << "! -1" << endl;
    return 0;
  }

  int a = query(0), b = query(n);
  if (a == b) answer(0);
  int l = 1, r = n-1;
  //f(0) = a-b, f(n) = b-a;
  while (l <= r) {
    int m = l+r>>1;
    int f = query(m)-query(n+m);
    if (a > b) f *= -1;
    if (f == 0) answer(m);
    else if (f < 0) l = m+1;
    else r = m-1;
  }
}