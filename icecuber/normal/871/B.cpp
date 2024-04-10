#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  /*int n = 3;
  int pans[3] = {2,1,0};
  int ipans[3];
  for (int i = 0; i < n; i++)
  ipans[pans[i]] = i;*/
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cout << "? " << i << ' ' << 0 << endl;
    //a[i] = pans[i] ^ ipans[0];
    cin >> a[i];
    cout << "? " << 0 << ' ' << i << endl;
    //b[i] = ipans[i] ^ pans[0];
    cin >> b[i];
  }
  auto f = [&](int i, int j) {
    return a[i]^b[j]^a[0];
  };
  int oks = 0;
  vector<int> ans(n);
  for (int ip0 = 0; ip0 < n; ip0++) {
    int ok = 1;
    vector<int> p(n), ip(n,-1);
    for (int i = 0; i < n; i++) {
      p[i] = a[i]^ip0;
      if (p[i] >= n || ip[p[i]] != -1) {
	ok = 0;
	break;
      }
      ip[p[i]] = i;
    }
    if (ok == 0 || ip[0] != ip0) continue;
    for (int i = 0; i < n; i++) {
      if (ip[i] != (b[i]^p[0])) ok = 0;
    }
    if (ok == 0) continue;
    oks++;
    ans = p;
  }
  cout << "!" << endl;
  cout << oks << endl;
  for (int i : ans) cout << i << ' ';
  cout << endl;
}