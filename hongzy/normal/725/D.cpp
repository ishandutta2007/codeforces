#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

#define x first
#define y second
#define ll long long

pair<ll, ll> A[300100];
int n, ans(1e7), pos;

inline ll min(const ll &a, const ll &b) {return a < b ? a : b;}

int main() {
	scanf("%d", &n);
	for(ll i=1; i<=n; i++) scanf("%lld%lld", &A[i].x, &A[i].y);
	sort(A+2, A+n+1, greater<pair<ll,ll> >());
	priority_queue<ll, vector<ll>, greater<ll> > Q;
	pos = 2;
	while(true) {
		while(pos <= n && A[pos].x > A[1].x) Q.push(A[pos].y - A[pos].x + 1), pos ++;
		ans = min(ans, (int)Q.size() + 1);
		if(Q.empty() || A[1].x < Q.top()) break;
		A[1].x -= Q.top(); Q.pop();
	}
	printf("%d\n", ans);
	return 0;
}