/***************************************************************
	File name: H.cpp
	Author: huhao
	Create time: Tue 15 Jun 2021 08:43:39 AM CST
***************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<assert.h>
#define i64 long long
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
#include<random>
const int N=15010;
int n,m;
int q[N];
int lst;
int type=0,val[N],Cnt;
int query(int a,int b)
{
	Cnt++;
	if(type==0){ printf("? %d %d\n",a,b); fflush(stdout); }
	if(type==0) return lst=read();
	val[a]+=b; if(val[a]==n*m) val[a]=0; else if(val[a]==-1) val[a]=n*m-1;
	static int vis[N];
	fr(i,0,n*m-1) vis[i]=0;
	fr(i,0,n-1) fr(j,0,m-1) vis[(val[i]+j)%(n*m)]=1;
	int ans=0; fr(i,0,n*m-1) ans+=!vis[i];
	if(type==1) printf("? %d %d  =>  %d\n",a,b,ans);
	return lst=ans;
}
int Query(int a,int b)
{
	int Lst=lst; int ans=query(a,b);
//	printf("%d %d => %d\n",a,b,ans-Lst);
	return ans-Lst;
}
int main()
{
	std::mt19937 Rand(123654789);
	n=read(); m=read();
	if(type!=0) fr(i,1,n-1) val[i]=read();//Rand()%(n*m);
	fr(i,1,1000) query(Rand()%n,Rand()%2?-1:1);
	query(0,1); lst=query(0,-1);
	static int p[N];
	fr(i,0,n-1) p[i]=i;
	std::shuffle(p,p+n,Rand);
	fr(I,0,n-1)
	{
		int i=p[I];
		if(Query(i,1)==-1)
		{
			while(Query(i,-1)==1) ;
			Query(i,1);
		}
		else
		{
			while(Query(i,1)!=-1) ;
			Query(i,-1);
		}
	}
	fprintf(stderr,"%d\n",Cnt);
//	fr(i,0,n-1) printf("%d%c",val[i],i==n-1?'\n':' ');
	int v=lst;
	fr(i,0,n-1) q[i]=-1;
	fr(i,0,n*m-1) if(lst==v)
	{
		query(0,1);
		fr(j,0,n-1) if(q[j]==-1)
		{
			if(Query(j,1)!=-1) q[j]=i;
			query(j,-1);
		}
	}
	else query(0,1);
	printf("! ");
	fr(i,1,n-1) printf("%d%c",q[i],i==n-1?'\n':' ');
	fprintf(stderr,"%d\n",Cnt);
	if(type!=0) fr(i,1,n-1) assert(q[i]==(val[i]-val[0]+n*m)%(n*m));
	return 0;
}