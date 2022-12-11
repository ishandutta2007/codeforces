#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define x first
#define y second

pair<int, pair<int, int> > A[300010];
int n, k;
int ans(-1), ansl(1e9+1), ansr(-1e9-1);
int res[300010], cnt;

int main() {
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; i++)
		scanf("%d%d", &A[i].x, &A[i].y.x), A[i].y.y = i;
	sort(A+1, A+n+1);
	priority_queue<int, vector<int>, greater<int> > Q;
	for(int i=1; i<=n; i++) {
		Q.push(A[i].y.x);
		if(Q.size() < k) continue;
		while(Q.size() > k) Q.pop();
		int nowl = A[i].x, nowr = Q.top();
		if(nowr - nowl + 1 > ans)
			ans = (ansr=nowr) - (ansl=nowl) + 1;
	}
	printf("%d\n", ~ans ? ans : 0);
	for(int i=1; i<=n && cnt<k; i++)
		if(A[i].x <= ansl && A[i].y.x >= ansr)
			res[++ cnt] = A[i].y.y;
	sort(res+1, res+cnt+1);
	for(int i=1; i<=cnt; i++) printf("%d ", res[i]);
	printf("\n");
	return 0;
}