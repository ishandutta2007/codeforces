#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b;
  cin >> a >> b;
  int rb = 0;
  while (b) {
    rb = rb*10+b%10;
    b /= 10;
  }
  cout << a+rb << endl;
}