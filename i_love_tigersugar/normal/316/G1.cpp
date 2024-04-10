#include<cstdio>
#include<cstring>
#include<set>
#define MAX   222
#define NMOD   4
#define BASE   26
using namespace std;
typedef long long ll;
const ll mod[]={1e9+7,1e9+9,1e9+21,1e9+33};
ll p[NMOD][MAX];
int n;
void finit(void) {
	int i,j;
	for (i=0;i<NMOD;i=i+1) {
		p[i][0]=1;
		for (j=1;j<=200;j=j+1) p[i][j]=(p[i][j-1]*BASE)%mod[i];
	}		
}
struct str {
	char c[MAX];
	ll s[NMOD][MAX];
	int l;
	void process(void) {
		int i,j;
		scanf("%s",c);
		l=strlen(c);
		for (i=0;i<NMOD;i=i+1) {
			s[i][0]=0;
			for (j=1;j<=l;j=j+1) s[i][j]=(s[i][j-1]+(c[j-1]*p[i][j-1]))%mod[i];
		}			
	}
};
struct rule {
	str p;
	int l,r;
	void process(void) {
		p.process();
		scanf("%d",&l);
		scanf("%d",&r);
	}	
};
rule rl[17];
str a;
void init(void) {
	int i;
	a.process();
	scanf("%d",&n);
	for (i=1;i<=n;i=i+1) rl[i].process();	
}
bool equal(const str &a1,const str &a2,int n,int f1,int f2) {
	int i;
	ll x,y;
	for (i=0;i<NMOD;i=i+1) {
		x=a1.s[i][f1+n-1]-a1.s[i][f1-1];
		y=a2.s[i][f2+n-1]-a2.s[i][f2-1];
		if (f1<f2) x=x*p[i][f2-f1];
		if (f2<f1) y=y*p[i][f1-f2];
		if ((x-y)%mod[i]!=0) return (false);
	}
	return (true);
}
int exst(const str &b,int l,int r) {
	int i,c;
	if (r-l+1>b.l) return (0);
	c=0;
	for (i=1;i+r-l<=b.l;i=i+1)
		if (equal(a,b,r-l+1,l,i)) c=c+1;
	return (c);
}
bool comp(const rule &r,int a,int b) {
	int t=exst(r.p,a,b);
	return ((r.l<=t) && (t<=r.r));
}
int min(int x,int y) {
	if (x<y) return (x); else return (y);
}
struct sub {
	int l,r;
	sub(){}
	sub(int _l,int _r) {
		l=_l;r=_r;
	}
	bool operator < (const sub &x) const {
		if (a.c[l-1]<a.c[x.l-1]) return (true);
		if (a.c[l-1]>a.c[x.l-1]) return (false);
		int L,M,R;
		L=1;R=min(r-l+1,x.r-x.l+1);
		while (true) {
			if (R==L) {
				M=R;
				break;
			}
			if (R-L==1) {
				if (equal(a,a,R,l,x.l)) M=R;
				else M=L;
				break;
			}
			M=(L+R)/2;
			if (equal(a,a,M,l,x.l)) L=M;
			else R=M-1;
		}
		if (M==r-l+1) return (M<x.r-x.l+1);
		if (M==x.r-x.l+1) return (false);
		return (a.c[l+M-1]<a.c[x.l+M-1]);		
	}	
};
set<sub> sb;
bool suit(const sub &x) {
	int i;
	int l=x.l;
	int r=x.r;
	for (i=1;i<=n;i=i+1)
		if (!comp(rl[i],l,r)) {
		//	printf("Sub %d %d failed at %d\n",l,r,i);
			return (false);
		}
	//printf("Sub %d %d passed\n",l,r);
	if (sb.empty()) return (true);
	return (sb.find(x)==sb.end());
}
void process(void) {
	int i,j;
	int res=0;
	for (i=1;i<=a.l;i=i+1)
		for (j=i;j<=a.l;j=j+1) 
			if (suit(sub(i,j))) {
				res++;
				sb.insert(sub(i,j));
	//			printf("%d %d\n",i,j);
			}
	printf("%d",res);
}
int main(void) {
	finit();
	init();
	process();
	return 0;
}