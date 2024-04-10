#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int k, a, b, v;
  cin >> k >> a >> b >> v;
  cout << max((a-1)/(k*v)+1, (a-1)/v+1-b) << endl;
}