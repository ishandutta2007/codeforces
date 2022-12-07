#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stack>
using namespace std;
int a[111],need[111],d[111],can[111];
int f[111][111],n;


int main(void) {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	cin >> n;
	for (int i=1;i<=n;i++) { 
		cin >> a[i];
		f[i][i] = 1;
		need[a[i]] = i;
	}
	for (int i=1;i<=n;i++) { 
		cin >> d[i];
		if (i-d[i] > 0) f[i][i-d[i]] = f[i-d[i]][i] = 1;
		if (i+d[i] <= n) f[i][i+d[i]] = f[i+d[i]][i] = 1;
	}

	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				f[i][j] |= f[i][k] & f[k][j];

	for (int i=1;i<=n;i++)
		if (!f[i][need[i]]) {
			puts("NO");
			return 0;
		}
	puts("YES");

	return 0;
}