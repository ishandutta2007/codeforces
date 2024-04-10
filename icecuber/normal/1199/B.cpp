#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  double h, l;
  cin >> h >> l;
  cout << setprecision(20) << (l*l-h*h)/(2*h) << endl;
}