#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct Num {
  ull a[5];
};

Num operator*(const Num&a, const Num&b) {
  Num r = {};
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      r.a[i+j>=5 ? i+j-5 : i+j] += a.a[i]*b.a[j];
  return r;
}

Num operator+(const Num&a, const Num&b) {
  Num r = {};
  for (int i = 0; i < 5; i++)
    r.a[i] = a.a[i]+b.a[i];
  return r;
}

Num W[10][10], Wi[10][10];

void dft(Num*a, int stride, int inv = 0) {
  Num(*w)[10] = inv ? Wi : W;
  Num a_[10];
  for (int i = 0; i < 10; i++) {
    Num r = {};
    for (int j = 0; j < 10; j++) {
      r = r+w[i][j]*a[j*stride];
    }
    a_[i] = r;
  }
  for (int i = 0; i < 10; i++)
    a[i*stride] = a_[i];
}

Num A[100000];

Num fastpow(Num a, ull p) {
  Num ans = {1}, mul = a;
  while (p) {
    if (p&1) ans = ans*mul;
    mul = mul*mul;
    p >>= 1;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  //Num a = {2,0,0,0,1}, b = {2,1,3};
  //Num c = a*b;
  //for (int i = 0; i < 5; i++) cout << c.a[i] << ' ';
  //cout << endl;
  Num w = {0,0,0,0,-1ull}, one = {1};
  W[1][0] = one;
  for (int j = 1; j < 10; j++)
    W[1][j] = W[1][j-1]*w;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++) {
      W[i][j] = W[1][i*j%10];
      Wi[i][j] = W[1][(10-i*j%10)%10];
    }

  if (0) {
    Num a[10] = {};
    for (int i = 0; i < 10; i++) {
      a[i].a[0] = i;
    }
    dft(a,1);
    dft(a,1,1);
    Num five = {5};
    Num inv5 = fastpow(five,(1ull<<62)-1);
    /*{Num one = five*inv5;
      cout << one.a[0] << ' ' << one.a[1] << ' ' << one.a[2] << ' ' << one.a[3] << ' ' << one.a[4] << endl;
      }*/
    for (int i = 0; i < 10; i++) {
      assert(a[i].a[1] == a[i].a[2]);
      a[i] = a[i]*inv5;
      a[i].a[0] -= a[i].a[1];
      cout << (a[i].a[0]>>1) << ' ';
    }
    cout << endl;
    return 0;
  }


  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    A[x] = A[x]+one;
  }
  for (int D = 0; D < 5; D++) {
    for (int a = 0; a < 10; a++)
      for (int b = 0; b < 10; b++)
	for (int c = 0; c < 10; c++)
	  for (int d = 0; d < 10; d++)
	    for (int e = 0; e < 10; e++) {
	      if (a&&D==0 || b&&D==1 || c&&D==2 || d&&D==3 || e&&D==4) continue;
	      dft(A+a+b*10+c*100+d*1000+e*10000, pow(10,D));
	    }
  }
  for (int i = 0; i < 100000; i++) {
    A[i] = fastpow(A[i], n);
  }
  for (int D = 0; D < 5; D++) {
    for (int a = 0; a < 10; a++)
      for (int b = 0; b < 10; b++)
	for (int c = 0; c < 10; c++)
	  for (int d = 0; d < 10; d++)
	    for (int e = 0; e < 10; e++) {
	      if (a&&D==0 || b&&D==1 || c&&D==2 || d&&D==3 || e&&D==4) continue;
	      dft(A+a+b*10+c*100+d*1000+e*10000, pow(10,D), 1);
	    }
  }

  Num five = {5};
  Num inv5 = fastpow(fastpow(five,5),(1ull<<62)-1);
  for (int i = 0; i < n; i++) {
    A[i] = A[i]*inv5;
    cout << ((A[i].a[0]-A[i].a[1])>>5&(1ull<<58)-1) << ' ';
  }
  cout << endl;
}