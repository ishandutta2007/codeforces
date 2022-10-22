#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int x[100000], y[100000];

double solve(int*x, int*y, int n) {
  ll area = 0;
  for (int i = 0; i < n; i++) {
    ll ax = x[i], bx = x[(i+1)%n];
    ll ay = y[i], by = y[(i+1)%n];
    area += ax*by-ay*bx;
  }
  if (area > 0) {
    reverse(x,x+n);
    reverse(y,y+n);
  }

  vector<ll> count(2e6+10,0);
  ll maxx = -1e9;
  for (int i = 0; i < n; i++) {
    ll ax = x[i], bx = x[(i+1)%n];
    ll ay = y[i], by = y[(i+1)%n];
    for (int j = ax; j < bx; j++) {
      count[j] += (ay*(bx-ax)+(by-ay)*(j-ax))/(bx-ax);
      //cout << (ay*(bx-ax)+(by-ay)*(j-ax))/(bx-ax) << endl;
    }
    for (int j = bx; j < ax; j++) {
      count[j] -= (by*(ax-bx)+(ay-by)*(j-bx)-1)/(ax-bx);
      //cout << "- " << (ay*(ax-bx)+(by-ay)*(j-bx)-1)/(ax-bx) << endl;
    }
    if (ax == bx && by < ay) {
      count[ax] += ay-by;
    }
    maxx = max(maxx, ax);
  }
  count[maxx]++;

  long double sum = 0, sum2 = 0, tot = 0;
  for (int i = 0; i < count.size(); i++) {
    tot += count[i];
    sum += (long double)count[i]*i;
  }
  assert(tot > 1);
  sum /= tot;
  for (int i = 0; i < count.size(); i++) {
    sum2 += count[i]*(i-sum)*(i-sum);
    //if (count[i])
    //  cout << i << ' ' << count[i] << endl;
  }
  return 2*sum2/(tot-1);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    x[i] += 1e6+1;
    y[i] += 1e6+1;
  }
  double ans = 0;
  ans += solve(x,y,n);
  ans += solve(y,x,n);
  cout << setprecision(20) << ans/2 << endl;
}