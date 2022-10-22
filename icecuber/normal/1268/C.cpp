#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

template<class T>
using os_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int nax = 1<<18;
struct SegTree {
  //#warning SLOW

  ll sum[nax*2], off[nax*2], count[nax*2];
  void init(int n) {
    for (int i = 0; i < n; i++) count[nax+i] = 1;
    for (int i = nax-1; i; i--) count[i] = count[i*2]+count[i*2+1];
  }
  void add(int r, ll v) {
    //for (int i = 0; i < r; i++) off[i+nax] += v;
    //return;

    if (!r) return;
    for (int i = r+nax; i > 1; i >>= 1) {
      if (i&1) {
	off[i-1] += v;
      }
      sum[i>>1] = sum[i]+off[i]*count[i] + sum[i^1]+off[i^1]*count[i^1];
    }
  }
  void add(int l, int r, ll v) {
    add(l,-v);
    add(r, v);
  }
  ll Sum(int r) {
    //ll ret = 0;
    //for (int i = 0; i < r; i++) ret += off[i+nax]*count[i+nax];
    //return ret;

    if (!r) return 0;
    ll ans = 0;
    ll acc = 0;
    for (int i = r+nax; i > 1; i >>= 1) {
      if (i&1) {
	ans += sum[i-1] + count[i-1] * off[i-1];
	acc += count[i-1];
      }
      ans += off[i>>1]*acc;
    }
    return ans;
  }
  ll Sum(int l, int r) {
    return Sum(r)-Sum(l);
  }
  void erase(int r) {
    count[r+nax] = 0;

    //return;

    for (int i = r+nax; i > 1; i >>= 1) {
      count[i>>1] = count[i]+count[i^1];
      sum[i>>1] = sum[i]+off[i]*count[i] + sum[i^1]+off[i^1]*count[i^1];
    }
  }
};

SegTree L, R;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> p(n), ip(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
    ip[p[i]] = i;
  }

  L.init(n), R.init(n);

  ll base = 0;
  os_set<int> inds;
  for (int i = 0; i < n; i++) {
    int pos = ip[i];
    inds.insert(pos);
    int mid = *inds.find_by_order(i/2);
    base += R.Sum(pos,pos+1);

    L.erase(pos);
    R.erase(pos);
    L.add(pos+1, n, 1);
    R.add(0, pos, 1);
    ll ans = base + L.Sum(0, mid)+R.Sum(mid, n);
    /*cout << endl;
    for (int i = 0; i < n; i++) cout << L.Sum(i,i+1) << ' ';
    cout << endl;
    for (int i = 0; i < n; i++) cout << R.Sum(i,i+1) << ' ';
    cout << endl;
    cout << ans << endl;*/
    cout << ans << ' ';
  }
  cout << endl;
}