#include<bits/stdc++.h>
using namespace std;

int n, m, c[5005], z[5005], ans[5005];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		z[i] = n-1;
	}
	for(int i=1;i<=m;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		c[A]++;
		z[A] = min(z[A], (A < B ? B - A : n - (A - B)));
	}
	for(int i=1;i<=n;i++) {
		if(c[i] == 0) continue;
		int T = (c[i] - 1) * n + z[i];
		ans[i] = max(ans[i], T);
		for(int j=1;j<n;j++) {
			int I = i + j > n ? i + j - n : i + j;
			ans[I] = max(ans[I], T + n - j);
		}
	}
	for(int i=1;i<=n;i++) {
		printf("%d ", ans[i]);
	}
}