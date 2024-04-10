#include<bits/stdc++.h>
#define MAX   300300
using namespace std;
set<int> cur;
int m,n;
int res[MAX];
stack<int> del;
void init(void) {
	memset(res,0,sizeof res);
	scanf("%d",&n);
	scanf("%d",&m);
	int i;
	for (i=1;i<=n;i=i+1) cur.insert(i);	
}
void process(void) {
	int i,l,r,w,t;
	set<int>::iterator it1,it2;
	for (i=1;i<=m;i=i+1) {
		scanf("%d",&l);
		scanf("%d",&r);
		scanf("%d",&w);
		if (cur.empty()) continue;
		it1=cur.begin();
		if (*it1>r) continue;
		it1=cur.end();it1--;
		if (*it1<l) continue;
		it1=cur.lower_bound(l);
		while (!del.empty()) del.pop();
		for (it2=it1;it2!=cur.end();it2++) {
			if (*it2>r) break;
			if (*it2!=w) {
				del.push(*it2);
				res[*it2]=w;
			}
		}
		while (!del.empty()) {
			t=del.top();del.pop();
			cur.erase(t);
		}
	}
	for (i=1;i<n;i=i+1) printf("%d ",res[i]);
	printf("%d",res[n]);
}
int main(void) {
	init();
	process();
	return 0;
}