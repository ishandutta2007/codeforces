#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mins(ll n, ll b, ll p = 1) {
  ll r = 0, d = 1;
  while (1) {
    if (n <= p) {
      r += d*n;
      break;
    }
    n -= p;
    r += d*p;
    p *= b;
    d++;
  }
  return r;
}

ll x[100010];

int main() {
  ios::sync_with_stdio(0);
  ll n, s;
  cin >> n >> s;
  if (s > n*(n+1)/2 || s < 2*n-1) {
    cout << "No" << endl;
    return 0;
  }
  ll pass = n-1, fail = 0;
  while (pass > fail+1) {
    ll b = pass+fail>>1;
    if (mins(n,b) <= s) pass = b;
    else fail = b;
  }
  ll b = pass;

  ll s_cp = s, n_cp = n;
  ll p = 1, depth = 1;
  x[0] = 1;
  while (n > p) {
    ll pass = min(p*b,n-p), fail = 0;
    while (fail+1 < pass) {
      ll mid = pass+fail>>1;
      if (mins(n-p,b,mid) <= s-n) pass = mid;
      else fail = mid;
    }
    x[depth] = pass;
    s -= n;
    n -= x[depth-1];
    p = x[depth];
    depth++;
    //cout << p << endl;
  }
  //cout << s << endl;
  //cout << n << endl;
  n = n_cp;
  s = s_cp;
  ll n_ = 0, s_ = 0;
  for (int i = 0; x[i]; i++) {
    n_ += x[i];
    s_ += (i+1)*x[i];
  }
  /*cout << n << ' ' << n_ << endl;
  cout << s << ' ' << s_ << endl;
  return 0;*/
  cout << "Yes" << endl;
  map<int,int> last;
  last[1] = b;
  ll id = 2;
  for (int i = 1; x[i]; i++) {
    map<int,int> next;
    for (int j = 0; j < x[i]; j++) {
      next[id++] = b;
      auto it = last.begin();
      cout << it->first << ' ';
      if (!--last[it->first])
	last.erase(it->first);
    }
    last = next;
  }
  cout << endl;
}