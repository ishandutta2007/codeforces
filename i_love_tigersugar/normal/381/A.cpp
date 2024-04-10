#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
int a[MAX],s[2];
int n,l,r;
int main(void) {
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	l=1;r=n;
	REP(i,n) {
		if (a[l]>a[r]) {
			s[i%2]+=a[l];
			l++;
		}
		else {
			s[i%2]+=a[r];
			r--;
		}
	}
	printf("%d %d",s[0],s[1]);
	return 0;
}