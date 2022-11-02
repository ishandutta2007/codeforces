#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <map>
#include <set>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int mod = 998244353;

int root;
int root_1;
const int root_pw = 1<<23;

int Pow(int x, int y, int mod) {
  int res = 1;
  while (y) {
    if (y % 2 == 1) {
      --y;
      res = (res * (int64) x) % mod;
    } else {
      y /= 2;
      x = (x * (int64) x) % mod;
    }
  }
  return res;
}


const int L = 1 << 18;
vi f(L), rf(L);

//int R[L];

int reverse(int x, int mod) {
//  return R[x];
  return Pow(x, mod - 2, mod);
}

void fft (vector<int> & a, bool invert) {
	int n = (int) a.size();

	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}

	for (int len=2; len<=n; len<<=1) {
		int wlen = invert ? root_1 : root;
		for (int i=len; i<root_pw; i<<=1)
			wlen = int (wlen * 1ll * wlen % mod);
		for (int i=0; i<n; i+=len) {
			int w = 1;
			for (int j=0; j<len/2; ++j) {
				int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
				a[i+j] = u+v < mod ? u+v : u+v-mod;
				a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
				w = int (w * 1ll * wlen % mod);
			}
		}
	}
	if (invert) {
		int nrev = reverse (n, mod);
		for (int i=0; i<n; ++i)
			a[i] = int (a[i] * 1ll * nrev % mod);
	}
}





int64 C(int n, int k) {
    int64 res = f[n] * (int64) rf[k];
    res %= mod;
    res *= rf[n - k];
    res %= mod;
    return res;
}

void mult(vi& a, vi b) {
  fft(a, false);
  //fft(b, false);
  for (int i = 0; i < sz(a); ++i)
    a[i] = (a[i] * (int64) b[i]) % mod;
  fft(a, true);
  for (int i = L / 2; i < sz(a); ++i)
    a[i] = 0;
}

vi mult2(vi& a) {
  fft(a, false);
  vi res = a;
  for (int i = 0; i < sz(a); ++i)
    a[i] = (a[i] * (int64) a[i]) % mod;
  fft(a, true);
  for (int i = L / 2; i < sz(a); ++i)
    a[i] = 0;
  return res;
} 

int main() {
  root = 1;
  while (Pow(root, root_pw, mod) != 1 || Pow(root, root_pw / 2, mod) == 1)
    ++root;
  root_1 = Pow(root, mod - 2, mod);

//  R[1] = 1;
//  for (int i = 2; i < L ; ++i)
//    R[i] = Pow(i, mod - 2, mod);


  int n, a, b;
  cin >> n >> a >> b;
  if (a == 0 || b == 0) {
    printf("0\n");
    return 0;
  }
  if (a + b  - 1> n) {
    printf("0\n");
    return 0;
  }
  vi basic(L, 0);
  for (int i = 1; i < L / 2; ++i) {
    basic[i] = Pow(i, mod - 2, mod);
  }
  vi p2[20];
  vi pp2[20];
  p2[1] = basic;
  pp2[1] = basic;
  fft(pp2[1], false);
  for (int i = 2; i < 19; ++i) {
    p2[i] = p2[i - 1];
    pp2[i - 1] = mult2(p2[i]);
  }
  //fft(basic, false);

  vi va(L, 0), vb(L, 0);
  va[0] = 1, vb[0] = 1;
  for (int i = 1; i < 20; ++i) {
//    cerr << i << "\n";
    if (((a - 1) >> (i - 1)) % 2 == 1)
      mult(va, pp2[i]);
    if (((b - 1) >> (i - 1)) % 2 == 1)
      mult(vb, pp2[i]);
  }
//  vi va = basic, vb = basic;
//  for (int i = 0; i < L; ++i) {
//    va[i] = Pow(va[i], a - 1, mod);
//    vb[i] = Pow(vb[i], b - 1, mod);
//  }
//  fft(va, true);
//  fft(vb, true);

//  for (int i = 0; i < 20; ++i)
//    cout << va[i] << " ";
//  cout << "\n";

  int64 mult = 1;
  for (int i = a; i < L; ++i) {
    mult *= i;
    mult %= mod;
    va[i] = (va[i] * mult) % mod;
  }

  mult = 1;
  for (int i = b; i < L; ++i) {
    mult *= i;
    mult %= mod;
    vb[i] = (vb[i] * mult) % mod;
  }

//  for (int i = 0; i < 20; ++i)
//     cout << va[i] << " ";
//  cout << "\n";
//
//  for (int i = 0; i < 20; ++i)
//     cout << vb[i] << " ";
//  cout << "\n";

  f[0] = 1;
  rf[0] = 1;
  for (int i = 1; i < sz(f); ++i) {
      f[i] = (int) ((f[i - 1] * (int64) i) % mod);
      //rf[i] = (int) ((rf[i - 1] * (int64) R[i]) % mod);
      rf[i]= Pow(f[i], mod - 2, mod);
  }

  int64 res = 0;
  for (int i = 0; i < n; ++i) {
    int ind1 = i ;
    int ind2 = n - i - 1 ;
      int64 cur = ind1 >= 0 ? va[ind1] : 0LL;
      if (cur == 0) continue;
      if (vb[ind2] == 0) continue;
      cur *= ind2 >= 0 ? vb[ind2] : 0LL;
//      cerr << (ind1 >= 0 ? va[ind1] : 0LL) << " " << (ind2 >= 0 ? vb[ind2] : 0LL) << "\n";
      cur %= mod;
      cur *= C(n - 1, i);
      cur %= mod;
      res += cur;
      res %= mod;
  }
  cout << res << "\n";

  return 0;
}