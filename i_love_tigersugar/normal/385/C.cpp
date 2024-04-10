#include<cstdio>
#define MAXN   1000100
#define MAXV   10001000
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
typedef long long ll;
int c[MAXV+7],nd[MAXV+7];
ll res[MAXV+7];
bool notprime[MAXV+7];
int n,q;
void eratosthene(void) {
	REP(i,2) notprime[i]=true;
	FOR(i,1,MAXV) if (!notprime[i])
		for (int j=2*i;j<=MAXV;j=j+i) notprime[j]=true;
}
void init(void) {
	scanf("%d",&n);
	REP(i,n) {
		int t;
		scanf("%d",&t);
		c[t]++;		
	}
	FOR(i,1,MAXV) for (int j=i;j<=MAXV;j=j+i) nd[i]+=c[j];
	FOR(i,1,MAXV) res[i]=res[i-1]+1LL*(!notprime[i])*nd[i];
}
ll answer(int l,int r) {
	if (l>r) return (0);
	if (l>=MAXV) return (0);
	if (r>=MAXV) return (answer(l,MAXV-1));
	return (res[r]-res[l-1]);
}
void process(void) {
	scanf("%d",&q);
	REP(i,q) {
		int l,r;
		scanf("%d",&l);
		scanf("%d",&r);
		printf("%d\n",answer(l,r));
	}		
}
int main(void) {
	eratosthene();
	init();
	process();
	return 0;
}