#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int B = 400;

struct Bucket {
  int data[B];
  int mi, ma, mx, my, all;
  int off;
  Bucket() {
    fill_n(data, B, 0);
    mi = ma = mx = my = all = off = 0;
  }
  void recalc() {
    mi = 1e8, ma = -1e8, mx = -1e8, my = -1e8, all = -1e8;
    for (int i = 0; i < B; i++) {
      mi = min(mi, get(i));
      ma = max(ma, get(i));
      mx = max(mx, ma-get(i)*2);
      my = max(my, -mi*2+get(i));
      all = max(all, mx+get(i));
    }
  }
  void add(int v) {
    off += v;
    mi += v;
    ma += v;
    mx -= v;
    my -= v;
  }
  int get(int i) {
    return data[i]+off;
  }
};

Bucket bucket[200000/B+1];
int buckets = 200000/B+1;

void add(int l, int r, int v) {
  for (int i = 0; i < buckets; i++) {
    int a = i*B, b = i*B+B;
    if (b <= l || a >= r);
    else if (a >= l && b <= r) {
      bucket[i].add(v);
    } else {
      for (int j = 0; j < B; j++) {
	if (i*B+j >= l && i*B+j < r)
	  bucket[i].data[j] += v;
      }
      bucket[i].recalc();
    }
  }
}
int query() {
  int ans = 0;
  int ma = -1e8, mx = -1e8;
  for (int i = 0; i < buckets; i++) {
    ans = max(ans, mx+bucket[i].ma);
    ans = max(ans, ma+bucket[i].my);
    ans = max(ans, bucket[i].all);
    mx = max(mx, bucket[i].mx);
    mx = max(mx, ma-2*bucket[i].mi);
    ma = max(ma, bucket[i].ma);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int acc = 0;
  for (int i = 0; i < 2*n-2; i++) {
    acc += (s[i]=='(')-(s[i]==')');
    add(i,i+1,acc);
  }
  cout << query() << endl;
  while (q--) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    if (a > b) swap(a,b);
    if (s[a] == ')')
      add(a,b,2);
    else
      add(a,b,-2);
    swap(s[a],s[b]);
    /*for (int i = 0; i < 2*n-2; i++)
      cout << bucket[i/B].get(i%B) << ' ';
      cout << endl;*/
    cout << query() << endl;
  }
}