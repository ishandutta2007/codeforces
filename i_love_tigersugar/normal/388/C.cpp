#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
void process(void) {
	int n;
	int a,b;
	a=0;b=0;
	scanf("%d",&n);
	vector<int> mid;
	REP(zz,n) {
		int t;
		scanf("%d",&t);
		if (t%2==0) {
			REP(i,t) {
				int v;
				scanf("%d",&v);
				if (i<t/2) a+=v;
				else b+=v;
			}			
		}
		else {
			REP(i,t/2) {
				int v;
				scanf("%d",&v);
				a+=v;
			}
			int v;
			scanf("%d",&v);
			mid.push_back(v);
			REP(i,t/2) {
				int v;
				scanf("%d",&v);
				b+=v;
			}
		}
	}
	sort(mid.begin(),mid.end(),greater<int>());
	REP(i,mid.size()) if (i%2==0) a+=mid[i]; else b+=mid[i];
	printf("%d %d",a,b);
}
int main(void) {
	process();
	return 0;
}