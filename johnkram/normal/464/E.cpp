#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
using namespace std;
#define P 1000000007
#define ll long long
#define L 1048576
#define MAXN 131072
char _buf[L],*S,*T,c;
inline char gc()
{
	if(S==T)
	{
		T=(S=_buf)+fread(_buf,1,L,stdin);
		if(S==T)return 0;
	}
	return *S++;
}
void get(int &x)
{
	for(c=gc();c<'0'||c>'9';c=gc());
	for(x=c^'0',c=gc();c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^'0');
}
struct node
{
	int s,l,r;
}t[MAXN*60];
int n,m,i,j,k,l,N=1,A,B,h[MAXN],ne[MAXN<<1],p[MAXN<<1],w[MAXN<<1],x[MAXN],d[MAXN],f[MAXN];
bool b;
void fix(int &R,int R1,int l,int r,int d)
{
	R=++N;
	if(l+15==r)
	{
		t[R].s=t[R1].s+(1<<d-l);
		if(t[R].s>=1<<16)
		{
			t[R].s-=1<<16;
			b=1;
		}
		else b=0;
		return;
	}
	int mid=l+r>>1;
	if(d<=mid)
	{
		fix(t[R].l,t[R1].l,l,mid,d);
		if(b){if(t[t[R1].r].s+1!=x[r-mid])
		{
			fix(t[R].r,t[R1].r,mid+1,r,mid+1);
			b=0;
		}}
		else t[R].r=t[R1].r;
	}
	else
	{
		t[R].l=t[R1].l;
		fix(t[R].r,t[R1].r,mid+1,r,d);
	}
	t[R].s=((ll)t[t[R].r].s*x[mid-l+1]+t[t[R].l].s)%P;
}
bool ask(int R,int R1,int l,int r)
{
	if(!t[R1].s)return 0;
	if(!t[R].s)return 1;
	if(l+15==r)return t[R].s<t[R1].s;
	int mid=l+r>>1;
	if(t[t[R].r].s==t[t[R1].r].s)return ask(t[R].l,t[R1].l,l,mid);
	return ask(t[R].r,t[R1].r,mid+1,r);
}
struct X
{
	int x,y;
	inline bool operator<(const X b)const
	{
		return !ask(y,b.y,0,MAXN-1);
	}
}tmp;
priority_queue<X> H;
void out(int x)
{
    if(x!=A)out(f[x]);
    printf("%d%c",x,x==B?'\n':' ');
}
int main()
{
	for(i=x[0]=1;i<MAXN;i++)
	{
		x[i]=x[i-1]<<1;
		if(x[i]>=P)x[i]-=P;
	}
	get(n);
	get(i);
	while(i--)
	{
		get(j);
		get(k);
		get(l);
		p[++m]=k;
		ne[m]=h[j];
		w[m]=l;
		h[j]=m;
		p[++m]=j;
		ne[m]=h[k];
		w[m]=l;
		h[k]=m;
	}
	get(A);
	get(B);
	tmp.x=A;
	tmp.y=d[A]=N;
	H.push(tmp);
	while(!H.empty())
	{
		tmp=H.top();
		H.pop();
		if(tmp.y!=d[tmp.x])continue;
		for(j=h[i=tmp.x];j;j=ne[j])
		{
			fix(k,d[i],0,MAXN-1,w[j]);
			if(!d[p[j]]||ask(k,d[p[j]],0,MAXN-1))
			{
				f[tmp.x=p[j]]=i;
				tmp.y=d[p[j]]=k;
				H.push(tmp);
			}
		}
	}
	if(d[B])
	{
	    printf("%d\n",t[d[B]].s);
	    for(i=B,j=1;i!=A;i=f[i],j++);
	    printf("%d\n",j);
	    out(B);
	}
	else puts("-1");
	return 0;
}