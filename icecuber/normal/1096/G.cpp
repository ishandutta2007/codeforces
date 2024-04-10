#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353, base = 854599625, M = 2097152;

ll mypow(ll a, ll p) {
  ll r = 1;
  while (p) {
    if (p&1) r = (r*a)%mod;
    a = (a*a)%mod;
    p >>= 1;
  }
  return r;
}

ll cache[M];
void fft(ll*in, ll*out, int n, int stride = 1) {
  if (n == 1) {
    out[0] = in[0];
    return;
  }
  fft(in, out, n/2, stride*2);
  fft(in+stride, out+n/2, n/2, stride*2);
  for (int i = 0; i < n/2; i++) {
    ll f = cache[i*stride]*out[i+n/2]%mod;
    out[i+n/2] = (out[i]-f)%mod;
    out[i] = (out[i]+f)%mod;
  }
}

void ifft(ll*in, ll*out, int n, int stride = 1) {
  if (n == 1) {
    out[0] = in[0];
    return;
  }
  ifft(in, out, n/2, stride*2);
  ifft(in+stride, out+n/2, n/2, stride*2);
  for (int i = 0; i < n/2; i++) {
    ll f = cache[(M-i*stride)%M]*out[i+n/2]%mod;
    //assert(cache[(M-i*stride)%M]*cache[i*stride]%mod==1);
    out[i+n/2] = (out[i]-f)%mod;
    out[i] = (out[i]+f)%mod;
  }
}

ll a[M], b[M];
int main() {
  assert(mypow(base,M/2)==mod-1);
  //cout << (1234*mypow(1234, mod-2))%mod << endl;
  cache[0] = 1;
  for (int i = 1; i < M; i++) {
    cache[i] = cache[i-1]*base%mod;
    //assert(cache[i]==mypow(base,i));
  }
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int d;
    cin >> d;
    a[d] = 1;
  }
  fft(a, b, M);
  ll iM = mypow(M, mod-2);
  for (int i = 0; i < M; i++)
    b[i] = mypow(b[i], n/2)*iM;

  //for (int i = 0; i < 20; i++) cout << b[i] << ' ';
  //cout << endl;
  ifft(b, a, M);
  //for (int i = 0; i < 20; i++) cout << (mypow(M, mod-2)*a[i]%mod+mod)%mod << ' ';
  //cout << endl;
  ll ans = 0;
  for (int i = 0; i < M; i++)
    ans = (ans+mypow(a[i], 2))%mod;
  //ans = iM*ans%mod;
  cout << (ans%mod+mod)%mod << endl;
  /*ll a = 2, i = 0;
  while (a != 1) {
    a *= 2;
    if (a >= mod) a -= mod;
    i++;
  }
  cout << i << endl;*/


}