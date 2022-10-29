/***************************************************************
	File name: F.cpp
	Author: huhao
	Create time: Fri 08 May 2020 08:34:09 PM CST
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
#include<bitset>
const int N=4010;
int n,q,m;
int a[N];
std::bitset<N> b[N];
int mul(int a,int b)
{
	int c=0;
	fr(i,0,1) fr(j,0,1) fr(k,0,1) c^=(((a>>(i*2+k))&(b>>(k*2+j)))&1)<<(i*2+j);
//	printf(" %d %d %d\n",a,b,c);
	return c;
}
int ans[N],Ans[N];
int main()
{
	n=read(); q=read();
	fr(i,1,n) a[i]=9;
	while(q--)
	{
		static char opt[5];
		static int p[N],k;
		scanf("%s",opt); k=read();
		fr(i,1,k) p[i]=read();
		if(!strcmp(opt,"mix"))
		{
			scanf("%s",opt);
			int op=*opt=='R'?2:*opt=='Y'?1:*opt=='B'?3:0;
			fr(i,0,1)
			{
				m++; b[m][0]=(op>>i)&1;
				fr(j,1,k) fr(K,0,1) if((a[p[j]]>>(i*2+K))&1) b[m][p[j]*2+K-1]=1;
			}
		}
		else if(!strcmp(opt,"RY")) fr(i,1,k) a[p[i]]=mul(6,a[p[i]]);
		else if(!strcmp(opt,"RB")) fr(i,1,k) a[p[i]]=mul(11,a[p[i]]);
		else fr(i,1,k) a[p[i]]=mul(13,a[p[i]]);
	}
//	fr(i,1,n) printf("%d%c",a[i],i==n?'\n':' ');
//	fr(i,1,m) fr(j,0,n+n) printf("%d%c",int(b[i][j]),j==n+n?'\n':' ');
	int k=1;
	fr(i,1,n+n)
	{
		int p=0;
		fr(j,k,m) if(b[j][i]){ p=j; break; }
		if(!p) continue;
		std::swap(b[k],b[p]); ans[i]=b[k][0]; Ans[k]=i;
		fr(j,k+1,m) if(b[j][i]) b[j]^=b[k];
		fr(j,1,k-1) if(b[j][i]){ b[j]^=b[k]; ans[Ans[j]]^=ans[i]; }
		k++;
	}
//	fr(i,1,m) fr(j,0,n+n) printf("%d%c",int(b[i][j]),j==n+n?'\n':' ');
	fr(j,k,m) if(b[j][0]){ printf("NO\n"); return 0; }
	printf("YES\n");
	fr(i,1,n) putchar(ans[i*2-1]?(ans[i*2]?'B':'Y'):(ans[i*2]?'R':'.'));
	putchar(10);
	return 0;
}