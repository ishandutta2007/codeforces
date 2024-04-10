#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod, phi;
ll fastpow(ll a, ll p) {
  ll r = 1;
  while (p) {
    if (p&1) r = (r*a)%mod;
    a = a*a%mod;
    p >>= 1;
  }
  return r;
}

ll inv(ll a) {
  return fastpow(a, phi-1);
}

int facs = 0;
ll fac[10];

struct Num {
  ll r, val;
  int c[10];
  Num() {
    for (int i = 0; i < facs; i++) c[i] = 0;
    r = 1;
    val = 1;
  }
  Num(ll x) {
    val = x%mod;
    for (int i = 0; i < facs; i++) {
      c[i] = 0;
      while (x%fac[i]==0) c[i]++, x /= fac[i];
    }
    r = x%mod;
    /*ll val_ = val;
    update_val();
    if (val_ != val) {
      cout << x << ' ' << val << endl;
      cout << val_ << ' ' << val << endl;
      for (int i = 0; i < facs; i++)
	cout << c[i] << ' ';
      cout << endl;
      exit(0);
      }*/
  }
  ll update_val() {
    val = r;
    for (int i = 0; i < facs; i++)
      val = val*fastpow(fac[i], c[i])%mod;
  }
  Num& operator*=(const Num&n) {
    r = r*n.r%mod;
    for (int j = 0; j < facs; j++)
      c[j] += n.c[j];
    val = val*n.val%mod;
    return *this;
  }
};

const int N = 1<<17;
ll sum[N*2];
Num mul[N*2];

void prop(int i) {
  if (i < N) {
    mul[i*2] *= mul[i];
    mul[i*2+1] *= mul[i];
    sum[i*2] = sum[i*2]*mul[i].val%mod;
    sum[i*2+1] = sum[i*2+1]*mul[i].val%mod;
    mul[i] = Num();
  }
}
void range_mul(int a, int b, Num&n, int x = 0, int y = N, int i = 1) {
  prop(i);
  if (b <= x || a >= y) return;
  if (a <= x && b >= y) {
    mul[i] *= n;
    sum[i] = sum[i]*n.val%mod;
    return;
  }
  int mid = x+y>>1;
  range_mul(a, b, n, x,mid,i*2);
  range_mul(a, b, n, mid,y,i*2+1);
  sum[i] = (sum[i*2]+sum[i*2+1])%mod;
}
ll range_sum(int a, int b, int x = 0, int y = N, int i = 1) {
  prop(i);
  if (b <= x || a >= y) return 0;
  if (a <= x && b >= y)
    return sum[i];
  int mid = x+y>>1;
  return (range_sum(a, b, x,mid,i*2)+range_sum(a, b, mid,y,i*2+1))%mod;
}
void div(int i, Num&n) {
  i += N;
  for (int j = 17; j >= 0; j--)
    prop(i>>j);
  mul[i].r = mul[i].r*inv(n.r)%mod;
  for (int j = 0; j < facs; j++)
    mul[i].c[j] -= n.c[j];
  mul[i].update_val();
  sum[i] = mul[i].val;
  for (int j = 1; j <= 17; j++)
    sum[i>>j] = (sum[(i>>j)*2]+sum[(i>>j)*2+1])%mod;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n >> mod;

  ll p = mod;
  phi = 1;
  for (ll i = 2; i*i <= p || i < 100000; i++) {
    if (p%i == 0) {
      if (i < 100000)
	fac[facs++] = i;
      p /= i;
      phi *= i-1;
      while (p%i == 0) {
	phi *= i;
	p /= i;
      }
    }
  }
  if (p > 1) phi *= p-1;
  //cout << phi << endl;
  //return 0;
  /*{
    ll t = 123457;
    cout << __gcd(t, mod) << endl;
    assert((inv(t)*t%mod+mod)%mod==1);
    }*/

  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    mul[N+i] = Num(a);
    sum[N+i] = a%mod;
  }
  for (int i = N-1; i; i--)
    sum[i] = (sum[i*2]+sum[i*2+1])%mod;
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    int i, l, r, x;
    if (t == 1) {
      cin >> l >> r >> x;
      l--;
      Num n(x);
      range_mul(l,r,n);
    } else if (t == 2) {
      cin >> i >> x;
      Num n(x);
      div(i-1,n);
    } else {
      cin >> l >> r;
      l--;
      ll ans = range_sum(l,r);
      cout << (ans%mod+mod)%mod << endl;
    }
    /*for (int i = 0; i < n; i++)
      cout << range_sum(i,i+1) << ' ';
      cout << endl;*/
  }
}