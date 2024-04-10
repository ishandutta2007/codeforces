#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll la, ra, ta, lb, rb, tb;
  cin >> la >> ra >> ta >> lb >> rb >> tb;
  ll g = __gcd(ta,tb);
  ll wa = ra-la+1, wb = rb-lb+1;
  ll r = 0;
  ll ob = ((lb-la)%g+g)%g;
  r = max(r, min(wa, ob+wb)-ob);
  ll oa = ((la-lb)%g+g)%g;
  r = max(r, min(oa+wa, wb)-oa);
  cout << r << endl;
}