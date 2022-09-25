#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))

int ans=0,b[200],a[200][200],c[200],n,m;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int l,r;
		cin >> l >> r; l--; r--;
		b[r]++; b[l]++;
		a[l][r]=a[r][l]=1;
	}
	ans=0;
	while (true) {
		bool f=false;
		for (int i=0; i<n; i++) c[i]=b[i];
		for (int i=0; i<n; i++) {
			if (b[i]==1) {
				for (int j=0; j<n; j++)
					if (a[i][j]) {
						a[i][j]=a[j][i]=0;
						c[j]--;
						f=true;
					}
			}
		}
		for (int i=0; i<n; i++) b[i]=c[i];
		if (f) ans++;
		else break;
	}
	cout << ans;
	return 0;
}