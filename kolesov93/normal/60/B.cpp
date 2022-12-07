#include <stdio.h>
#include <iostream>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int n,m,k;
char a[22][22][22];

int calc(int z, int x, int y) {
	if (a[z][x][y] == '#') return 0;
	a[z][x][y] = '#';
	return calc(z+1,x,y) + calc(z-1,x,y) + calc(z,x-1,y) + calc(z,x+1,y) + calc(z,x,y-1) + calc(z,x,y+1) + 1; 
}

int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	cin >> k >> n >> m;
	memset(a,'#',sizeof(a));
	
	for (int i=1;i<=k;i++) {
		for (int j=1;j<=n;j++) { 
			cin >> (a[i][j] + 1);
			a[i][j][m+1] = '#';
		}
	} 
	
	int sx,sy;
	cin >> sx >> sy;
	cout << calc(1,sx,sy) << endl;
	
	return 0;
}