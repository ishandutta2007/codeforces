#include <bits/stdc++.h>
#define maxn 800086

using namespace std;

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

int lim = 1;//lim(0lim-1) 2
int pos[maxn];// 

void FFT(Complex *a, int type){
	for(int i = 0;i < lim;i++){
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

int n, m;
int p[26];
char s[maxn], t[maxn];
Complex a[maxn], b[maxn];
double sum[maxn]; 


int main(){
	for(int i = 0;i < 26;i++) scanf("%d", &p[i]), --p[i];//debug:1-26 
	scanf("%s%s", s, t); 
	n = strlen(t), m = strlen(s);
	for(int i = 0;i < n;i++) t[i] -= 'a';
	for(int i = 0;i < m;i++) s[i] -= 'a';
	reverse(s, s + m);
	while(lim < n) lim <<= 1;
	for(int i = 0;i < lim;i++){
		pos[i] = (pos[i >> 1] >> 1) | ((i & 1) ? (lim >> 1) : 0);
	}
	for(int i = 0;i < n;i++) a[i] = Complex(pow(t[i], 4), 0);
	for(int i = 0;i < m;i++) b[i] = 1;
	FFT(a, 1), FFT(b, 1);
	for(int i = 0;i < lim;i++) a[i] = a[i] * b[i];
	FFT(a, -1);
	for(int i = 0;i < n - m + 1;i++) sum[i] += a[m + i - 1].x;
	
	memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
	for(int i = 0;i < n;i++) a[i] = Complex(pow(t[i], 3), 0);
	for(int i = 0;i < m;i++) b[i] = Complex(-2 * (s[i] + p[s[i]]), 0);
	FFT(a, 1), FFT(b, 1);
	for(int i = 0;i < lim;i++) a[i] = a[i] * b[i];
	FFT(a, -1);
	for(int i = 0;i < n - m + 1;i++) sum[i] += a[m + i - 1].x;
	
	memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
	for(int i = 0;i < n;i++) a[i] = Complex(pow(t[i], 2), 0);
	for(int i = 0;i < m;i++) b[i] = Complex(s[i] * s[i] + 4 * s[i] * p[s[i]] + p[s[i]] * p[s[i]], 0);
	FFT(a, 1), FFT(b, 1);
	for(int i = 0;i < lim;i++) a[i] = a[i] * b[i];
	FFT(a, -1);
	for(int i = 0;i < n - m + 1;i++) sum[i] += a[m + i - 1].x;
	
	memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
	for(int i = 0;i < n;i++) a[i] = Complex(t[i], 0);
	for(int i = 0;i < m;i++) b[i] = Complex(-2 * s[i] * p[s[i]] * (s[i] + p[s[i]]), 0);
	FFT(a, 1), FFT(b, 1);
	for(int i = 0;i < lim;i++) a[i] = a[i] * b[i];
	FFT(a, -1);
	for(int i = 0;i < n - m + 1;i++) sum[i] += a[m + i - 1].x;
	
	memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
	for(int i = 0;i < n;i++) a[i] = Complex(1, 0);
	for(int i = 0;i < m;i++) b[i] = Complex(s[i] * s[i] * p[s[i]] * p[s[i]], 0);
	FFT(a, 1), FFT(b, 1);
	for(int i = 0;i < lim;i++) a[i] = a[i] * b[i];
	FFT(a, -1);
	for(int i = 0;i < n - m + 1;i++) sum[i] += a[m + i - 1].x;
	
	for(int i = 0;i < n - m + 1;i++) printf("%d", ((int)(sum[i] + 0.5) == 0)); 
}