#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

int c[500000];
struct Query {
  int s, e, i;
};
vector<Query> p;
int ans[500000];

struct Basis {
  vector<int> subset, mask;
  Basis() {}
  void insert(int v) {
    for (int i = 0; i < mask.size(); i++)
      if (v&mask[i]) v ^= subset[i];
    //cout << "insert: " << v << endl;
    if (v) {
      int m = v&-v;
      for (int&i : subset)
	if (i&m) i ^= v;
      subset.push_back(v);
      mask.push_back(m);
    }
  }
  Basis merge(Basis other) {
    for (int i : subset)
      other.insert(i);
    return other;
  }
  int maxComb() {
    int r = 0;
    vector<int> s = subset;
    for (int i = 19; i >= 0; i--) {
      int found = -1;
      for (int j = 0; j < s.size(); j++) {
	if (s[j]>>i&1) {
	  if (found == -1) {
	    found = s[j];
	    s[j] = 0;
	    if (!(r>>i&1))
	      r ^= found;
	  } else {
	    s[j] ^= found;
	  }
	}
      }
    }
    return r;
  }
  void dump() {
    for (int i : subset) cout << i << ' ';
    cout << endl;
  }
};

Basis base[500000];

void daq(vector<Query>&p, int a, int b) {
  if (p.empty()) return;
  int split = a+b>>1;
  vector<Query> left, right;
  (base[split] = Basis()).insert(c[split]);
  for (int i = split+1; i < b; i++)
    (base[i] = base[i-1]).insert(c[i]);
  for (int i = split-1; i >= a; i--)
    (base[i] = base[i+1]).insert(c[i]);

  for (Query q : p) {
    if (q.e <= split) left.push_back(q);
    else if (q.s > split) right.push_back(q);
    else {
      //cout << q.i << endl;
      //(base[q.s].merge(base[q.e-1])).dump();
      ans[q.i] = (base[q.s].merge(base[q.e-1])).maxComb();
    }
  }
  daq(left, a, split);
  daq(right, split+1, b);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> c[i];

  /*Basis b;
  for (int i = 0; i < 4; i++) {
    b.insert(c[i]);
    b.dump();
  }
  return 0;*/
  int q;
  cin >> q;
  p.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> p[i].s >> p[i].e;
    p[i].s--;
    p[i].i = i;
  }
  daq(p,0,n);
  for (int i = 0; i < q; i++)
    cout << ans[i] << '\n';
}