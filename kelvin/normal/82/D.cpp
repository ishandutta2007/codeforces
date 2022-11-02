#include <stdio.h>
#define MAXN 1060

const int inf=1000000010;

int n;
int s[MAXN];
int dp[MAXN][MAXN]; // x-th:prev
int prev[MAXN][MAXN];
int h;
int cus[MAXN][2];

inline void relax(int &x,int val) { if(val<x) x=val; }
inline int max(int a,int b) { return a>b?a:b; }

void solve() {
	int i,j,val,opt,optj,p,nj;
	h=(n+1)/2;
	for(i=0;i<=n+1;i++)
		for(j=0;j<n;j++)
			dp[i][j]=inf;
	dp[1][0]=0;
	for(i=1;i<n-1;i+=2) {
		for(j=0;j<i;j++) {
			if(dp[i][j]==inf) continue;
			val=dp[i][j]+max(s[i],s[i+1]);
			if(val<dp[i+2][j]) {
				dp[i+2][j]=val;
				prev[i+2][j]=j;
			}
			val=dp[i][j]+max(s[j],s[i+1]);
			if(val<dp[i+2][i]) {
				dp[i+2][i]=val;
				prev[i+2][i]=j;
			}
			val=dp[i][j]+max(s[i],s[j]);
			if(val<dp[i+2][i+1]) {
				dp[i+2][i+1]=val;
				prev[i+2][i+1]=j;
			}
		}
	}
	opt=inf;
	if(n&1) {
		for(j=0;j<n;j++) {
			val=dp[n][j]+s[j];
			if(val<opt) {
				opt=val;
				optj=j;
			}
		}
		cus[h-1][0]=optj;
		cus[h-1][1]=-1;
		i=n-2;
		j=prev[n][optj];
		p=h-2;
		nj=optj;
		while(i>=1) {
			if(nj==j) {
				cus[p][0]=i;
				cus[p][1]=i+1;
			} else if(nj==i) {
				cus[p][0]=j;
				cus[p][1]=i+1;
			} else {
				cus[p][0]=j;
				cus[p][1]=i;
			}
			nj=j;
			j=prev[i][j];
			i-=2;
			p--;
		}
	} else {
		for(j=0;j<n;j++) {
			val=dp[n-1][j]+max(s[j],s[n-1]);
			if(val<opt) {
				opt=val;
				optj=j;
			}
		}
		cus[h-1][0]=optj;
		cus[h-1][1]=n-1;
		i=n-3;
		j=prev[n-1][optj];
		p=h-2;
		nj=optj;
		while(i>=1) {
			if(nj==j) {
				cus[p][0]=i;
				cus[p][1]=i+1;
			} else if(nj==i) {
				cus[p][0]=j;
				cus[p][1]=i+1;
			} else {
				cus[p][0]=j;
				cus[p][1]=i;
			}
			nj=j;
			j=prev[i][j];
			i-=2;
			p--;
		}
	}
	printf("%d\n",opt);
	for(i=0;i<h;i++) {
		if((n&1)&&i==h-1) printf("%d\n",cus[i][0]+1);
		else printf("%d %d\n",cus[i][0]+1,cus[i][1]+1);
	}
}

int main(void)
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",s+i);
	solve();
}