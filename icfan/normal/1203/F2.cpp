
#include<bits/stdc++.h>
using namespace std;
int n, r, a, b, lp, lq;
struct node {
	int a, b;
} p[111], q[111];
int dp[60007];
bool cmp1(node x, node y) {
	if(x.a == y.a)
		return x.b > y.b;
	return x.a < y.a;
}
bool cmp2(node x, node y) {
	return x.a+x.b > y.a+y.b;
}
int main() {
	scanf("%d%d", &n, &r);
	for(int i = 0; i < n; i++) {
		scanf("%d%d", &a, &b);
		if(b >= 0)
			p[lp].a = a, p[lp].b = b, lp++;
		else
			q[lq].a = a, q[lq].b = b, lq++;
	}
	int cnt = 0;
	sort(p, p+lp, cmp1);
	for(int i = 0; i < lp; i++)
		if(r >= p[i].a)
			r += p[i].b, cnt++;
	sort(q, q+lq, cmp2);
	dp[r] = cnt;
	for(int i = 0; i < lq; i++)
		for(int j = max(q[i].a, -q[i].b); j <= r; j++)
			dp[j+q[i].b] = max(dp[j+q[i].b], dp[j]+1);
	for(int i = 0; i <= r; i++)
		cnt = max(cnt, dp[i]);
	printf("%d", cnt);
	return 0;
}