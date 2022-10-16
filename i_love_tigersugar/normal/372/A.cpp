#include<algorithm>
#include<cstdio>
#include<queue>
#include<vector>
#define MAX   500500
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int n;
int a[MAX];
void init(void) {
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1,greater<int>());
}
bool ok(const int &k) {
	if (2*k>n) return (false);
	if (k<1) return (true);
	vector<int> b,s;
	b.clear();
	s.clear();
	FOR(i,1,k) {
		b.push_back(a[i]);
		s.push_back(a[n+1-i]);
	}	
	reverse(s.begin(),s.end());
	REP(i,k) if (b[i]<2*s[i]) return (false);
	return (true);
}
void process(void) {
	int l=0;
	int r=n+7;
	while (true) {
		if (l==r) {
			printf("%d",n-l);
			return;
		}
		if (r-l==1) {
			if (ok(r)) printf("%d",n-r);
			else printf("%d",n-l);
			return;
		}
		int m=(l+r)/2;
		if (ok(m)) l=m;
		else r=m-1;
	}	
}
int main(void) {
	init();
	process();
	return 0;
}