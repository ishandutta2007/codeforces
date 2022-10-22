#include <bits/stdc++.h>
#define mm(a,b) a=max(a,b);
using namespace std;
typedef long long ll;
int d[100][101],ans[10001],v[100];
int main() {
	int n, m,i,j,l;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		int k,tot=0,t;
		scanf("%d", &k);
		for (j = 0; j < k; j++)scanf("%d", v + j),tot+=v[j];
		for (j = 0; j < k; j++) {
			t = 0;
			mm(d[i][k], tot);
			for (l = j; l < k; l++) {
				t += v[l];
				mm(d[i][k - (l - j + 1)], tot-t);
			}
		}
	}
	for (i = 0; i < n; i++) {
		for (j = m; j >= 0; j--) {
			for (l = 1; l <= min(j,100); l++) {
				mm(ans[j], ans[j - l] + d[i][l]);
			}
		}
	}
	printf("%d",ans[m]);
	getchar(); getchar();
}