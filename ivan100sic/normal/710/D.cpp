#include "bits/stdc++.h"
using namespace std;

long long a1, a2, b1, b2, L, R;

long long gcd(long long a, long long b){
	long long t;
	while (b != 0){
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

long long xGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    long long x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

long long modinv(long long a, long long mod){
	long long w, q;
	xGCD(a, mod, w, q);
	
	w %= mod;
	if (w < 0) w += mod;
	return w;
}

long long mmod(long long a, long long b, long long mod){
	long long z = 0;
	a %= mod;
	b %= mod;
	for (long long i=62; i>=0; i--){
		z = (z + z);
		if (z >= mod) z -= mod;
		if (a & (1ll<<i)){
			z += b;
			if (z >= mod) z -= mod;
		}
	}
	return z;
}

long long floordiv(long long a, long long b){
	if (a > 0) return a/b;
	if (a==0) return 0;
	if (a % b == 0) return a/b;
	return a/b-1;
}

int main(){
	cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
	
	cerr << mmod(1000000000, 1000000001, 1000000000000000000) << endl;
	
	long long g = gcd(a1, a2);
	
	// ako postoji perioda onda je ona tacno NZS(a1, a2)
	long long nzs = a1*a2/g;
	
	long long m1 = b1 % a1;
	if (m1 < 0) m1 += a1;
	
	long long m2 = b2 % a2;
	if (m2 < 0) m2 += a2;
	
	if (m1 % g != m2 % g){
		cout << 0;
		return 0;
	}
	
	long long diff = (m2 - m1) % a2;
	if (diff < 0) diff += a2;
	long long q = modinv(a1, a2);
	
	q *= diff /= g;
	
	long long mm = (m1 + mmod(q, a1, nzs)) % nzs;
	cerr << mm << endl;
	
	L = max(L, max(b1, b2));
	
	L -= mm - nzs;
	R -= mm - nzs;
	
	L--;
	
	long long domg = floordiv(R, nzs) - floordiv(L, nzs);
	if (domg < 0) domg = 0;
	
	cout << domg;

	cin >> L;

	return 0;
}