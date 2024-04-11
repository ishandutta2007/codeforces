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
#include <map>
#include <memory.h>
using namespace std;
int x[1111],y[1111];
int a[1111],b[1111],ans[1111];

int mabs(int x) {
	if (x < 0) return -x;
	else return x;
}

int ras(int i, int j) {
	return mabs(x[i]-x[j]) + mabs(y[i]-y[j]);
}

int main(void) {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	int n,m;
	
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) cin >> x[i] >> y[i];
        x[0] = x[n]; y[0] = y[n];
        x[n+1] = x[1]; y[n+1] = y[1];

	for (int i=0;i<m;i++) cin >> a[i];

	bool ok = 1;
	for (int i=2;i<=n;i+=2) {
		int need = ras(i-1,i+1);
		bool flag = 0;
		for (int j=0;j<m;j++)
			if (a[j] == need && !b[j]) {
				b[j] = 1;
				ans[i] = j+1; flag = 1;
				break;
			}
		if (!flag) {
			ok = 0;
			break;
		}
	}

	if (ok) {
		puts("YES");
		for (int i=1;i<=n;i++)
			if (ans[i] == 0) cout << "-1 ";
			else cout << ans[i] << " ";
		cout << endl;
		return 0;
	}

	memset(ans,0,sizeof(ans));
	memset(b,0,sizeof(b));

	ok = 1;
	for (int i=1;i<=n;i+=2) {
		int need = ras(i-1,i+1);
		bool flag = 0;
		for (int j=0;j<m;j++)
			if (a[j] == need && !b[j]) {
				b[j] = 1;
				ans[i] = j+1; flag = 1;
				break;
			}
		if (!flag) {
			ok = 0;
			break;
		}
	}

	if (ok) {
		puts("YES");
		for (int i=1;i<=n;i++)
			if (ans[i] == 0) cout << "-1 ";
			else cout << ans[i] << " ";
		cout << endl;
		return 0;
	} else puts("NO");

	return 0;
}