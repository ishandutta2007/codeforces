#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353;

int n, m;
int f[32][21][21][21][21][2][2];

inline void add(int &x, int y){
	x += y;
	if(x >= p) x -= p;
}

int x[5], y[5];
int xx[1 << 5][2], yy[1 << 5][2];

inline int cal(int x, int y, int i){
	return (x & 1) < ((m >> i) & 1) || (x & 1) == ((m >> i) & 1) && y;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0;i < n;i++) scanf("%d%d", &x[i], &y[i]);
	for(int i = 0;i < (1 << n);i++) for(int j = 0;j < n;j++) if(i & (1 << j)) xx[i][x[j] > 0] += abs(x[j]), yy[i][y[j] > 0] += abs(y[j]);
	f[0][0][0][0][0][1][1] = 1;
	for(int i = 0;i <= 30;i++) for(int xa = 0;xa < 21;xa++) for(int xb = 0;xb < 21;xb++) for(int ya = 0;ya < 21;ya++) for(int yb = 0;yb < 21;yb++) for(int xm = 0;xm <= 1;xm++) for(int ym = 0;ym <= 1;ym++) for(int j = 0;j < (1 << n);j++){
		int xa_ = xa, xb_ = xb, ya_ = ya, yb_ = yb;
		xa_ += xx[j][0], xb_ += xx[j][1], ya_ += yy[j][0], yb_ += yy[j][1];
		if((xa_ & 1) == (xb_ & 1) && (ya_ & 1) == (yb_ & 1)) add(f[i + 1][xa_ / 2][xb_ / 2][ya_ / 2][yb_ / 2][cal(xa_, xm, i)][cal(ya_, ym, i)], f[i][xa][xb][ya][yb][xm][ym]);
	}
	printf("%d", (f[31][0][0][0][0][1][1] + p - 1) % p);
}