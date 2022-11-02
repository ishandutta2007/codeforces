#include <stdio.h>
#define MAXVAL 50000

int pn,pr[MAXVAL/5];
bool np[MAXVAL]={0};

int a,b,k;

inline void gen() {
	int i,j;
	pn=1;
	pr[0]=2;
	for(i=3;i<MAXVAL;i+=2) {
		if(np[i]) continue;
		pr[pn++]=i;
		if(i>250) continue;
		for(j=i*i;j<MAXVAL;j+=i)
			np[j]=1;
	}
}

#define HARDCAP 20000000

int cnt;
int vis[HARDCAP+1]={0},visid=0;
long long lcnt;

void dfs(int m,int pi,int pend,int cur,int sg) {
	int i;
	lcnt+=sg*m/cur;
//	printf("<%lld> ",lcnt);
	for(i=pi;i<pend;i++)
		if(cur<=m/pr[i]) dfs(m,i+1,pend,cur*pr[i],-sg);
}

inline int solve(int m,int pi) {
	int i,j,p;
	if(m<=HARDCAP) { // pi large
		++visid;
		for(i=0;i<pi;i++) {
			p=pr[i];
			for(j=p;j<=m;j+=p)
				vis[j]=visid;
		}
		cnt=0;
		for(i=1;i<=m;i++)
			if(vis[i]<visid) cnt++;
	} else { // pi small
		lcnt=0;
		dfs(m,0,pi,1,1);
		cnt=lcnt;
	}
	return cnt;
}

int main(void)
{
	int i,sol;
	gen();
	scanf("%d %d %d",&a,&b,&k);
	for(i=0;i<pn;i++)
		if(k%pr[i]==0) break;
	if(i<pn&&k!=pr[i]) {
		puts("0");
		return 0;
	}
//	printf("(%d - %d)\n",solve(b/k,i),solve((a-1)/k,i));
	sol=solve(b/k,i)-solve((a-1)/k,i);
	printf("%d\n",sol);
}