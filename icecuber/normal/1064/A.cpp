#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a[3];
  for (int i = 0; i < 3; i++) cin >> a[i];
  sort(a,a+3);
  cout << max(a[2]+1-a[0]-a[1],0) << endl;
}