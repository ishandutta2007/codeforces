#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ask(int a, int b) {
  cout << "? " << a << ' ' << b << endl;
  int ans;
  cin >> ans;
  return ans+1;
}

const int bits = 30;
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int greater = -1, a = 0, b = 0, done = 0;
  for (int i = bits-1; i >= 0; i--) {
    if (greater == -1) {
      greater = ask(a,b)>0;
      i++;
      continue;
    } else if (greater == 1) {
      if (ask(a|1<<i,b|1<<i)) {
	;
      } else {
	a |= 1<<i;
	done |= 1<<i;
	greater = -1;
      }
    } else {
      if (!ask(a|1<<i,b|1<<i)) {
	;
      } else {
	b |= 1<<i;
	done |= 1<<i;
	greater = -1;
      }
    }
  }
  //cout << a << ' ' << b << ' ' << done << endl;
  for (int i = 0; i < bits; i++) {
    if (done>>i&1) continue;
    if (!ask(a|1<<i,b))
      a |= 1<<i, b |= 1<<i;
  }
  cout << "! " << a << ' ' << b << endl;
}