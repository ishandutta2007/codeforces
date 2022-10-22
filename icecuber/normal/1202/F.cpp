#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int n = a+b;
  int ans = 0;
  auto f = [&](int g) {
    if ((a-1)/(g+1)+1 > a/g || (b-1)/(g+1)+1 > b/g) return 0;
    int mi = (a-1)/(g+1)+1 + (b-1)/(g+1)+1;
    int ma = a/g+b/g;

    mi = max(mi, n/(g+1)+1);
    ma = min(ma, n/g);

    /*if (ma-mi >= 0) {
      cout << g << ": ";
      for (int i = mi; i <= ma; i++)
	cout << i << ' ';
      cout << endl;
      }*/
    return max(ma-mi+1,0);
  };


  set<int> gs;
  for (int k = 1; k*k <= n; k++) {
    gs.insert(k);
    gs.insert(n/k);
  }
  for (int g : gs) {
    ans += f(g);
  }

  /*  for (int k = 1; k <= n; k++) {
    int g = n/k;
    //assert(gs.count(g));
    if ((a-1)/(g+1)+1 + (b-1)/(g+1)+1 <= k &&
	a/g+b/g >= k) {
      cout << (a-1)/(g+1)+1 << ' ' << a/g << endl;
      cout << (b-1)/(g+1)+1 << ' ' << b/g << endl;
      cout << k << ' ' << g << endl;
      cout << endl;
      ans++;
    }
    }*/
  cout << ans << endl;
}