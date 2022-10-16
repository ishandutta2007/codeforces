#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX   1111
const int INF=(int)1e8;
char c[30];
int e[30];
int f[30][MAX];
int t[30][MAX];
int a[MAX];
int r[30];
char s[MAX];
int m,n;
void init(void) {
	memset(e,-1,sizeof e);
	scanf("%s",s);
	int len=strlen(s);
	int i;
	m=0;
	for (i=0;i<len;i=i+1) {
		if (e[s[i]-'a']<0) {
			m++;
			e[s[i]-'a']=m;
			c[m]=s[i];
			a[m]=1;
		}
		else a[e[s[i]-'a']]++;
	}	
	scanf("%d",&n);
	if (n<m) {
		printf("-1");
		exit(0);
	}
}
int req(const int &p,const int &q) {
	if (p%q==0) return (p/q);
	return (p/q+1);
}
int min(const int &x,const int &y) {
	if (x<y) return (x); else return (y);
}
int max(const int &x,const int &y) {
	if (x>y) return (x); else return (y);
}
void optimize(void) {
	int i,j,k;
	for (i=1;i<=n;i=i+1) {
		f[1][i]=req(a[1],i);
		t[1][i]=i;
	}
	for (i=2;i<=m;i=i+1)
		for (j=i;j<=n;j=j+1) {
			f[i][j]=INF;
			for (k=1;k<=j-i+1;k=k+1)
				if (f[i][j]>max(f[i-1][j-k],req(a[i],k))) {
					f[i][j]=max(f[i-1][j-k],req(a[i],k));
					t[i][j]=k;
				}
		}
}
void trace(void) {
	int i,j;
	printf("%d\n",f[m][n]);
	j=n;
	for (i=m;i>=1;i=i-1) {
		r[i]=t[i][j];
		j=j-t[i][j];
	}
	for (i=1;i<=m;i=i+1)		
		for (j=1;j<=r[i];j=j+1) printf("%c",c[i]);
}
int main(void) {
	init();
	optimize();
	trace();
	return 0;
}