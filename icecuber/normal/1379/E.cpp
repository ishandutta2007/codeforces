#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 100;
int mem[nax][nax];
int ok(int n, int k) {
  if (n%2 == 0 || n <= 0 || k < 0) return 0;
  if (n == 1) return (k == 0);

  int&memo = mem[n][k];
  if (!memo) {
    int r = 0;
    //for (int na : {1, 2, 3, n/2-3, n/2-2, n/2-1, n/2}) {
      //if (na > n-1) continue;
    for (int na = 1; na < n-1; na = na*2+1) {
      //if (na > 20 && na < n/2-20) continue;
      int ka = 0;
      int nb = n-1-na;
      int got = (na >= nb*2 || nb >= na*2);
      int kb = k-ka-got;
      r |= (ok(na, ka) && ok(nb, kb));
    }
    memo = r+1;
  }
  return memo-1;
}

int fastOK(int n, int k) {
  int balance = !(n&(n+1));
  return (n > 0 && k >= 0 && n%2 && (2*k+3 <= n || k == 0) && (k > 1 || k != balance) && (n != 9 || k != 2));
}

int id;
void rec(int n, int k, int par = 0) {
  assert(fastOK(n, k));
  cout << par << ' ';
  int myid = ++id;
  if (n == 1) return;

  for (int na = 1; na < n-1; na = na*2+1) {
    int nb = n-1-na;
    int kb = k-(na >= nb*2 || nb >= na*2);
    if (fastOK(na, 0) && fastOK(nb, kb)) {
      rec(na, 0, myid);
      rec(nb, kb, myid);
      return;
    }
  }
  assert(0);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int n, k;
  cin >> n >> k;

  if (!fastOK(n, k)) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  rec(n, k);
  cout << endl;
  return 0;
  /*
  for (int n = 1; n < nax; n++) {
    //cout << n << ": ";
    for (int k = 0; k < nax; k++) {
      id = 0;
      if (fastOK(n, k))
	rec(n, k);
      continue;
      int balance = !(n&(n+1));
      if (ok(n,k) != (n%2 && (2*k+3 <= n || k == 0) && (k > 1 || k != balance) && (n != 9 || k != 2))) {
	cout << n << ' ' << k << endl;
	return 0;
      }
      //if (ok(n,k)) cout << k << ' ';
    }
    //cout << endl;
  }
  */
}