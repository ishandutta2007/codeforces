#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}

const int maxn=1e5+20;

char s[maxn];
int n,m,a[maxn],b[maxn],pa[maxn],pb[maxn];
char p[maxn];

void init()
{
	cin>>(s+1);
	cin>>(p+1);
	n=strlen(s+1);
	m=strlen(p+1);
	REP(i,1,n)a[i]=a[i-1]+(s[i]=='B')+(s[i]=='C');
	REP(i,1,m)b[i]=b[i-1]+(p[i]=='B')+(p[i]=='C');
	REP(i,1,n)pa[i]=s[i]=='A'?pa[i-1]+1:0;
	REP(i,1,m)pb[i]=p[i]=='A'?pb[i-1]+1:0;
}

inline void doing()
{
	int q=read();
	REP(i,1,q)
	{
		int l=read(),r=read();
		int l1=read(),r1=read();
		int x=a[r]-a[l-1],y=b[r1]-b[l1-1];
		int Pa=min(pa[r],r-l+1),Pb=min(pb[r1],r1-l1+1);
		if(!x && y)
		{
			if(y%2==0 && Pa-1>=Pb){putchar('1');continue;}
			else {putchar('0');continue;}
		}
		else if(x<=y && (y-x)%2==0 && Pa>=Pb && (x<y || (Pa-Pb)%3==0))putchar('1');
		else putchar('0');
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in","r",stdin); 
    freopen("E.out","w",stdout);
#endif
	init();
	doing();
	return 0;
}