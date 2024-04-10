#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int n = 1<<18;
int data[n*2];

void prop(int i) {
  i += n;
  for (int l = 18; l >= 1; l--) {
    int j = i>>l;
    data[j*2] = max(data[j*2], data[j]);
    data[j*2+1] = max(data[j*2+1], data[j]);
    data[j] = 0;
  }
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> data[i+n];
  }
  int q;
  cin >> q;
  while (q--) {
    int cmd;
    cin >> cmd;
    if (cmd == 1) {
      int p, x;
      cin >> p >> x;
      p--;
      prop(p);
      data[p+n] = x;
    } else {
      int x;
      cin >> x;
      data[1] = max(data[1], x);
    }
  }
  for (int i = 0; i < m; i++) {
    prop(i);
    cout << data[n+i] << ' ';
  }
  cout << endl;
}