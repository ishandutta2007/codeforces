#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct line { ll m,b; };
bool die(line a, line b, line c) { return (c.b - a.b) / (a.m - c.m) < (b.b - a.b) / (a.m - b.m); }
vector<line> cvx;
ll dp[100001], s[100001],sc[100001];
void insert(line l) {
	while (cvx.size() >= 2 && die(cvx[cvx.size() - 2], cvx[cvx.size() - 1], l))cvx.pop_back();
	cvx.push_back(l);
}
int cur = 0;
ll query(ll x) {
	if (cur >= cvx.size())cur = cvx.size() - 1;
	while (cur < cvx.size() - 1 && cvx[cur + 1].m*x + cvx[cur + 1].b < cvx[cur].m*x + cvx[cur].b)cur++;
	return cvx[cur].m*x + cvx[cur].b;
}
int main() {
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%lld", s + i);
	for (i = 0; i < n; i++)scanf("%lld", sc + i);
	insert({ sc[0],0 });
	for (i = 1; i < n; i++) {
		dp[i] = query(s[i]);
		insert({ sc[i],dp[i] });
	}
	printf("%lld", dp[n - 1]);
	getchar(); getchar();
}