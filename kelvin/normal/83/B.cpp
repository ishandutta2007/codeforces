#include <stdio.h>
#include <iostream>
#define MAXN 100500

using namespace std;

const int inf=1000000010;

int n;
long long k,visitsum;
int s[MAXN];

int ql,qr,que[MAXN*3];

inline int min(int a,int b) { return a<b?a:b; }
inline int max(int a,int b) { return a>b?a:b; }

inline long long test(int t) {
	int i;
	long long r=0;
	for(i=0;i<n;i++)
		r+=min(s[i],t);
	return r;
}

inline void solve() {
	int i,x,l=-1,r=inf,m;
	long long vis;
	if(k>visitsum) {
		puts("-1");
		return;
	}
	while(l<r-1) {
		m=(l+r)/2;
		vis=test(m);
		if(vis>=k) r=m;
		else l=m;
	}
	vis=test(l);
	k-=vis;
	ql=qr=0;
	for(i=0;i<n;i++) {
		if(s[i]>l) que[qr++]=i;
		s[i]-=l;
	}
	while(k--) {
		x=que[ql++];
		s[x]--;
		if(s[x]) que[qr++]=x;
	}
	for(i=ql;i<qr;i++)
		printf("%d%c",que[i]+1,i<qr-1?' ':'\n');
}

int main(void)
{
	int i;
	cin >> n >> k;
	visitsum=0;
	for(i=0;i<n;i++) {
		scanf("%d",s+i);
		visitsum+=s[i];
	}
	solve();
}