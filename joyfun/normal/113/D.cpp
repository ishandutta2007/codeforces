#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 505;
const double eps = 1e-8;
#define rep(i,a,b) for(int i=a;i<b;i++)
double A[N][N];

void Gauss(int n, int m) {
	int i = 0, x = 0;
	for (; i < n && x < m; i++, x++) {
		int r = i;
		rep(j,i+1,n) if (fabs(A[j][x]) > fabs(A[r][x])) {r=j;}
		if (fabs(A[r][x]) < eps) --i;
		else {
			if (r!=i) rep(j,0,m+1) swap(A[r][j],A[i][j]);
			for (int j = m; j >= x; j--) A[i][j] /= A[i][x];
			rep(j,0,n) if (i!=j && A[j][x])
			for (int k = m; k >= x; k--)
				A[j][k] -= A[i][k] * A[j][x];
		}
	}
}

int n, a, b, m;
int g[25][25], d[25];
double p[25][25];

int main() {
	scanf("%d%d%d%d", &n, &m, &a, &b);
	a--; b--;
	int u, v;
	while (m--) {
		scanf("%d%d", &u, &v);
		u--; v--;
		g[u][v] = g[v][u] = 1;
		d[u]++; d[v]++;
	}
	for (int i = 0; i < n; i++) scanf("%lf", &p[i][i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j && g[i][j]) p[i][j] = (1 - p[i][i]) / d[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			A[i * n + j][i * n + j] -= 1;
			if (i == j) continue;
			for (int k = 0; k < n; k++) 
				for (int l = 0; l < n; l++) 
					A[k * n + l][i * n + j] += p[i][k] * p[j][l];
		}
	}
	A[a * n + b][n * n] -= 1.0;
/*	for (int i = 0; i < n*n; i++)
	{
		for(int j=v=i;j<n*n;j++)
			if(fabs(A[j][i])>fabs(A[v][i]))
				v=j;
		for (int k =0; k <=n*n; k++)
			swap(A[v][k],A[i][k]);
		double u;
		u=A[i][i];
		for (int k = 0; k <=n * n ;k++)
			A[i][k]/=u;
		for (int j =0; j<n*n;j++)
			if(u=A[j][i],i!=j)
				for (int k = 0; k <=n * n;k++)
					A[j][k]-=u*A[i][k];
	}*/
	Gauss(n * n, n * n);
	for (int i = 0; i < n; i++) printf("%.10f ", A[i * n + i][n * n]); printf("\n");
	return 0;
}