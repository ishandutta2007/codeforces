#include <bits/stdc++.h>
using namespace std;
int f[100001],a[100001];
int main() {
	int w, l,i;
	scanf("%d%d", &w, &l);
	a[0] =f[0]=a[w]= 0x3f3f3f3f;
	for (i = 1; i < w; i++)scanf("%d", a + i);
	int cur = 0,am;
	for (i = 1; i <= w; i++) {
		am = 0;
		cur = max(cur, i - l);
		while (am + f[cur] <= a[i]&&cur<i) {
			am += f[cur];
			f[cur] = 0;
			cur++;
		}
		if (cur < i)f[cur] -= a[i] - am, am = a[i];
		f[i] = am;
	}
	printf("%d", f[w]);
}