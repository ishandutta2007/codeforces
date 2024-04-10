#include<bits/stdc++.h>
using namespace std;

const int N = 300005, MB = 19, inf = 1e9;

int n, q, a[N], nxt[N][MB], lst[MB][MB], d[MB+1];
bool vis[MB];

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	a[n+1] = (1<<MB) - 1;
	for(int i=0;i<MB;i++) {
		for(int j=0;j<MB;j++) {
			lst[i][j] = n+1;
		}
	}
	for(int i=n;i>=1;i--) {
		for(int j=0;j<MB;j++) {
			if((1<<j) & a[i]) {
				nxt[i][j] = i;
				continue;
			}
			nxt[i][j] = n+1;
			for(int k=0;k<MB;k++) {
				if(!((1<<k) & a[i])) continue;
				nxt[i][j] = min(nxt[i][j], lst[j][k]);
			}
		}
		for(int j=0;j<MB;j++) {
			if(!((1<<j) & a[i])) continue;
			for(int k=0;k<MB;k++) {
				if(!((1<<k) & a[i])) continue;
				lst[j][k] = i;
			}
		}
	}
	d[MB] = inf;
	while(q--) {
		int S, E;
		scanf("%d%d",&S,&E);
		for(int i=0;i<MB;i++) {
			d[i] = ((a[S] & (1<<i)) ? S : inf);
			vis[i] = false;
		}
		while(true) {
			int C = MB;
			for(int i=0;i<MB;i++) {
				if(!vis[i] && d[C] > d[i]) C = i;
			}
			if(d[C] >= n+1) break;
			vis[C] = true;
			for(int i=0;i<MB;i++) {
				d[i] = min(d[i], nxt[d[C]][i]);
			}
		}
		bool F = false;
		for(int i=0;i<MB;i++) {
			if(((1<<i) & a[E]) && d[i] <= E) {
				F = true;
				break;
			}
		}
		puts(F ? "Shi" : "Fou");
	}
}