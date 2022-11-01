#include <bits/stdc++.h>
#define maxn 1000086

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
Complex a[maxn], b[maxn];

int n, m, y;
int x, q;
int ans[maxn];

int main(){
	scanf("%d%d%d", &n, &m, &y);
	for(int i = 0;i <= n;i++){
		scanf("%d", &x);
		a[x].x = 1, b[m - x].x = 1;
	}
	while(lim <= m * 2) lim <<= 1;//  
	for(int i = 0;i < lim;i++){
		pos[i] = (pos[i >> 1] >> 1) | ((i & 1) ? (lim >> 1) : 0);//i>>1i 1 
	} 
	FFT(a, 1), FFT(b, 1);
	for(int i = 0;i < lim;i++) a[i] = a[i] * b[i];
	FFT(a, -1);
	for(int i = 0;i < m;i++){
		if((int)(a[i].x + 0.5) == 0) continue;
		x = 2 * ((m - i) + y);
		for(int j = 1;x * j <= 1e6;j++){
			ans[x * j] = max(ans[x * j], x);
		}
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d", &x);
		printf("%d ", ans[x] ? ans[x] : -1);
	}
}