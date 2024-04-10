#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k, n, w;
  cin >> k >> n >> w;
  cout << max(k*w*(w+1)/2-n, 0) << endl;
}