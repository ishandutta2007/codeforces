#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e7+10;
int isprime[nax], phi[nax], fac[nax];

#define data erlkgjerlgj
int data[nax];
void add(int i, int v) {
  for (i++; i < nax; i+=i&-i) data[i] += v;
}
int sum(int i) {
  int r = 0;
  for (i++; i; i-=i&-i) r += data[i];
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  fill_n(isprime+2, nax-2, 1);
  for (int i = 0; i < nax; i++) phi[i] = i;
  for (int i = 2; i < nax; i++) {
    if (!isprime[i]) continue;
    for (int j = i*2; j < nax; j += i) {
      isprime[j] = 0;
    }
    for (int j = i; j < nax; j += i) {
      phi[j] = phi[j]/i*(i-1);
      if (!fac[j]) fac[j] = i;
    }
  }
  ll zeros = 1;
  for (int i = 2; i <= n; i++) {
    if (isprime[i] && i*2 > n) zeros++;
  }
  zeros = n*(n-1)/2-(n-zeros)*(n-zeros-1)/2;
  ll ones = 0;
  for (int i = 2; i <= n; i++) {
    ones += i-1-phi[i];
  }
  ll twos = -ones;
  for (int i = 2; i <= n; i++) {
    twos += sum(n/fac[i]);
    if (!isprime[i]) {

    }
    add(fac[i], 1);
  }
  ll threes = (ll)n*(n-1)/2-zeros-ones-twos;
  //cout << zeros << ' ' << ones << ' ' << twos << ' ' << threes << endl;
  cout << ones + 2 * twos + 3 * threes << endl;
}