#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#include <memory.h>
using namespace std;

int main() {
	//freopen("in","r",stdin);
	//reopen("out","w",stdout);
	
	int n,m,k;
	cin >> n >> m >> k;
	int ans = 0;
	int a[1111];
	for (int i=1;i<=m;i++) a[i] = k + 1;
	for (int i=0;i<n;i++) {
		int x,y;
		cin >> x >> y;
		a[x] = min(a[x],y);
	}
	
	for (int i=1;i<=m;i++) ans += a[i];
	cout << min(ans,k) << endl;
	
	return 0;
}