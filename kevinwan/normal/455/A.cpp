#include <bits/stdc++.h>
using namespace std;
/*struct nd {
	nd *l, *r,*p;
	int val, pri;
	nd(int v) {
		val = v;
		pri = rand();
	}
};
nd* treap;
nd* find(int num,nd* cur=treap) {
	while (cur != NULL) {
		if (num > cur->val)cur = cur->r;
		else if (num < cur->val)cur = cur->l;
		else return cur;
	}
	return NULL;
}
nd* insert(int num, nd* cur = treap) {
	nd* par = NULL;
	while (cur != NULL) {
		if (num > cur->val) { par = cur;  cur=cur->r; }
		else if (num < cur->val) { par = cur; cur = cur->l; }
		else if (num == cur->val)return cur;
	}
}*/
long long num[100001];
long long dp[100001][2];
int main() {
	long long n,i;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		num[x]++;
	}
	memset(dp, 0x80, sizeof(dp));
	dp[0][0] = 0;
	for (i = 1; i <= 100000; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = dp[i - 1][0] + num[i]*i;
	}
	printf("%lld", max(dp[100000][0], dp[100000][1]));
	getchar(); getchar();
}