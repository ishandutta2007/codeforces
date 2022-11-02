#include <stdio.h>
#define MAXN 1055

int n;
char s[MAXN];
int w[MAXN],val[MAXN];

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

inline void solve() {
	int i,j,h=0,minh,t,sol=0;
/*	t=n;
	n=1;
	w[0]=1;
	for(i=0;i<t-1;i++) {
		if(s[i]=='=') {
			w[n-1]++;
		} else {
			++n;
			s[n]=s[i];
			w[n]=1;
		}
	}
	for(i=0;i<n-1;i++)
		printf("%c ",s[i]);puts("");*/
	for(i=0;i<n;i++)
		val[i]=1;
//	for(i=0;i<n;i++)
//		if((i==0||s[i-1]=='L')&&(i==n-1||s[i]=='R')) val[i]=1;
	for(t=0;t<n;t++) {
		for(i=0;i<n;i++) {
			if(i&&s[i-1]=='R') val[i]=max(val[i-1]+1,val[i]);
			if(i<n-1&&s[i]=='L') val[i]=max(val[i+1]+1,val[i]);
			if(i&&s[i-1]=='=') val[i]=max(val[i-1],val[i]);
			if(i<n-1&&s[i]=='=') val[i]=max(val[i+1],val[i]);
		}
	}
	bool flag=0;
	for(i=0;i<n;i++) {
		printf("%d%c",val[i],i<n-1?' ':'\n');
	}
}

int main(void) {
	int i;
	while(scanf("%d",&n)==1) {
		scanf("%d",&n);
		scanf("%s",s);
		solve();
	}
}