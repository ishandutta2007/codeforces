#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a;
    cin >> a;
    int pop = 0;
    while (a) a -= a&-a, pop++;
    cout << (1<<pop) << endl;
  }
}