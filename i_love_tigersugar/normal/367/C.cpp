#include<cstdio>
#include<iostream>
#include<algorithm>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
int m,n;
int a[MAX];
ll cost(const int &x) {
	if (x%2==1) return (1LL*x*(x-1)/2+1);
	return (1LL*x*(x-1)/2+x/2);
}
void init(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	ll s=0LL;
	FOR(i,1,m) REP(j,2) scanf("%d",&a[i]);
	sort(a+1,a+m+1,greater<int>());
	FORD(i,m,1) if (cost(i)<=1LL*n) {
		FOR(j,1,i) s+=a[j];
		cout<<s;
		return;
	}
}
int main(void) {
	init();
	return 0;
}