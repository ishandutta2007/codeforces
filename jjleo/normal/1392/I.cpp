#include <bits/stdc++.h>
#define maxn 270086

using namespace std;

typedef long long ll;

const double pi = acos(-1);

struct Complex{
	double x, y;
	Complex(double xx = 0, double yy = 0){
		x = xx, y = yy;
	}
};

Complex operator + (Complex a, Complex b){
	return Complex(a.x + b.x, a.y + b.y);
}

Complex operator - (Complex a, Complex b){
	return Complex(a.x - b.x, a.y - b.y);
}

Complex operator * (Complex a, Complex b){
	return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}

int pos[maxn];// 

void FFT(Complex *a, int lim, int type){
	for(int i = 0;i < lim;i++){
		pos[i] = (pos[i >> 1] >> 1) | ((i & 1) ? (lim >> 1) : 0);//i>>1i 1 
		if(i < pos[i]) swap(a[i], a[pos[i]]);// pos[pos[i]] = i  
	}
	for(int mid = 1;mid < lim;mid <<= 1){// n/2
		Complex wn(cos(pi / mid), type * sin(pi / mid));// 
		for(int i = mid << 1, j = 0;j < lim;j += i){//i j 
			Complex w(1, 0);//
			for(int k = 0;k < mid;k++, w = w * wn){// O(1) 
				Complex x = a[j + k], y = w * a[j + k + mid];
				a[j + k] = x + y;
				a[j + k + mid] = x - y;
			} 
		}
	}
	if(type == -1) for(int i = 0;i < lim;i++) a[i].x /= lim;
} 

int n, m, q, x;
int a[maxn], b[maxn], mxa[maxn], mxb[maxn], mna[maxn], mnb[maxn];
Complex A[maxn], B[maxn], Mxa[maxn], Mxb[maxn], Mna[maxn], Mnb[maxn];
Complex d[maxn], h1[maxn], h2[maxn], l1[maxn], l2[maxn], g1[maxn], g2[maxn];
ll D[maxn], H1[maxn], H2[maxn], L1[maxn], L2[maxn], G1[maxn], G2[maxn];


int main(){
	scanf("%d%d%d", &n, &m, &q);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 1;i <= m;i++) scanf("%d", &b[i]);
	for(int i = 1;i < n;i++) mna[i] = min(a[i], a[i + 1]), mxa[i] = max(a[i], a[i + 1]);
	for(int i = 1;i < m;i++) mnb[i] = min(b[i], b[i + 1]), mxb[i] = max(b[i], b[i + 1]);
	for(int i = 1;i <= n;i++) A[a[i]].x++;
	for(int i = 1;i <= m;i++) B[b[i]].x++;
	for(int i = 1;i < n;i++) Mxa[mxa[i]].x++, Mna[mna[i]].x++;
	for(int i = 1;i < m;i++) Mxb[mxb[i]].x++, Mnb[mnb[i]].x++;
	int lim = 1 << 18;
	FFT(A, lim, 1), FFT(B, lim, 1), FFT(Mxa, lim, 1), FFT(Mna, lim, 1), FFT(Mxb, lim, 1), FFT(Mnb, lim, 1);
	for(int i = 0;i < lim;i++){
		d[i] = A[i] * B[i];
		h1[i] = A[i] * Mxb[i];
		h2[i] = A[i] * Mnb[i];
		l1[i] = Mxa[i] * B[i];
		l2[i] = Mna[i] * B[i];//debugab  
		g1[i] = Mxa[i] * Mxb[i];
		g2[i] = Mna[i] * Mnb[i];
	}
	FFT(d, lim, -1), FFT(h1, lim, -1), FFT(h2, lim, -1), FFT(l1, lim, -1), FFT(l2, lim, -1), FFT(g1, lim, -1), FFT(g2, lim, -1);
	for(int i = 0;i < lim;i++){
		//printf("%d %lld %lld %lld %lld--\n", i, (ll)(d[i].x + 0.5), (ll)(h2[i].x + 0.5), (ll)(l2[i].x + 0.5), (ll)(g2[i].x + 0.5));
		D[i] = (ll)(d[i].x + 0.5) + (i ? D[i - 1] : 0);
		H1[i] = (ll)(h1[i].x + 0.5) + (i ? H1[i - 1] : 0);
		H2[i] = (ll)(h2[i].x + 0.5) + (i ? H2[i - 1] : 0);
		L1[i] = (ll)(l1[i].x + 0.5) + (i ? L1[i - 1] : 0);
		L2[i] = (ll)(l2[i].x + 0.5) + (i ? L2[i - 1] : 0);
		G1[i] = (ll)(g1[i].x + 0.5) + (i ? G1[i - 1] : 0);
		G2[i] = (ll)(g2[i].x + 0.5) + (i ? G2[i - 1] : 0);
	}
	while(q--){
		scanf("%d", &x), x--;
		ll v1 = D[x], v2 = D[lim - 1] - D[x];
		ll e1 = H1[x] + L1[x], e2 = H2[lim - 1] - H2[x] + L2[lim - 1] - L2[x];
		ll q1 = G1[x], q2 = G2[lim - 1] - G2[x];
		//printf("%lld %lld %lld %lld %lld %lld--\n", v1, v2, e1, e2, q1, q2);
		printf("%lld\n", -(v1 - v2 - e1 + e2 + q1 - q2));
	}
}