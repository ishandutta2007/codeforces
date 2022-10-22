#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

pair<ll,int> a[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x;
    a[i].y = i+1;
  }
  sort(a, a+n);
  int delfirst = 1;
  for (int i = 3; i < n; i++)
    if (a[i].x-a[i-1].x != a[2].x-a[1].x) delfirst = 0;
  if (delfirst) {
    cout << a[0].y << endl;
    return 0;
  }
  for (ll d : {a[1].x-a[0].x, a[2].x-a[0].x}) {
    int found = 0, skipped = 0;
    for (int i = 0; i+!!skipped < n; i++) {
      if (a[i+!!skipped].x != a[0].x+d*i) {
	if (skipped) goto next;
	skipped = a[i--].y;
      }
    }
    cout << skipped << endl;
    return 0;
  next:;
  }
  cout << -1 << endl;
}