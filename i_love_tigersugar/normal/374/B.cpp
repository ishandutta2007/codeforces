#include<cstdio>
#include<cstring>
#include<iostream>
#define MAX   100100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
struct ans {
	int best;
	ll cnt;
	ans() {
		best=0;cnt=0;
	}
	ans(int x,ll y) {
		best=x;cnt=y;
	}
	void update(const ans &x) {
		if (best<x.best) {
			*this=x;
			return;
		}
		if (best==x.best) cnt+=x.cnt;
	}
};
char a[MAX];
ans f[MAX];
int n;
void init(void) {
	scanf("%s",a);
	n=strlen(a);
}
void optimize(void) {
	f[0]=ans(0,1LL);
	REP(i,n) {
		f[i+1].update(ans(f[i].best+(a[i]=='9'),f[i].cnt));
		if (i+1<n && (a[i]+a[i+1]==105)) f[i+2].update(ans(f[i].best+1,f[i].cnt));
	}
	if (f[n].best==0) cout<<"1";
	else cout<<f[n].cnt;
}
int main(void) {
	init();
	optimize();
	return 0;
}