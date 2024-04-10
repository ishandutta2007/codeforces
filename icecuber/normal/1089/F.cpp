#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void euclid(int p, int q, int&ip, int&iq) {
  if (q) {
    int k = p/q;
    euclid(q,p%q,iq,ip);
    iq -= ip*k;
  } else
    ip = 1,iq = 0;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int p = 1, q = 1;
  for (int i = 2; 1ll*i*i <= n; i++) {
    if (n%i == 0) {
      while (n/p%i == 0) p *= i;
      q = n/p;
      break;
    }
  }
  if (p == 1 || q == 1) {
    cout << "NO" << endl;
    return 0;
  }
  int ip, iq;
  euclid(p,q,ip,iq);
  cout << "YES" << endl;
  cout << 2 << endl;
  cout << (-ip%q+q)%q << ' ' << n/p << endl;
  cout << (-iq%p+p)%p << ' ' << n/q << endl;
}