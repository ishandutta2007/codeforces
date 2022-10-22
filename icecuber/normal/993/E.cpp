#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef complex<double> C;

const int nax = 1<<19;
C a[nax], a_[nax], b_[nax];
C cache[2][nax];

void fft(C*in, C*out, int inv, int n = nax, int stride = 1) {
  if (n == 1) {
    out[0] = in[0];
    return;
  }
  int n2 = n/2;
  fft(in,out,inv,n2,stride*2);
  fft(in+stride,out+n2,inv,n2,stride*2);
  for (int i = 0; i < n2; i++) {
    C a = out[i], b = cache[inv][i*stride]*out[i+n2];
    out[i] = a+b;
    out[i+n2] = a-b;
  }
}

int main() {
  for (int k = 0; k < 2; k++)
    for (int i = 0; i < nax; i++)
      cache[k][i] = exp((k ? 1. : -1.)*C(0,1)*2.*acos(-1)*(i*1./nax));

  ios::sync_with_stdio(0); cin.tie(0);
  int n, x;
  cin >> n >> x;
  ll ans0 = 0;
  int pref = 0;
  a[0] += 1;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    pref += (v < x);
    ans0 += ll(a[pref].real());
    a[pref] += 1;
  }

  fft(a, a_, 0);
  fft(a, b_, 1);
  for (int i = 0; i < nax; i++)
    a_[i] *= b_[i]*(1./nax);
  fft(a_, a, 1);

  cout << ans0 << ' ';
  for (int i = 1; i <= n; i++)
    cout << ll(a[i].real()+0.5) << ' ';
  cout << endl;
}