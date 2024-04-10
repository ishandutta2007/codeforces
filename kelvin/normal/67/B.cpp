#include <stdio.h>
#define MAXN 1005

int n,k;
int s[MAXN],lim[MAXN];
int a[MAXN];
bool used[MAXN];

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

inline bool rec(int x) {
	int i;
	used[x]=1;
	for(i=x-k;i>=0;i--)
		s[i]--;
}

inline void solve() {
	int i,j,t;
	for(i=0;i<n;i++)
		used[i]=0;
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(used[j]) continue;
			if(s[j]==0) break;
		}
		a[i]=j;
		rec(j);
/*		for(j=n-1;j>=0;j--) {
			if(used[j]) continue;
			if(s[j]==lim[j]) break;
		}
		if(j<0) {
			for(t=0;t<n;t++)
				if(!used[t]) break;
			a[i]=t;
			rec(t);
		} else {
			for(t=j+k;t<n;t++)
				if(!used[t]) break;
			a[i]=t;
			rec(t);
		}*/
	}
	for(i=0;i<n;i++)
		printf("%d%c",a[i]+1,i<n-1?' ':'\n');
}

int main(void)
{
	int i;
	while(scanf("%d %d",&n,&k)==2) {
		for(i=0;i<n;i++) {
			scanf("%d",s+i);
//			lim[i]=max(n-(i+k),0);
		}
		solve();
	}
}