#include <bits/stdc++.h>
#define maxn 600086

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

int n, m, k;
char s[maxn], t[maxn];
char S[4] = {'A', 'G', 'C', 'T'};
int sum[maxn];

Complex a[maxn], b[maxn];
int ans[maxn];

int main(){
	scanf("%d%d%d%s%s", &n, &m, &k, s + 1, t + 1);
	while(lim <= n + m) lim <<= 1;
	for(int i = 0;i < lim;i++){
		pos[i] = (pos[i >> 1] >> 1) | ((i & 1) ? (lim >> 1) : 0);
	}
	for(int i = 0;i < 4;i++){
		memset(sum, 0, sizeof(sum)), memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
		char c = S[i];
		for(int j = 1;j <= n;j++){
			if(s[j] == c) sum[max(1, j - k)]++, sum[min(n + 1, j + k + 1)]--;
		}
		for(int j = 1;j <= n;j++){
			sum[j] += sum[j - 1];
			if(sum[j]) a[j].x = 1;
		}
		for(int j = 1;j <= m;j++){
			if(t[j] == c) b[m + 1 - j].x = 1;
		}
		FFT(a, 1), FFT(b, 1);
		for(int j = 0;j < lim;j++) a[j] = a[j] * b[j];
		FFT(a, -1);
		for(int j = 1;j + m - 1 <= n;j++){
			ans[j] += (int)(a[m + j].x + 0.5);
			//printf("%d %d--\n", j, (int)(a[m + j].x + 0.5));
		}
	}
	int cnt = 0;
	for(int i = 1;i <= n;i++) cnt += ans[i] == m;
	printf("%d", cnt);
	
	
}