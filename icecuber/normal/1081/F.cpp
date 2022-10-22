#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
typedef long long ll;

int query(int l, int r) {
  //cerr << "? " << l+1 << ' ' << r+1 << endl;
  cout << "? " << l+1 << ' ' << r+1 << endl;
  int t;
  cin >> t;
  if (t == -1) exit(0);
  return t;
}

int a[500], total[500];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, t0;
  cin >> n >> t0;
  if (n%2==0) {
    for (int i = 0; i < n; i++) {
      while (1) {
	int t = query(i,i);
	int last = t0;
	t0 = t;
	if ((i+1)%2==abs(t-last)%2) {
	  // Flipped [0,i]
	  for (int j = 0; j <= i; j++) total[j] ^= 1;
	  int sum_before = 0, sum_after = 0;
	  for (int j = 0; j < i; j++) {
	    sum_before += a[j];
	    a[j] ^= 1;
	    sum_after += a[j];
	  }
	  a[i] = (last-sum_before < t-sum_after);
	  break;
	} else {
	  // Flipped [i,n-1]
	  for (int j = i; j < n; j++) total[j] ^= 1;
	}
      }
    }
  } else {
    for (int i = 0; i < n-1; i++) {//i=n-1?
      while (1) {
	if (i%2 == 0) {
	  int t = query(i+1,n-1);
	  int last = t0;
	  t0 = t;
	  if ((t-last)%2==0) {
	    // Flipped [i+1,n-1]
	    for (int j = i+1; j < n; j++) total[j] ^= 1;
	    int sum = 0;
	    for (int j = 0; j < i; j++) sum += a[j];
	    a[i] = (t-sum > n-i-(last-sum));
	    break;
	  } else {
	    // Flipped [0,n-1]
	    for (int j = 0; j < n; j++) total[j] ^= 1, a[j] ^= 1;
	  }
	} else {
	  int t = query(0,i);
	  int last = t0;
	  t0 = t;
	  if ((t-last)%2==0) {
	    // Flipped [0,i]
	    int sum_before = 0, sum_after = 0;
	    for (int j = 0; j < i; j++) sum_before += a[j];
	    for (int j = 0; j <= i; j++) total[j] ^= 1, a[j] ^= 1;
	    for (int j = 0; j < i; j++) sum_after += a[j];
	    a[i] = (t-sum_after) > (last-sum_before);
	    break;
	  } else {
	    // Flipped [0,n-1]
	    for (int j = 0; j < n; j++) total[j] ^= 1, a[j] ^= 1;
	  }
	}
      }
    }
  }
  for (int i = 0; i < n-1; i++) t0 -= a[i];
  a[n-1] = t0;
  cout << "! ";
  for (int i = 0; i < n; i++)
    cout << (total[i]^a[i]);
  cout << endl;
}