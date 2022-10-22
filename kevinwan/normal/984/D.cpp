#include <bits/stdc++.h>
using namespace std;
/*struct nd {
	nd *l, *r;
	int val, pri;
	nd(int v) {
		val = v;
		pri = rand();
	}
};
nd* treap;
nd* find(int num,nd* cur=treap) {
	if (cur == NULL)return NULL;
	if (num == cur->val)return cur;
	if (num > cur->val)return find(num, cur->r);
	if (num < cur->val)return find(num, cur->l);
}
nd* insert(int num, nd* cur = treap) {
	if (num == cur->val)return cur;
	if (num > cur->val)return insert(num, cur->r);
	if (num < cur->val)return insert(num, cur->l);
	if (num > cur->val&&cur->r == NULL) cur->r =new nd(num);
	if (num < cur->val&&cur->l == NULL) cur->l = new nd(num);
}*/
int nums[5000],dp[5000][5000],ans[5000][5000];
int solve(int a, int b) {
	if (dp[a][b] != -1)return dp[a][b];
	if (a == b)return dp[a][b] = nums[a];
	return dp[a][b] = solve(a, b - 1) ^ solve(a + 1, b);
}
void prop(int a, int b) {
	if (ans[a][b] != -1)return;
	ans[a][b] = dp[a][b];
	if (a == b)return;
	prop(a, b - 1);
	prop(a + 1, b);
	ans[a][b] = max(ans[a][b], ans[a][b - 1]);
	ans[a][b] = max(ans[a][b], ans[a + 1][b]);
}
int main() {
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", nums + i);
	memset(dp, -1, sizeof(dp));
	memset(ans,-1,sizeof(ans));
	solve(0, n - 1);
	prop(0, n - 1);
	int q;
	scanf("%d", &q);
	for (i = 0; i < q; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", ans[a-1][b-1]);
	}
	getchar(); getchar();
}