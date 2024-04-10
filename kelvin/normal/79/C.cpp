#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MAXS 100010
#define MAXP 12
#define MAXN 12
#define MAXNUM 1000010

class Pair {
	public:
		int l,r;
		Pair() {}
		Pair(int li,int ri):l(li),r(ri) {}
		const bool operator<(const Pair &b) const {
			return l>b.l;
		}
};

int n,sl;
char s[MAXS];
char p[MAXN][MAXP];
int pl[MAXN];

int lim[MAXS];
//int fn;
//Pair fbd[MAXNUM];

inline int min(int a,int b) { return a<b?a:b; }

int pre[MAXS],match[MAXS];
inline void prekmp(char *p,int pl) {
	int i,x;
	x=-1; // match to which position
	pre[0]=-1;
	for(i=1;i<pl;i++) {
		while(x>=0&&p[x+1]!=p[i])
			x=pre[x];
		if(p[x+1]==p[i]) x++;
		pre[i]=x;
	}
}

inline void matchkmp(char *s,int sl,char *p,int pl) {
	int i,x;
	x=-1; // match to which position
	for(i=0;i<sl;i++) {
		while(x>=0&&p[x+1]!=s[i])
			x=pre[x];
		if(p[x+1]==s[i]) x++;
		match[i]=x+1;
		if(match[i]==pl) x=pre[x];
	}
}

inline void solve() {
	int i,j,rb,opt=0,pos=0;
	//fn=0;
	for(i=0;i<sl;i++)
		lim[i]=sl;
	for(i=0;i<n;i++) {
		prekmp(p[i],pl[i]);
		matchkmp(s,sl,p[i],pl[i]);
		for(j=0;j<sl;j++)
			if(match[j]==pl[i]) lim[j-pl[i]+1]=min(lim[j-pl[i]+1],j);
//			if(match[j]==pl[i]) fbd[fn++]=Pair(j-pl[i]+1,j);
	}
	j=0;
	rb=sl;
	//std::sort(fbd,fbd+fn);
	for(i=sl-1;i>=0;i--) {
		rb=min(rb,lim[i]);
		if(rb-i>opt) {
			opt=rb-i;
			pos=i;
		}
	}
	printf("%d %d\n",opt,pos);
}

int main(void)
{
	int i;
	scanf("%s",s);
	sl=strlen(s);
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%s",p[i]);
		pl[i]=strlen(p[i]);
	}
	solve();
	return 0;
}