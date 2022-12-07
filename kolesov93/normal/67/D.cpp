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
#define N 1111111
int x[N],y[N],n,wh[N];

inline void readi(int& x) {
	x = 0;
	char c = getchar();
	while (c < '0' || c > '9') {
		c = getchar();
	}
	while (!(c < '0' || c > '9')) {
		x = x*10 + c-'0';
		c = getchar();
	}
}

int a[N];

int prev(int x) {
	return x&(x-1);
}
int next(int x) {
	return x+x-prev(x);
}

int b[N];

int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	readi(n);
	for (int i=1;i<=n;i++) readi(x[i]);
	for (int i=1;i<=n;i++) {
		readi(y[i]);
		wh[y[i]] = i;
	}
	
	for (int i=n;i>=1;i--) a[n-i+1] = wh[x[i]];
	
	int res = 0;
	for (int i=1;i<=n;i++) {
		int ans = 0,x=a[i]-1;
		while (x) {
			ans = max(ans,b[x]);
			x = prev(x);
		}
		ans++;
		res = max(res,ans);
		x = a[i];
		while (x <= n) {
			b[x] = max(b[x],ans);
			x = next(x);
		}
	}
	
	cout << res << endl;
	
	return 0;
}