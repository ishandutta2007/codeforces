#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1<<18;
ll sum[nax*2], put[nax*2];

void push(int i, int w) {
  if (put[i] != -1) {
    sum[i] = w*put[i];
    if (i < nax) {
      put[i*2] = put[i*2+1] = put[i];
    }
    put[i] = -1;
  }
}

ll A[nax];
void querySet(int a, int b, ll v, int l = 0, int r = nax, int i = 1) {
  if (0) {for (int i = a; i < b; i++)
    A[i] = v;
    return;}
  //cout << a << ' ' << b << ' ' << l << ' ' << r << endl;
  push(i, r-l);
  if (a <= l && b >= r) {
    put[i] = v;
    push(i, r-l);
  } else if (b <= l || a >= r) return;
  else {
    int mid = (l+r)>>1;
    querySet(a, b, v, l, mid, i*2);
    querySet(a, b, v, mid, r, i*2+1);
    sum[i] = sum[i*2]+sum[i*2+1];
  }
}

ll querySum(int a, int b, int l = 0, int r = nax, int i = 1) {
  if(0){
    int R = 0;
    for (int i = a; i < b; i++)
      R += A[i];
    return R;
  }
  push(i, r-l);
  if (a <= l && b >= r) {
    return sum[i];
  } else if (b <= l || a >= r) return 0;
  else {
    int mid = (l+r)>>1;
    return querySum(a, b, l, mid, i*2) +
      querySum(a, b, mid, r, i*2+1);
  }
}


int main() {
  fill_n(put, nax*2, -1);
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    for (int i = 0; i < n; i++)
      querySet(i,i+1,b[i]-'0');

    vector<array<int,2>> query(q);
    for (auto&[l,r] : query) cin >> l >> r, l--;
    reverse(query.begin(), query.end());

    int ok = 1;
    for (auto [l,r] : query) {

      int s = querySum(l,r);
      //cout << l << ' ' << r << ' ' << s << endl;
      if (s <= (r-l-1)/2)
        querySet(l,r, 0);
      else if (r-l-s <= (r-l-1)/2)
        querySet(l,r, 1);
      else ok = 0;
    }

    for (int i = 0; i < n; i++)
      if (querySum(i,i+1) != a[i]-'0') ok = 0;

    cout << (ok ? "YES" : "NO") << endl;
  }
}