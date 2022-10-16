#include<bits/stdc++.h>
#define MAX   100100
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int a[MAX],b[MAX];
int main(void) {
	int n;
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) scanf("%d",&b[i]);
	long long res=0LL;
	REP(i,n) if (a[i]*2<b[i] || b[i]<2) res--;
	else {
		int x=b[i]/2;
		int y=b[i]/2+b[i]%2;
		assert(x<=a[i] && y<=a[i] && x>0 && y>0);
		res+=1LL*x*y;
	}
	cout << res;
	return 0;
}