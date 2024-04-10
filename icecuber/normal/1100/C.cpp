#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  double n, r;
  cin >> n >> r;
  double t = sin(M_PI/n);
  cout << setprecision(20) << r*t/(1-t) << endl;
}