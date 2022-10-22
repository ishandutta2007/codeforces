#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, k;
int query(int p) {
  assert(p >= 0 && p < n);
  cout << "? " << p+1 << endl;
  int ans;
  cin >> ans;
  return ans;
}

int Answer(int p) {
  cout << "! " << p+1 << endl;
  exit(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n >> k;

  mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());

  int big = 0;
  while (1) {
    big = (big + mrand()%100 + 300)%n;
    if (query(big) != k) break;
  }


  int dir ;
  if (query(big) > k) dir = 1;
  else dir = -1;

  int step = 1;
  while ((query(big)-k)*dir > 0) {
    big = (big+n - step*dir)%n;
    step *= 2;
  }
  step /= 2;

  if (query(big) == k) Answer(big);

  if (dir == -1) {
    big = (big+n-step)%n;
  }

  int l = big;
  assert(query(l) < k);

  int high = step, low = 0;
  while (1) {
    assert(high-low > 1);
    int mid = (low+high)/2;
    int q = query((l+mid)%n);
    if (q == k) Answer((l+mid)%n);
    else if (q > k) high = mid;
    else low = mid;
  }
  assert(0);
}