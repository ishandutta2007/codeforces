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
#define N 1111
int n,m,k;
struct cell {
	double x,y;
} a[N];
struct cir {
	double r,x,y;
	int num;
	
	bool operator <(const cir& A) const {
		return r > A.r;
	}
} b[N];
int fath[N],f[N];
int wh[N],g[N][N];

double dis(double x1, double y1, double x2, double y2) {
	return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main() {
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++) {
		scanf("%lf%lf",&a[i].x,&a[i].y);
	}
	for (int i=1;i<=m;i++) {
		scanf("%lf%lf%lf",&b[i].r,&b[i].x,&b[i].y);
		b[i].num = i;
	}
	b[0] = (cir) {1e18,0,0,0};
	sort(b+1,b+m+1);
	
	for (int i=1;i<=m;i++) {
		int x = 0;
		for (int j=1;j<=m;j++)
			if (b[j].r > b[i].r)
				if (dis(b[i].x,b[i].y,b[j].x,b[j].y) < b[j].r*b[j].r && b[j].r < b[x].r) x = j;
		fath[i] = x;
		f[i] = f[x] + 1;
		
		g[i][0] = i;
		for (int j=1;j<=m;j++)
			g[i][j] = fath[g[i][j-1]];
	}
	
	
	
	for (int i=1;i<=n;i++) {
		int x = 0;
		for (int j=m;j;j--)
			if (dis(a[i].x,a[i].y,b[j].x,b[j].y) < b[j].r*b[j].r) {
				x = j;
				break;
			}
		wh[i] = x;
	}
	
	while (k--) {
		int A,B;
		scanf("%d%d",&A,&B);
		A = wh[A]; B = wh[B];
		if (f[A] < f[B]) swap(A,B);
		
		int l=0,r=f[A],mid;
		while (l<r) {
			mid = (l+r) >> 1;
			int mid2 = mid - f[A] + f[B];
			if (mid2 < 0) {
				l = mid + 1;
				continue;
			}
			if (g[A][mid] == g[B][mid2]) r = mid;
			else l = mid + 1;
		}
		
		int lca = g[A][l];
		if (lca == B) printf("%d\n",f[A] - f[B]);
		else printf("%d\n",-f[lca]+f[B]-f[lca]+f[A]);
	}
	
	return 0;
}