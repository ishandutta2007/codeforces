#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
using namespace std;
int a[MAX],c[MAX];
int n;
void process(void) {
	scanf("%d",&n);
	long long res=0LL;
	FOR(i,1,n) {
		scanf("%d",&a[i]);
		c[i]=c[i-1]+a[i];
		if (a[i]<1) res+=c[i];
	}
	cout << res;
}
int main(void) {
	process();
	return 0;
}