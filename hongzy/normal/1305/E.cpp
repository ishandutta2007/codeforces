#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int n, m, a[N]; 
int main() {
	scanf("%d%d", &n, &m);
	int t = 0;
	for(int i = 1; i <= n; i ++) t += (i - 1) >> 1;
	if(m > t) return puts("-1"), 0;
	t = 0;
	for(int i = 0; i < n; i ++) {
		t += (i - 1) / 2; a[i] = i;
		if(t + (i >> 1) >= m) {
			m -= t;
			a[i + 1] = 2 * i + 1 - 2 * m;
			for(int j = i + 2; j <= n; j ++) a[j] = 1e8 + 2e4 * j;
			break ;
		}
	}
	for(int i = 1; i <= n; i ++)
		printf("%d%c", a[i], " \n"[i == n]);
	return 0;
}