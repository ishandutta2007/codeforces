#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int c[4] = {};
  int n;
  cin >> n;
  vector<int> a(n);
  string s1,s2;
  cin >> s1 >> s2;
  for (int i = 0; i < n; i++) {
    a[i] = (s1[i]-'0')+(s2[i]-'0')*2;
    c[a[i]]++;
  }
  //x0,x1,x2,x3;
  //x1+x2+2*x3 = n2+n3
  for (int x2 = 0; x2 <= c[2]; x2++)
    for (int x3 = 0; x3 <= c[3]; x3++) {
      int x1 = c[2]+c[3]-x3*2-x2;
      if (x1 < 0 || x1 > c[1]) continue;
      int x0 = n/2-x1-x2-x3;
      if (x0 < 0 || x0 > c[0]) continue;

      int x[] = {x0,x1,x2,x3};
      for (int i = 0; i < n; i++) {
	if (x[a[i]]) {
	  x[a[i]]--;
	  cout << i+1 << ' ';
	}
      }
      cout << endl;
      return 0;
    }
  cout << -1 << endl;
}