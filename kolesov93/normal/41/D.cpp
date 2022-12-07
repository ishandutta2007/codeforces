#include <stdio.h>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

#define forn(i,n) for (int (i) = 0; (i) < (int) (n); (i)++)
#define N 111
int a[N][N];
char f[N][N][N*10];

int main() {
	int n,m,K;
	cin >> n >> m >> K;
	for (int i=n;i;i--)
		for (int j=1;j<=m;j++) {
			char c = getchar();
			while (c < '0' || c > '9') c = getchar();
			a[i][j] = c - '0';
		}
	
	
	for (int i=1;i<=m;i++)
		f[1][i][a[1][i]] = 'x';
	
	for (int i=1;i<n;i++)
		for (int j=1;j<=m;j++) {
			int lim = 10 * i;
			for (int k=0;k<=lim;k++)
				if (f[i][j][k]) {
					f[i+1][j-1][k + a[i+1][j-1]] = 'L';
					f[i+1][j+1][k + a[i+1][j+1]] = 'R';
				}
		}
	
	int ans = -1, curx, cury=n;
	for (int i=1;i<=m;i++)
		for (int j=0;j<=n*10;j += K+1)
			if (j > ans && f[n][i][j]) {
				curx = i;
				ans = j;
			}
			
	cout << ans << endl;
	if (ans == -1) return 0;		
	
	string way = "";
	while (f[cury][curx][ans] != 'x') {
		int nx,ny = cury-1,nz = ans - a[cury][curx];
		way = f[cury][curx][ans] + way;
		if (f[cury][curx][ans] == 'L') nx = curx + 1;
 		else nx = curx - 1;
 		curx = nx; cury = ny; ans = nz;
	}
	cout << curx << endl;
	cout << way << endl;
	
	
	return 0;
}