// Hydro submission #63571c0b63ef0fee598971a7@1666653195517
#include <cstdio>
#include <iostream>
#include <algorithm>
#define LL long long
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0; int f = 0; char ch = getchar();
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
	for(; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
	if(f) x = ~x + 1;
}
const int N = 4e5 + 10;
int n, m, a[N], b[N], ans;
int sa[N], sb[N];
int a1, b1, pa, pb;
LL movex(int x, int y, LL now, int tp) {
	++x;
	now += min(sa[x], y);
	now -= min(m - sa[x], m - y);
	if(tp)  {
		if(pa == x && pb > y) ++now;//, puts("+");
	}
	return now;
}
LL movey(int x, int y, LL now, int tp) {
	++y;
	now += min(sb[y], x);
	now -= min(n - sb[y], n - x);
	if(tp)  {
		if(pb == y && pa > x) ++now;//, puts("-");
	}
	return now;
}
bool check(int x) {
	if(a1 + b1 <= x) return true;
	sa[0] = m;
	for(int i = 1; i <= n; ++i) {
		int p = sa[i - 1];
		while(a[i] + b[p] > x && p) --p;
		sa[i] = p;
	}
	sb[0] = n;
	for(int i = 1; i <= m; ++i) {
		int p = sb[i - 1];
		while(a[p] + b[i] > x && p) --p;
		sb[i] = p;
	}
//	printf("solve %d\n",x);
//	for(int i = 1; i <= n; ++i) printf("%d ",sa[i]); puts("");
//	for(int i = 1; i <= m; ++i) printf("%d ",sb[i]); puts("");
	int nx = 0, ny = 0;
	LL s1 = 0, s2 = -1;
	for(int i = 1; i <= n; ++i) s1 += m - sa[i], s2 += m - sa[i];
//	printf("%d %d\n",s1,s2);
	LL p1 = s1, p2 = s2;
	while(nx < n) {
		s1 = movex(nx, ny, s1, 0), ++nx;
		while(movey(nx, ny, s1, 0) > s1 && ny < m) s1 = movey(nx, ny, s1, 0), ++ny;
//		printf("best %d %d %d\n",nx,ny,s1);
		p1 = max(p1, s1);
	}
	nx = 0, ny = 0; 
//	puts("\n");
	while(nx < n) {
		s2 = movex(nx, ny, s2, 1), ++nx;
		while(movey(nx, ny, s2, 1) > s2 && ny < m) s2 = movey(nx, ny, s2, 1), ++ny;
//		printf("best %d %d %d\n",nx,ny,s2);
		p2 = max(p2, s2);
	}
//	printf("end %d %d\n",p1,p2);
	if(p1 == p2 + 1) return false;
	return true;
}
int main() {
	read(n), read(m);
	for(int i = 1; i <= n; ++i) read(a[i]); a1 = a[1];
	for(int i = 1; i <= m; ++i) read(b[i]); b1 = b[1];
	sort(a + 1, a + n + 1), sort(b + 1, b + m + 1);
	pa = lower_bound(a + 1, a + n + 1, a1) - a, pb = lower_bound(b + 1, b + m + 1, b1) - b;
	for(int l = 0, r = a1 + b1, mid; l <= r; ) {
		mid = l + r >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%d\n",ans);
}