#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  cout << (n*2+k-1)/k+(n*5+k-1)/k+(n*8+k-1)/k << endl;
}