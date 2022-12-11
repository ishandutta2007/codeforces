#include <algorithm>
#include <cstdio>
using namespace std;
int l1, r1, l2, r2, ans;
void solve(int l1, int r1, int l2, int r2, int d) {
	if(l1 > r1 || l2 > r2) return ;
	bool tag = 1;
	int x = 1 << d;
	while(tag) {
		tag = 0;
		while(l1 > x) l1 -= x, r1 -= x, tag = 1;
		while(l2 > x) l2 -= x, r2 -= x, tag = 1;
		while(x > max(r1, r2)) d --, x >>= 1, tag = 1;
		if(l1 > l2 || (l1 == l2 && r1 < r2))
			swap(l1, l2), swap(r1, r2);
	}
	ans = max(ans, min(r1, r2) - l2 + 1); 
	if(r1 >= r2) return ;
	solve(l1, r1, l2, x - 1, d);
	solve(l1, r1, 1, r2 - x, d);
//	printf("%d %d %d %d %d!\n", l1, r1, l2, r2, d); 
}
int main() {
	scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
	solve(l1, r1, l2, r2, 30);
	printf("%d\n", ans);
	return 0;
}