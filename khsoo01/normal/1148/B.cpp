#include<bits/stdc++.h>
using namespace std;

const int N = 200005, inf = 2e9+7;

int n, m, ta, tb, k, a[N], b[N], ans;

int main()
{
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	if(n <= k || m <= k) {
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++) {
		scanf("%d",&b[i]);
	}
	for(int i=0;i<=k;i++) {
		int S = 1, E = m+1;
		while(S<E) {
			int M = (S+E)/2;
			a[i+1] + ta <= b[M] ? E = M : S = M+1;
		}
		if(m+1 <= k - i + S) {
			puts("-1");
			return 0;
		}
		ans = max(ans, b[k-i+S] + tb);
	}
	printf("%d\n", ans);
}