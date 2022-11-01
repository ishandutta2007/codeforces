#include <bits/stdc++.h>
#define maxn 100086

using namespace std;//

int n;
int a[maxn], b[maxn], c[maxn];
int x, y, lastx, lasty;

inline void get(int i, int &u, int &v){
	printf("+ %d\n", i);
	fflush(stdout);
	scanf("%d%d", &x, &y);
	u = x - lastx, v = y - lasty, lastx = x, lasty = y;
}

inline int C(int x){
	for(int i = 1;;i++) if(i * (i - 1) / 2 == x) return i; 
}

int main(){
	scanf("%d%d%d", &n, &lastx, &lasty);
	for(int i = 2;i <= n - 2;i++) get(i, b[i], c[i]);
	int u1, v1, u2, v2, u3, v3;
	get(n, u1, v1), get(n - 1, u2, v2), get(n, u3, v3);
	a[n] = C(u3) - 1;
	a[n - 2] = v3 - v1 - 1;
	a[n - 1] = v1 / (a[n - 2] + 1);
	a[n - 3] = (v2 - (a[n - 2] + 1) * (a[n] + 1)) / (a[n - 2] + 1) - 1;//debug:a[n-3] a[n]1 
	for(int i = n - 4;i;i--){//debug:cb 
		a[i] = (c[i + 2] - (a[i + 1] + 1) * a[i + 3] - a[i + 3] * a[i + 4]) / (a[i + 1] + 1) - 1;
	}
	++a[1];//1 
	printf("!");
	for(int i = 1;i <= n;i++) printf(" %d", a[i]);
}