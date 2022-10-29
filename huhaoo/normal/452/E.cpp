/***************************************************************
	File name: E.cpp
	Author: huhao
	Create time: Mon 13 Apr 2020 07:53:00 PM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=r*10+c-48;
		c=getchar();
	}
	return r*t;
}
const int N=600010,L=20,mod=1000000007;
int n,r[N],R[N<<1],sa[N],m,h[N],a[N][L+2],d[N],p[N],b[N],cnt[N],_n;
char s[N];
void sufsort()
{
	fr(i,0,m) d[i]=0;
	fr(i,1,n) d[r[i]]++;
	fr(i,1,m) d[i]+=d[i-1];
	fd(i,n,1) sa[d[r[p[i]]]--]=p[i];
}
#define i64 long long
int Max(int x,int y){ return h[x]<h[y]?x:y; } // min
int qmax(int l,int r)
{
	int B=b[r-l+1];
	return Max(a[l][B],a[r-(1<<B)+1][B]);
}
i64 ans[N];
struct info
{
	i64 a,b,c;
	info(i64 A=0,i64 B=0,i64 C=0){ a=A; b=B; c=C; }
};
info solve(int l,int r)
{
//	fprintf(stderr,"%d %d\n",l,r);
	if(l==r) return info(cnt[::sa[l]]==1,cnt[::sa[l]]==2,cnt[::sa[l]]==3);
	int p=qmax(l+1,r);
//	fprintf(stderr,"%d\n",p);
	info x=solve(l,p-1),y=solve(p,r);
//	printf("%d %d %d\n",l,r,h[::sa[p]]);
	ans[h[p]]+=x.a*y.b*y.c+y.a*x.b*y.c+y.a*y.b*x.c+x.a*x.b*y.c+x.a*y.b*x.c+y.a*x.b*x.c;
	return info(x.a+y.a,x.b+y.b,x.c+y.c);
}
int main()
{
	scanf("%s",s+n+1); _n=strlen(s+n+1); n+=strlen(s+n+1); s[++n]='z'+1; fr(i,1,n) cnt[i]++;
	scanf("%s",s+n+1); _n=std::min(_n,(int)strlen(s+n+1)); n+=strlen(s+n+1); s[++n]='z'+2; fr(i,1,n) cnt[i]++;
	scanf("%s",s+n+1); _n=std::min(_n,(int)strlen(s+n+1)); n+=strlen(s+n+1); s[++n]='z'+3; fr(i,1,n) cnt[i]++;
	fr(i,1,n) if(s[i]>'z') cnt[i]=0;
	m='z'+3;
	fr(i,1,n){ r[i]=s[i]; p[i]=i; }
	sufsort();
//	fr(i,1,n) printf("%s\n",s+sa[i]);
	fr(i,0,20)
	{
		int c=0;
		fr(j,n-(1<<i)+1,n) p[++c]=j;
		fr(j,1,n) if(sa[j]>(1<<i)) p[++c]=sa[j]-(1<<i);
//		fr(i,1,n) printf("%d%c",p[i],i==n?'\n':' ');
		sufsort();
//		putchar(10);
//		fr(i,1,n) printf("%s\n",s+sa[i]);
		fr(j,1,n) R[j]=r[j];
		r[sa[1]]=m=1;
		fr(j,2,n)
		{
			if(R[sa[j]]!=R[sa[j-1]]||R[sa[j]+(1<<i)]!=R[sa[j-1]+(1<<i)]) m++;
			r[sa[j]]=m;
		}
		if(m==n) break;
	}
	fr(i,1,n)
	{
		int p=sa[r[i]-1],H=h[r[i-1]]-1; if(H<0) H=0;
		while(s[i+H]==s[p+H]) H++;
		h[r[i]]=H;
	}
//	fr(i,1,n) printf("%s %d\n",s+sa[i],h[i]);
	fr(i,2,n) a[i][0]=i;
	fr(j,1,L) fr(i,2,n-(1<<j)+1) a[i][j]=Max(a[i][j-1],a[i+(1<<(j-1))][j-1]);
	fr(i,2,n) b[i]=b[i>>1]+1;
//	fr(i,1,n) printf("%d%c",cnt[sa[i]],i==n?'\n':' ');
//	fr(i,1,n) printf("%d%c",h[i],i==n?'\n':' ');
//	return 0;
	solve(1,n);
	fd(i,_n,1) ans[i]+=ans[i+1];
	fr(i,1,_n) printf("%lld%c",ans[i]%mod,i==_n?'\n':' ');
	return 0;
}