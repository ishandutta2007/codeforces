#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
int a[100100], ft[100100];

int d[100100];
bool flag[100100];

bool Check(int r) {
	memset(flag, false, sizeof(bool) * (m + 5));
	memset(d, 0, sizeof(int) * (n + 5));
	int cnt = 0, days = 0;
	for(int i=r; i>=1; i--)
		if(a[i] && !flag[a[i]]) {
			flag[d[i] = a[i]] = true;
			cnt ++;
		}
	if(cnt < m) return false;
	for(int i=1; i<=r; i++) {
		if(!d[i]) days ++;
		else {
			if(ft[d[i]] > days) return false;
			days -= ft[d[i]];
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d", a+i);
	for(int i=1; i<=m; i++) scanf("%d", ft+i);
	int l = 1, r = n, mid, ans = -1;
	while(l <= r) {
		mid = l + r >> 1;
		if(Check(mid)) r = (ans = mid) - 1;
		else l = mid + 1;
	}
	printf("%d\n", ans);
	return 0;
}