#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e5+51;
struct Node{
	ll op,id,x;
	li numer,denom;
};
Node ass[MAXN],add[MAXN],mul[MAXN],res[MAXN];
ll cnt,ccnt,kk,tots,totd,totm,tmp,x,y,z,rres;
li sum;
li num[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
template <class T>
inline T Min(T x,T y)
{
	return x<y?x:y;
}
inline bool cmp1(Node x,Node y)
{
	return x.x==y.x?x.numer<y.numer:x.x<y.x;
}
inline bool cmp2(Node x,Node y)
{
	return x.x==y.x?x.numer>y.numer:x.x<y.x;
}
inline bool cmp3(Node x,Node y)
{
	return x.op<y.op;
}
inline bool cmp4(Node x,Node y)
{
	return x.numer*y.denom>x.denom*y.numer;
}
int main()
{
	cnt=read(),ccnt=read(),kk=read();
	for(register int i=1;i<=cnt;i++)
	{
		num[i]=read();
	}
	for(register int i=1;i<=ccnt;i++)
	{
		x=read(),y=read(),z=read();
		if(x==1&&z>num[y])
		{
			ass[++tots]=(Node){1,i,y,z,1};
		}
		if(x==2)
		{
			add[++totd]=(Node){2,i,y,z,1};
		}
		if(x==3)
		{
			mul[++totm]=(Node){3,i,y,z,1};
		}
	}
	sort(ass+1,ass+tots+1,cmp1);
	for(register int i=1;i<=tots;i++)
	{
		if(ass[i].x!=ass[i+1].x)
		{
			ass[++tmp]=ass[i];
		}
	}
	tots=tmp;
	for(register int i=1;i<=tots;i++)
	{
		ass[i].numer=ass[i].numer-num[ass[i].x],add[++totd]=ass[i];
	}
	sort(add+1,add+totd+1,cmp2);
	for(register int i=1;i<=totd;i++)
	{
		if(add[i].x!=add[i-1].x)
		{
			sum=num[add[i].x];
		}
		add[i].denom=sum,sum+=add[i].numer;
	}
	for(register int i=1;i<=totm;i++)
	{
		mul[i].numer--;
	}
	for(register int i=1;i<=totd;i++)
	{
		mul[++totm]=add[i];
	}
	sort(mul+1,mul+totm+1,cmp4);
	for(register int i=1;i<=Min(kk,totm);i++)
	{
		res[++rres]=mul[i];
	}
	printf("%d\n",rres);
	sort(res+1,res+rres+1,cmp3);
	for(register int i=1;i<=rres;i++)
	{
		printf("%d ",res[i].id);
	}
}