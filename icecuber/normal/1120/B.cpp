#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll diff[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  ll work = 0;
  for (int i = 0; i < n; i++) {
    diff[i] = b[i]-a[i]-(i ? diff[i-1] : 0);
    work += abs(diff[i]);
  }
  if (diff[n-1]) {
    cout << -1 << endl;
    return 0;
  }
  set<int> todo;
  for (int i = 0; i < n-1; i++) {
    if (diff[i] > 0 && a[i] != '9' && a[i+1] != '9' ||
	diff[i] < 0 && a[i] != '0' && (i || a[i] != '1') && a[i+1] != '0')
      todo.insert(i);
  }

  cout << work << endl;
  for (int it = 0; it < min(work, 100000ll); it++) {
    //for (int i = 0; i < n-1; i++) cout << diff[i] << ' '; cout << endl;
    //cout << a << ' ' << b << endl;
    assert(todo.size());
    int j = *todo.begin();
    int s = diff[j]/abs(diff[j]);
    cout << j+1 << ' ' << s << endl;
    a[j] += s;
    a[j+1] += s;
    diff[j] -= s;
    assert(a[j] >= '0' && a[j] <= '9');
    assert(j || a[j] >= '1');
    for (int i : {j-1,j,j+1}) {
      if (todo.count(i)) todo.erase(i);
      if (i > -1 && i < n-1 &&
	  (diff[i] > 0 && a[i] != '9' && a[i+1] != '9' ||
	   diff[i] < 0 && a[i] != '0' && (i || a[i] != '1') && a[i+1] != '0'))
	todo.insert(i);
    }
  }
}