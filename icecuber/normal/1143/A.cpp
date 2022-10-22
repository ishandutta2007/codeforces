#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int last[2] = {};
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int side;
    cin >> side;
    last[side] = i;
  }
  cout << min(last[0], last[1])+1 << endl;
}