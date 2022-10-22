#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    //string a0 = a;

    int l = 0, r = n-1, flip = 0;
    vector<int> ans;
    for (int i = n-1; i >= 0; i--) {
      if ((a[r]^flip) != b[i]) {
	if ((a[l]^flip) == b[i]) {
	  ans.push_back(1);
	  a[l] ^= 1;
	}
	ans.push_back(i+1);
	swap(l, r);
	flip ^= 1;
      }
      if (l < r) r--;
      else r++;
    }
    cout << ans.size() << endl;
    for (int v : ans) {
      /*reverse(a0.begin(), a0.begin()+v);
      for (int i = 0; i < v; i++)
      a0[i] ^= 1;*/
      cout << v << ' ';
    }
    cout << endl;
    /*cout << a0 << ' ' << b << endl;
      assert(a0 == b);*/
  }
}