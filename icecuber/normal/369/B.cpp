#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k, l, r, sa, sk;
  cin >> n >> k >> l >> r >> sa >> sk;
  sa -= sk+l*(n-k);
  sk -= l*k;
  for (int i = 0; i < k; i++)
    cout << sk*(i+1)/k-sk*i/k+l << ' ';
  n -= k;
  for (int i = 0; i < n; i++)
    cout << sa*(i+1)/n-sa*i/n+l << ' ';
  cout << endl;
}