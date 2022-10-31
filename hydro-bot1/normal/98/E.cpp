// Hydro submission #6258ff1ecc64917dc4663942@1649999646789
#include <cstdio>
#include <iostream>
using namespace std;
int n, m;
double f[1010][1010];
void getf(int n, int m) {
	if(f[n][m] > 0) return ;
	if(n == 0) return f[0][m] = 1.0 / (m + 1), void();
	if(m == 0) return f[n][0] = 1.0, void();
	getf(m, n - 1), getf(m - 1, n);
	double a = 1.0, b = 1.0 - f[m][n - 1], c = 1.0 * m / (m + 1) * (1 - f[m - 1][n]);double d = c + 1.0 / (m + 1);
	double p = (-b + d) / (a - b - c + d);
	return f[n][m] = p * a + (1.0 - p) * b, void(); 
}
int main() {
	scanf("%d%d",&n,&m);
	getf(n, m);
	printf("%.10lf %.10lf\n",f[n][m],1.0 - f[n][m]);
}