#include<cstdio>
#include<cstring>
#include<cassert>
#define MAX   103
char s1[MAX];
char s2[MAX];
char vi[MAX];
char ans[MAX];
int m,n,p;
int f[MAX][MAX][MAX];
int t[MAX][MAX][MAX];
int next[MAX][33];
int max(const int &x,const int &y) {
	if (x>y) return (x); else return (y);
}
void init(void) {
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	scanf("%s",vi+1);
	m=strlen(s1+1);
	n=strlen(s2+1);
	p=strlen(vi+1);	
}
void precount(void) {
	int i,j,k,l;
	bool ok;
	for (i=0;i<p;i=i+1)
		for (j='A';j<='Z';j=j+1)
			for (k=i+1;k>=0;k=k-1)
				if (k==0 || vi[k]==j) {
					ok=true;
					for (l=1;l<k;l=l+1)
						if (vi[l]!=vi[l+i-k+1]) {
							ok=false;
							break;
						}
					if (ok) {
						next[i][j-'A']=k;
						break;
					}
				}
	/*for (i=0;i<p;i=i+1)
		for (j='A';j<='Z';j=j+1)
			printf("Next of %d with %c is %d\n",i,j,next[i][j-'A']);*/
}
void optimize(void) {
	memset(t,-1,sizeof t);
	memset(f,-1,sizeof f);
	int i,j,k;
	for (k=0;k<p;k=k+1) {
		for (i=0;i<=m;i=i+1) f[i][0][k]=0;
		for (j=0;j<=n;j=j+1) f[0][j][k]=0;		
	}
	for (i=1;i<=m;i=i+1)
		for (j=1;j<=n;j=j+1) {
			for (k=0;k<p;k=k+1) f[i][j][k]=max(f[i][j-1][k],f[i-1][j][k]);
			if (s1[i]==s2[j]) {
				for (k=0;k<p;k=k+1)
					if (next[k][s1[i]-'A']<p)
						if (f[i][j][next[k][s1[i]-'A']]<f[i-1][j-1][k]+1) {
							f[i][j][next[k][s1[i]-'A']]=f[i-1][j-1][k]+1;
							t[i][j][next[k][s1[i]-'A']]=k;
						}
			}
		}
}
void trace(void) {
	int i,j,k;
	int res=-1;
	for (i=0;i<p;i=i+1)
		if (res<f[m][n][i]) {
			res=f[m][n][i];
			k=i;
		}
	if (res<=0) {
		printf("0");
		return;
	}
	i=m;j=n;
	int cnt=0;
	while (f[i][j][k]>0) {
		if (f[i][j-1][k]==f[i][j][k]) {
			j--;
			continue;
		}
		if (f[i-1][j][k]==f[i][j][k]) {
			i--;
			continue;
		}
		if (s1[i]==s2[j] && t[i][j][k]>=0) {
			cnt++;
			ans[res-cnt+1]=s1[i];
			k=t[i][j][k];
			i--;
			j--;			
			continue;
		}
		assert(false);
	}
	assert(strlen(ans+1)==res);
	printf("%s",ans+1);
}
int main(void) {
#ifndef ONLINE_JUDGE
	freopen("tmp.txt","r",stdin);
#endif
	init();
	precount();
	optimize();
	trace();
	return 0;
}