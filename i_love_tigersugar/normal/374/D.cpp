#include<algorithm>
#include<cstdio>
#define MAX   1000100
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define FORD(i,b,a) for (int i=(b);i>=(a);i=i-1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
const char emp[]="Poor stack!";
int a[MAX];
int b[MAX];
int ndel[MAX];
int t[MAX];
bool del[MAX];
int n,m,p;
void init(void) {
	scanf("%d",&n);
	scanf("%d",&m);
	FOR(i,1,m) scanf("%d",&a[i]);
}
void precount(void) {		
	int t;
	int sz=0;
	int cnt=0;
	REP(i,n) {
		scanf("%d",&t);
		if (t<0) {		
			p++;			
			ndel[p]=upper_bound(a+1,a+m+1,sz)-a-1;
			sz-=ndel[p];			
		}
		else {
			sz++;
			cnt++;
			b[cnt]=t;
		}
	}
	//FOR(i,1,cnt) printf("%d ",b[i]); printf("\n");
}
void update(int u) {
	while (1<=u && u<=n-p) {
		t[u]++;
		u+=u&(-u);
	}
}
int get(int u) {
	int ret=0;
	while (1<=u && u<=n-p) {
		ret+=t[u];
		u=u&(u-1);
	}
	return (ret);
}
int findid(int pos) {
	int l=1;
	int r=n-p;
	while (true) {
		if (l==r) return (r);
		if (r-l==1) {
			if (l-get(l)>=pos) return (l);
			else return (r);
		}
		int m=(l+r)>>1;
		if (m-get(m)>=pos) r=m;
		else l=m+1;
	}
}
void process(void) {
	int cnt=n-p;
	FOR(i,1,p) FORD(j,ndel[i],1) {
		int t=findid(a[j]);
		//printf("delete %d at %d\n",a[j],t);
		del[t]=true;
		update(t);
		cnt--;
	}
	if (cnt==0) printf("%s",emp);
	else FOR(i,1,n-p) if (!del[i]) printf("%d",b[i]);
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	init();
	precount();
	process();
	return 0;
}