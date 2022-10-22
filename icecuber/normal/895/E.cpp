#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int n = 1<<17;
double sum[n*2], lazy_mul[n*2], lazy_add[n*2];

void push(int i, int l, int r) {
  if (lazy_mul[i] != 1 || lazy_add[i] != 0) {
    sum[i] = sum[i]*lazy_mul[i]+lazy_add[i]*(r-l);
    if (i < n) {
      for (int j : {i*2,i*2+1}) {
	lazy_mul[j] *= lazy_mul[i];
	lazy_add[j] *= lazy_mul[i];
	lazy_add[j] += lazy_add[i];
      }
    }
    lazy_mul[i] = 1;
    lazy_add[i] = 0;
  }
}

void fma(double mul, double add, int a, int b, int l = 0, int r = n, int i = 1) {
  push(i,l,r);
  if (a >= r || b <= l) return;
  if (a <= l && b >= r) {
    lazy_mul[i] = mul;
    lazy_add[i] = add;
    push(i,l,r);
    return;
  }
  int m = l+r>>1;
  fma(mul,add,a,b,l,m,i*2);
  fma(mul,add,a,b,m,r,i*2+1);
  sum[i] = sum[i*2]+sum[i*2+1];
}

double querySum(int a, int b, int l = 0, int r = n, int i = 1) {
  push(i,l,r);
  if (a >= r || b <= l) return 0;
  if (a <= l && b >= r) {
    return sum[i];
  }
  int m = l+r>>1;
  return
    querySum(a,b,l,m,i*2)+
    querySum(a,b,m,r,i*2+1);
}

int main() {
  fill_n(lazy_mul, n*2, 1.);

  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    fma(1,a,i,i+1);
  }
  /*for (int i = 0; i < n; i++)
    cout << querySum(i,i+1) << ' ';
  cout << endl;
  return 0;*/

  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l1, r1, l2, r2;
      cin >> l1 >> r1 >> l2 >> r2;
      l1--, l2--;
      double e1 = querySum(l1,r1)/(r1-l1);
      double e2 = querySum(l2,r2)/(r2-l2);
      double p1 = 1./(r1-l1);
      fma(1-p1, p1*e2, l1,r1);
      double p2 = 1./(r2-l2);
      fma(1-p2, p2*e1, l2,r2);
    } else {
      int l, r;
      cin >> l >> r;
      l--;
      cout << setprecision(20) << querySum(l,r) << '\n';
    }
  }
}