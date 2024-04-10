#include <stdio.h>
#define MAXN 1000050

int n;
int s[MAXN],out[MAXN],pos[MAXN];

int ll,lds[MAXN];

inline int solve() {
	int i,l,r,m;
	ll=0;
	for(i=0;i<n;i++) {
		l=-1;
		r=ll;
		while(l<r-1) {
			m=(l+r)>>1;
			if(lds[m]<=s[i]) r=m;
			else l=m;
		}
		if(r==ll) ll++;
		lds[r]=s[i];
	}
	return ll;
}

int main(void)
{
	int i;
	while(scanf("%d",&n)==1) {
		for(i=0;i<n;i++) {
			scanf("%d",s+i);
			s[i]--;
		}
		for(i=0;i<n;i++) {
			scanf("%d",out+i);
			out[i]--;
			pos[out[i]]=i;
		}
		for(i=0;i<n;i++)
			s[i]=pos[s[i]];
		printf("%d\n",solve());
	}
}