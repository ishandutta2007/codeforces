/***************************************************************
	File name: E.cpp
	Author: huhao
	Create time: Mon 07 Jun 2021 10:42:58 AM CST
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
#include<vector>
#define Q std::vector<int>
const int N=1<<15|10;
int p[N],n,P[N];
int vis[N];
int m;
int t[N],T[N];
std::vector<int> id[N];
int val[N],op=0;
int cnt;
int query(Q a)
{
	cnt++;
	if(op!=2&&op!=4)
	{
		printf("? %d",a.size()); for(auto i:a) printf(" %d",i); putchar(10); fflush(stdout);
	}
	if(!op) return read();
	int u=0,v=0;
	for(auto i:a){ u++; v+=val[i]; }
//	if(op==1) printf(" => %d (%d/%d)\n",v%u==0,v,u);
	return v%u==0;
}
int main()
{
	n=read(); m=n; int flag=0;
	if(op)
	{
		if(op<=2) fr(i,1,n) val[i]=read();
		else
		{
			fr(i,1,n) val[i]=i;
			srand((unsigned long long)new char);
			std::random_shuffle(val+1,val+n+1);
			if(val[1]>n/2) fr(i,1,n) val[i]=n+1-val[i];
		}
	}
	fr(i,1,n)
	{
		Q a;
		fr(j,1,n) if(i!=j) a.push_back(j);
		if(query(a))
		{
			if(flag) vis[P[i]=p[i]=n]=1;
			else{ vis[P[i]=p[i]=1]=1; flag=1; }
		}
	}
	fr(i,1,n) if(p[i]) t[i]=-1;
//	fr(i,1,n) printf("%d%c",p[i],i==n?'\n':' ');
	fr(o,0,30) if((m>>(o+1))>1)
	{
		int s=(1<<(o+1))-1;
		fr(i,0,s) id[i].clear();
		fr(i,1,n) if(p[i]) id[p[i]&s].push_back(i);
		fr(i,0,s) assert(!id[i].empty());
//		fr(i,0,s) printf("%d%c",id[i][0],i==s?'\n':' ');
		fr(i,1,n) T[i]=0;
//		printf("%d\n",(m>>(o+1))%2==0?1:m==(3<<(o+1))?2:3);
		fr(_t,1,(m>>(o+1))%2==0?1:m==(3<<(o+1))?2:2) fr(j,0,(1<<o)-1)
		{
			if(_t==1)
			{
				if(j) assert(id[0].size()>=2);
				fr(i,1,n) if(t[i]==j)
				{
					if(P[i]){ T[i]=P[i]&s; continue; }
					Q a={i};
					if(!j) fr(k,1,s) a.push_back(id[k][0]);
					else
					{
						a.push_back(id[0][1]);
						fr(k,0,s) if(k!=(1<<o)&&k!=j+(1<<o)) a.push_back(id[k][0]);
					}
					T[i]=t[i];
					if(query(a)) T[i]|=(1<<o);
//					printf("%d <",i);
//					for(auto k:a) printf(" %d",k);;
//					printf(" > %d\n",t[i]!=T[i]);
				}
			}
			int x=0,y=0;
			int u=0,v=0;
			int Cnt=0;
			fr(i,1,n) if(t[i]==j) Cnt++;
			fr(i,1,n) if(!vis[i]&&(i&((1<<o)-1))==j){ if(!u) u=i; v=i; }
			fr(i,1,n) if(t[i]==j)
			{
				if(P[i])
				{
					if(P[i]==u) x=i;
					if(P[i]==v) y=i;
					continue;
				}
				Q a;
				fr(k,1,n) if(t[k]==j&&k!=i) a.push_back(k);
				if(Cnt==2||query(a))
				{
					if(T[i]==(u&s)) x=i;
					else y=i;
				}
				if(x&&y) break;
			}
//			printf(">"); fr(i,1,n) if(t[i]==j) printf(" %d",i);; putchar(10);
//			printf("<"); fr(i,1,n) if(t[i]==j) printf(" %d",T[i]);; putchar(10);
			vis[P[x]=p[x]=u]=1; vis[P[y]=p[y]=v]=1; t[x]=t[y]=-1; id[u&s].push_back(x); id[v&s].push_back(y);
			assert(x&&y);
		}
		if((m>>(o+1))%2==1&&m>(3<<(o+1)))
		{
//			fr(i,1,n) if(p[i]>=(1<<(o+1))+1&&p[i]<=(3<<(o+1))){ vis[p[i]]=0; p[i]=0; }
			m-=(1<<(o+1));
		}
		fr(i,1,n) if(!p[i]) t[i]=T[i]; else t[i]=-1;
//		fr(i,1,n) printf("%d%c",t[i],i==n?'\n':' ');
//		fr(i,1,n) printf("%d%c",T[i],i==n?'\n':' ');
//		fr(i,1,n) printf("%d%c",p[i],i==n?'\n':' ');
	}
	else break;
	if(p[1]>n/2) fr(i,1,n) p[i]=n+1-p[i];
	printf("! "); fr(i,1,n) printf("%d%c",p[i],i==n?'\n':' ');
	if(op) fr(i,1,n) assert(p[i]==val[i]);
//	fprintf(stderr,"%d %d\n",cnt,18*n);
	return 0;
}