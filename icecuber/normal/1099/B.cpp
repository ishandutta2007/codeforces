#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int a = sqrt(n);
  int b = (n+a-1)/a;
  cout << a+b << endl;
}