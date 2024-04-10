#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int w, h;
  cin >> w >> h;
  int a = min(w,h);
  cout << a+1 << endl;
  for (int i = 0; i <= a; i++)
    cout << i << ' ' << a-i << endl;
}