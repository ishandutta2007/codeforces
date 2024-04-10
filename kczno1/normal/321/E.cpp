#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=4000+5,ch_top=N*N*3;
char ch[ch_top],*now_r=ch-1;
#define c (*now_r)
#define gc (*++now_r)
int read()
{
	while(gc<'0');
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef c
#undef gc

int qa[2][N],*f=qa[0],*f0=qa[1],g[N],s[N][N],fir[N];

int main()
{
//	freopen("1.in","r",stdin);
	fread(ch,1,ch_top,stdin);
	int n=read(),k=read();
	rep(i,1,n)
	{
		rep(j,1,i)
		{
			if(*(now_r+2)>='0')now_r+=3;
			else now_r+=2;
		}
		rep(j,i+1,n)
		{
			if(*(now_r+2)>='0'){s[j][i]=10;now_r+=3;}
			else {s[j][i]=*(now_r+1)-'0';now_r+=2;}
		}
	}
	rep(j,1,n)
	rep(i,1,j)s[j][i]+=s[j-1][i];
	rep(j,1,n)
	rep(i,1,j)s[j][i]+=s[j][i-1];
	rep(i,1,n)
	{
		int base=f[i]=s[i][i];
		for(int j=i;--j>=0;)s[i][j]=base-s[i][j];
		g[i]=0;
	}
	fir[0]=0;
	rep(i,1,n)fir[i]=n;
	rep(j,2,k)
	{
		swap(f,f0);
		rep(i,1,n)f[i]=f0[g[i]]+s[i][g[i]];
		rep(i,0,n)
		while(fir[i]>i&&f[fir[i]]>f0[i]+s[fir[i]][i])
		{
			g[fir[i]]=i;
			f[fir[i]]=f0[i]+s[fir[i]][i];
			--fir[i];
		}
		for(int i=n;--i;)
		if(fir[i]>fir[i+1])fir[i]=fir[i+1];
	}
	printf("%d\n",f[n]);
}