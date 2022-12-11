#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
const int N = 3000600;
ll sum, a[N];

template <typename T>
void read(T &x) {
	x = 0; bool f = 0;
	char c = getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
	for (;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	if (f) x = -x;
}

struct Complex {
	double x, y;
	Complex (double xx = 0,double yy = 0) {x=xx,y=yy;}
	Complex operator + (Complex &i) const {
		return Complex(x + i.x, y + i.y);
	}
	Complex operator - (Complex &i) const {
		return Complex(x - i.x, y - i.y);
	}
	Complex operator * (Complex &i) const {
		return Complex(x * i.x - y * i.y, x * i.y + y * i.x);
	}
}A[N], B[N];

const double Pi = acos(-1.0);

int n, m, k;

int lim = 1, L;
int r[N];

void FFT(Complex *a,int type) {
	for (int i = 0;i < lim; i++)
	if (r[i] > i) swap(a[r[i]], a[i]);
	for (int mid = 1;mid < lim; mid <<= 1) {
		Complex T(cos(Pi/mid), type * sin(Pi/mid));
		for (int j = 0;j < lim; j += (mid << 1)) {
			Complex t(1, 0);
			for (int k = 0;k < mid; k++, t = t * T) {
				Complex x = a[j + k], y = t * a[mid + j + k];
				a[k + j] = x + y;
				a[mid + j + k] = x - y;
			}
		}
	}
}
		
ll calc(void) {
	ll res = 0, p = 0;
	for (ll i = 1;i <= n; i++) {
		if (a[i]) p = i;
		res += i - p;
	}
	return res;
}

int main() {
	read(n), read(k); m = n;
	for (ll i = 1;i <= n; i++) {
		read(a[i]); a[i] = a[i] < k;
		sum += a[i]; A[sum].x += 1;
	}
	A[0].x += 1;
	for (ll i = 0;i <= n; i++) B[i] = A[n-i];
	while (lim <= (n + m)) lim <<= 1, L++;
	for (int i = 0;i < lim; i++)
	r[i] = (r[i>>1]>>1) | ((i&1) << (L-1));
	
	FFT(A, 1); FFT(B, 1);
	for (int i = 0;i <= lim; i++) A[i] = A[i] * B[i];
	FFT(A, -1);
	cout << calc() << ' ';
	for (int i = 1;i <= n; i++)
	printf ("%lld ", (ll)(A[i+n].x / lim + 0.5));
	return 0;
}