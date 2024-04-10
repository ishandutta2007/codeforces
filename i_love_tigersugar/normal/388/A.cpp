#include<bits/stdc++.h>
#define MAX   1010
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int a[MAX];
int n;
void init(void) {
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
}
bool ok(int x) {	
	if (x>=n) return (true);
	priority_queue<int> q;
	while (!q.empty()) q.pop();
	FOR(i,1,x) q.push(a[i]);
	FOR(i,x+1,n) {
		int p=q.top();q.pop();
		if (p<=0) return (false);
		q.push(min(a[i],p-1));
	}
	return (true);
}
void process(void) {
	int l=1;
	int r=n;
	while (true) {
		if (r==l) {
			printf("%d",l);
			return;
		}
		if (r-l==1) {
			if (ok(l)) printf("%d",l);
			else printf("%d",r);
			return;
		}
		int m=(l+r)>>1;
		if (ok(m)) r=m; else l=m+1;
	}
}
int main(void) {
	init();
	process();
	return 0;
}