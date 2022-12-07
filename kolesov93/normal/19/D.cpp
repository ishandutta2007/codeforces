#include <stdio.h>
#include <algorithm>
#include <queue>
#include <math.h>
#include <map>
#include <deque>
#include <string>
#include <string.h>
#define N 211111
#define INF (int) 2e9
struct cell {
	int l,r,max;
} a[N+N+N];
struct point {
	int x,y;
	
	bool operator <(const point& A) const {
		return x < A.x || (x == A.x && y < A.y);
	}
	
	bool operator ==(const point& A) const {
		return x == A.x && y == A.y;
	}
} c[N];
struct ev {
	int type;
	point p;
} b[N];
int n,m,kf;
char w[11];

void build(int x, int l, int r) {
	a[x].l = l; a[x].r = r; a[x].max = -INF;
	if (l<r) {
		build(x<<1,l,(l+r)>>1);
		build(1+(x<<1),1+((l+r)>>1),r);		
	}
}

void modify(int x, int pos, int val) {
	if (pos < a[x].l || pos > a[x].r) return;
	if (a[x].l == a[x].r) {
		a[x].max = val;
		return;
	}
	modify(x<<1,pos,val);
	modify(1+(x<<1),pos,val);
	a[x].max = std::max(a[x<<1].max,a[1+(x<<1)].max);
}

bool match(point candidate, point lim) {
	return lim.x < candidate.x && lim.y < candidate.y;
}

point find(int x, point lim) {
	if (c[a[x].r].x <= lim.x || !(a[x].max > lim.y)) return (point) {-INF,-INF};
	if (a[x].r == a[x].l) {
		if (match(c[a[x].r],lim)) return c[a[x].l];
		else return (point) {-INF,-INF};
	}
	point ans = find(x<<1,lim);
	if (lim < ans) return ans;
	return find(1+(x<<1),lim);	
}

int main(void) {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
			scanf("%s %d %d",w,&b[i].p.x,&b[i].p.y);
			c[i] = b[i].p;
			if (w[0] == 'f') b[i].type = 0;
			if (w[0] == 'a') b[i].type = 1;
			if (w[0] == 'r') b[i].type = 2;
	}
	
	std::sort(c,c+n);
	m = std::unique(c,c+n) - c;
	build(1,0,m-1);
		
	for (int i=0;i<n;i++) {
		if (b[i].type == 1) {
			int l=0,r=m-1,mid;
			while (l<r) {
				mid = (l+r)>>1;
				if (c[mid] < b[i].p) l = mid+1;
				else r = mid;
			}
			modify(1,l,c[l].y);
			continue;
		}
		if (b[i].type == 2) {
			int l=0,r=m-1,mid;
			while (l<r) {
				mid = (l+r)>>1;
				if (c[mid] < b[i].p) l = mid+1;
				else r = mid;
			}
			modify(1,l,-INF);
			continue;
		}
		
		if (b[i].p.x >= c[m-1].x) {
			puts("-1");
			continue;
		} 
		
		point ans = find(1,b[i].p);
		if (match(ans,b[i].p)) printf("%d %d\n",ans.x,ans.y);
		else puts("-1");		
	}
		
	return 0;
}