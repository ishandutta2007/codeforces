#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,int> a[200000], b[200000];

int m, n;
ll f(int k) {
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll d = abs(a[i].first-b[(i+k)%n].first);
    sum += min(d,m-d);
  }
  return sum;
}

pair<ll,int> solve(int l, int r) {
  r--;
  while (r-l >= 5) {
    int mid = l+r>>1;
    if (f(mid) > f(mid+1))
      l = mid+1;
    else
      r = mid;
  }
  for (int i = l+1; i <= r; i++) {
    if (f(i) < f(l)) l = i;
  }
  return {f(l),l};
  /*
  if (0) {
    int a = 0, b = n;
    assert(a <= b);
    while (b - a >= 5) {
      int mid = (a + b) / 2;
      if (f(mid) < f(mid+1))
	a = mid;
      else
	b = mid+1;
    }
    for (int i = a+1; i < b+1; i++)
      if (f(a) < f(i)) a = i;
    cout << f(a) << endl;
  }
  for (int k = l+1; k < r; k++) {
    ans = min(ans, make_pair(f(k),k));
    }*/
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> m >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i].first;
    b[i].second = i;
  }
  sort(a, a+n);
  sort(b, b+n);

  pair<ll,int> ans_a = solve(0,n/2);
  pair<ll,int> ans_b = solve(n/2,n);
  auto ans = min(ans_a, ans_b);
  cout << ans.first << endl;
  vector<int> perm(n);

  for (int i = 0; i < n; i++) {
    perm[a[i].second] = b[(i+ans.second)%n].second;
  }
  for (int i = 0; i < n; i++) {
    cout << perm[i]+1 << ' ';
  }
  cout << endl;
}