#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mem[1<<16][16*16];

char c[16];
int r[16], b[16];
int n;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  int totr = 0, totb = 0;
  for (int i = 0; i < n; i++) {
    cin >> c[i] >> r[i] >> b[i];
    totr += r[i];
    totb += b[i];
  }
  int ans = max(totr, totb);

  for (int got = (1<<n)-1; got >= 0; got--) {
    for (int saveb = 0; saveb < n*n; saveb++) {
      int A = 0, B = 0;
      for (int i = 0; i < n; i++) {
	if (got>>i&1) {
	  (c[i] == 'R' ? A : B)++;
	}
      }
      int ans = -1e9;
      if (A+B == n && saveb == 0) {
	ans = 0;
      }
      for (int i = 0; i < n; i++) {
	if ((got>>i&1) == 0) {
	  int newsaver = r[i]-max(r[i]-A,0);
	  int newsaveb = b[i]-max(b[i]-B,0);
	  if (saveb >= newsaveb)
	    ans = max(ans, mem[got | (1<<i)][saveb-newsaveb]+newsaver);
	}
      }
      mem[got][saveb] = ans;
    }
  }

  for (int saveb = 0; saveb < n*n; saveb++) {
    int saver = mem[0][saveb];
    if (saver < 0) continue;
    ans = min(ans, max(totb-saveb, totr-saver));
  }
  cout << ans+n << endl;
}