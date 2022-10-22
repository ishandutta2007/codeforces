#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
typedef long long ll;
const int P=998244353,g=3,MAXN=600005;
struct Int
{
	int a;
	Int(int x=0)
	{
		if(x<0)x+=P;
		a=x;
	}
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
}G,t,ans,w[2][MAXN],a[MAXN],b[MAXN],d[MAXN],x;
void NTT(Int X[],int k,bool v)
{
    int i,j,l;
    for(i=j=0;i<k;i++)
	{
        if(i>j)swap(X[i],X[j]);
        for(l=k>>1;(j^=l)<l;l>>=1);
    }
    for(i=2;i<=k;i<<=1)for(j=0;j<k;j+=i)for(l=0;l<i>>1;l++)
	{
        t=X[j+l+(i>>1)]*w[v][(k/i)*l];
        X[j+l+(i>>1)]=X[j+l]-t;
        X[j+l]=X[j+l]+t;
    }
    if(v)for(i=0,t=k,t=t.inv();i<k;i++)X[i]=X[i]*t;
}
void Pre(int k)
{
    w[0][0]=w[0][k]=w[1][0]=w[1][k]=1;
    G=g;
    G=G.Pow((P-1)/k);
    int i;
    for(i=1;i<k;i++)w[0][i]=w[0][i-1]*G;
    for(i=1;i<k;i++)w[1][i]=w[0][k-i];
}
int n,A,B,i;
void work(int l,int r)
{
	if(l==r)
	{
		d[l]=l;
		return;
	}
	int mid=l+r>>1,i,L;
	work(l,mid);
	work(mid+1,r);
	for(L=1;L<=r-l+1;L<<=1);
	fill(a,a+L,0);
	fill(b,b+L,0);
	for(i=l;i<=mid;i++)a[i-l]=d[i];
	for(;i<=r;i++)b[i-mid-1]=d[i];
	a[mid-l+1]=b[r-mid]=1;
	Pre(L);
	NTT(a,L,0);
	NTT(b,L,0);
	for(i=0;i<L;i++)a[i]=a[i]*b[i];
	NTT(a,L,1);
	for(i=l;i<=r;i++)d[i]=a[i-l];
}
int main()
{
	cin>>n>>A>>B;
	n--;
	if(!A||!B||A+B>n+2)
	{
		puts("0");
		return 0;
	}
	A--;
	B--;
	if(!n)
	{
		puts("1");
		return 0;
	}
	work(0,n-1);
	d[n]=1;
	for(i=x=1;i<=A;i++)x=x*Int(i);
	for(i=1;i<=B;i++)x=x*Int(i);
	x=x.inv();
	for(i=1;i<=A+B;i++)x=x*Int(i);
	x=x*d[A+B];
	printf("%d\n",x.a);
	return 0;
}