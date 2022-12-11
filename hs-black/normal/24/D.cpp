#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template <typename T>
void write(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x >= 10) write(x / 10);
    putchar('0' + x % 10);
}

const int N = 1005;
double F[N][N];
int n, m, x, y;

/*

4f[x][i] = (f[x][i] + f[x][i+1] + f[x][i-1] + f[x+1][i]) + 4;
3f[x][i] - f[x][i+1] - f[x][i-1] = 4 + f[x+1][i]

3f[x][i] = (f[x][i] + f[x][i+1] + f[x+1][i]) + 3
2f[x][i] - f[x][i+1] = f[x+1][i] + 3


*/

double M[N][N];
void build(int lin) {
	M[1][1] = M[m][m] = 2, M[1][2] = M[m][m-1] = -1;
	M[1][m+1] = F[lin+1][1] + 3, M[m][m+1] = F[lin+1][m] + 3;
	for (int i = 2;i < m; i++) 
		M[i][i-1] = M[i][i+1] = -1, 
		M[i][i] = 3, M[i][m+1] = F[lin+1][i] + 4;
}

void work(int lin) {
	for (int i = 1;i < m; i++) {
		double k = M[i+1][i] / M[i][i];
		M[i+1][i] = 0, M[i+1][i+1] -= M[i][i+1] * k;
		M[i+1][m+1] -= M[i][m+1] * k;
	}
	
	F[lin][m] = M[m][m+1] / M[m][m];
	for (int i = m - 1;i >= 1; i--) 
		F[lin][i] = (M[i][m+1] - F[lin][i+1] * M[i][i+1]) / M[i][i];
}

int main() {
	read(n), read(m), read(x), read(y);
	
	if (m == 1) return cout << (n - x) * 2 << endl, 0;
	
	for (int i = n - 1;i >= x; i--) 
		build(i), work(i);
	
	printf ("%.10lf", F[x][y]);
	return 0;
}