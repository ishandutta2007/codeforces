#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
const int P=998244353,g=3,MAXN=600005;
struct Int
{
	int a;
	int operator=(int x)
	{
		return a=x;
	}
	Int operator+(Int x)
	{
		Int tmp;
		tmp=a+x.a;
		if(tmp.a>=P)tmp.a-=P;
		return tmp;
	}
	Int operator-(Int x)
	{
		Int tmp;
		tmp=a-x.a;
		if(tmp.a<0)tmp.a+=P;
		return tmp;
	}
	Int operator*(Int x)
	{
		Int tmp;
		tmp=(ll)(a)*x.a%P;
		return tmp;
	}
	Int Pow(int x)
	{
		Int tmp,ans;
		tmp=a;
		ans=1;
		while(x)
		{
			if(x&1)ans=ans*tmp;
			tmp=tmp*tmp;
			x>>=1;
		}
		return ans;
	}
	Int inv()
	{
		return Pow(P-2);
	}
}G,w[2][MAXN],t,a[MAXN],b[MAXN],c[MAXN],d[MAXN],e[MAXN],T;
inline void NTT(Int X[],int k,bool v)
{
    int i,j,l,m,n;
    for(i=j=0;i<k;i++)
	{
        if(i>j)swap(X[i],X[j]);
        for(l=k>>1;(j^=l)<l;l>>=1);
    }
    for(i=2;i<=k;i<<=1)for(m=k/i,n=i>>1,j=0;j<k;j+=i)for(l=0;l<n;l++)
	{
        t=X[j+l+n]*w[v][m*l];
        X[j+l+n]=X[j+l]-t;
        X[j+l]=X[j+l]+t;
    }
    if(v)for(i=0,t=k,t=t.inv();i<k;i++)X[i]=X[i]*t;
}
inline void Pre(int k)
{
    w[0][0]=w[0][k]=w[1][0]=w[1][k]=1;
    G=g;
    G=G.Pow((P-1)/k);
    int i;
    for(i=1;i<k;i++)w[0][i]=w[0][i-1]*G;
    for(i=1;i<k;i++)w[1][i]=w[0][k-i];
}
inline void Mul(Int X[],Int Y[],int k)
{
	k<<=1;
	Pre(k);
	int i;
    for(i=0;i<k>>1;i++)e[i]=Y[i];
    for(;i<k;i++)e[i]=0;
    NTT(X,k,0);
    NTT(e,k,0);
    for(i=0;i<k;i++)X[i]=X[i]*e[i];
    NTT(X,k,1);
    k>>=1;
    for(i=k;i<k<<1;i++)X[i]=0;
}
void Inv(Int X[],Int Y[],int k)
{
	if(k==1)
	{
		Y[0]=X[0].inv();
		return;
	}
	Inv(X,Y,k>>1);
	int i;
	for(i=0;i<k;i++)d[i]=X[i];
	for(k<<=1;i<k;i++)d[i]=0;
	Pre(k);
	NTT(d,k,0);
	NTT(Y,k,0);
	for(i=0;i<k;i++)Y[i]=Y[i]+Y[i]-d[i]*Y[i]*Y[i];
	NTT(Y,k,1);
	for(i=k>>1;i<k;i++)Y[i]=0;
}
void Sqrt(Int X[],Int Y[],int k)
{
	if(k==1)
	{
		Y[0]=1;
		return;
	}
	Sqrt(X,Y,k>>1);
	int i;
	for(i=0;i<k<<1;i++)c[i]=0;
	Inv(Y,c,k);
	Mul(c,X,k);
	for(i=0;i<k;i++)Y[i]=(Y[i]+c[i])*T;
}
int main()
{
	int n,m,L,i;
	scanf("%d%d",&n,&m);
	m++;
	T=2;
	T=T.inv();
    for(L=1;L<m;L<<=1);
    while(n--)
    {
    	scanf("%d",&i);
    	a[i]=P-4;
    }
    a[0]=1;
    Sqrt(a,b,L);
    b[0]=b[0]+(Int){1};
    for(i=0;i<L<<1;i++)c[i]=0;
    Inv(b,c,L);
    for(i=1;i<m;i++)
	{
		c[i]=c[i]+c[i];
		printf("%d\n",c[i].a);
	}
	return 0;
}