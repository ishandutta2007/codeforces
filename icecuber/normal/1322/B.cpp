#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  vector<int> a(n);
  for (int&v : a) {
    cin >> v;
  }
  for (int j = 0; j < 25; j++) {
    int r = 0;

    int m = (2<<j)-1;
    vector<int> cnt(m+10);
    vector<int> acc(m+10);
    for (int i = 0; i < n; i++) {
      cnt[a[i]&m]++;
    }
    for (int i = 0; i < (1<<j+1); i++)
      acc[i+1] = acc[i]+cnt[i];
    for (int i = 0; i < (1<<j+1); i++) {
      r ^= ((i+i)>>j&1)*((ll)cnt[i]*(cnt[i]-1)/2&1);

      {
	//(1<<j)-i <= k < (2<<j)-i
	int mi = max((1<<j)-i, 0), ma = min({(2<<j)-i, m+1, i});
	if (ma > mi) {
	  r ^= (acc[ma]-acc[mi]&1)*(cnt[i]&1);
	}
      }

      {
	//(3<<j)-i <= k < (4<<j)-i
	int mi = max((3<<j)-i, 0), ma = min({(4<<j)-i, m+1, i});
	if (ma > mi) {
	  r ^= (acc[ma]-acc[mi]&1)*(cnt[i]&1);
	}
      }
    }

    /*for (int i = 0; i < n; i++) {
      for (int k = 0; k < i; k++) {
	r ^= ((a[i]&m) + (a[k]&m)) >> j&1;
      }
      }*/

    ans |= (r&1)<<j;
  }
  cout << ans << endl;
}