#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'0');
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
const int N=1<<18,D=998244353;
s64 mi(s64 x,int y=D-2,int p=D)
{
	s64 ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%p;
		x=x*x%p;y>>=1;
	}
	return ans;
}
s64 a[N],b[N],a1[N];
namespace NTT
{
s64 w[N];
int rev[N];
void ntt(s64 a[],int n,int flag)
{
	rep(i,1,n-1)rev[i]=rev[i/2]/2+i%2*n/2;
	rep(i,0,n-1)
	if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int i=1;i<n;i<<=1)
	{
		s64 wn=mi(3,(D-1)/(2*i)*flag+D-1);
		w[0]=1;
		rep(k,1,i-1)w[k]=w[k-1]*wn%D;
		for(int j=0;j<n;j+=i*2)
		{
			s64 *a1=a+j,*a2=a1+i;
			rep(k,0,i-1)
			{
				s64 x=a1[k],y=a2[k]*w[k];
				a1[k]=(x+y)%D;
				a2[k]=(x-y)%D; 
			}
		}
	}
	if(flag==-1)
	{
		s64 niv_n=mi(n);
		rep(i,0,n-1)a[i]=a[i]*niv_n%D;
	}
}
};
using NTT::ntt;
struct Poly
{
vector<s64>a;
void set(int n)
{
	a.resize(n+1);
}
Poly (int n=-1)
{
	set(n);
}
int size()const
{
	return int(a.size())-1;
}
s64& operator [](int i)
{
	return a[i];
}
const s64& operator [](int i)const
{
	return a[i];
}
};
Poly operator *(const Poly &A,const Poly &B)
{
	int n=1;
	while(n<=A.size()+B.size())n*=2;
	rep(i,0,n-1)a[i]=b[i]=0;
	rep(i,0,A.size())a[i]=A[i];
	rep(i,0,B.size())b[i]=B[i];
	ntt(a,n,1);ntt(b,n,1);
	rep(i,0,n-1)a[i]=a[i]*b[i]%D;
	ntt(a,n,-1);
	Poly ans(A.size()+B.size());
	rep(i,0,ans.size())ans[i]=a[i];
	return ans;
}
Poly operator -(Poly A,const Poly &B)
{
	if(A.size()<B.size())A.set(B.size());
	rep(i,0,B.size())(A[i]-=B[i])%=D;
	return A;
}
Poly rev(const Poly &A)
{
	Poly B=A;
	reverse(B.a.begin(),B.a.end());
	return B;
}
Poly niv(const Poly &A,int n0)
{
//	assert(A[0]!=0);
	int n=1;a1[0]=mi(A[0]);
//	if(A.size()==3&&n0==2)
//		int yyx=1;
	while(n<n0)
	{
		n*=2;
		rep(i,0,n*2-1)a[i]=b[i]=0;
		rep(i,0,min(n-1,A.size()))a[i]=A[i];
		rep(i,0,n/2-1)b[i]=a1[i];
		ntt(a,n*2,1);ntt(b,n*2,1);
		rep(i,0,n*2-1)a[i]=a[i]*b[i]%D*b[i]%D;
		ntt(a,n*2,-1);
		rep(i,0,n-1)a1[i]=(((i<n/2)?(2*a1[i]):0)-a[i])%D; 
	}
	Poly ans(n0-1);
	rep(i,0,n0-1)ans[i]=a1[i];
/*	Poly tmp=ans*A;
	rep(i,1,n0-1)
	if(tmp[i]%D)
	{
		printf("%d %d\n",A.size(),n0);
		rep(i,0,A.size())printf("%d ",int(A[i]));puts("");
		rep(i,0,n0-1)printf("%d ",int(ans[i]));
		assert(0);
	}*/
	return ans;
}
pair<Poly,Poly> div(const Poly &A,const Poly &B)
{
	int n=A.size(),m=B.size();
	if(n<m)return {{},A};
	Poly _A=rev(A),_B=niv(rev(B),n-m+1);
	_A.set(n-m);
	Poly Q=_A*_B;
	Q.set(n-m);
	Q=rev(Q);
	Poly R=A-Q*B;
	R.set(m-1);
	return {Q,R};	
}
Poly operator %(const Poly &a,const Poly &b)
{
	return div(a,b).second;
}
Poly ln(const Poly &A,int n)
{
	Poly B=A;
	rep(i,0,B.size()-1)B[i]=B[i+1]*(i+1)%D;
	B.a.pop_back();
	B=B*niv(A,n);
	B.set(n-1);
	per(i,n-1,1)B[i]=B[i-1]*mi(i)%D;
	B[0]=0;
	return B;
}
Poly exp(const Poly &A,int n0)
{
	int n=1;
	Poly B(0);
	B[0]=1;
	while(n<n0)
	{
		n*=2;
		Poly _A(n-1);
		rep(i,0,n-1)_A[i]=(i<=A.size())?A[i]:0;
		++_A[0];
		B=B*(_A-ln(B,n));
		B.set(n-1);
	}
	B.set(n0-1);
	return B;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	Poly C(m);
	rep(i,1,n)
	{
		int x=read();
		if(x<=m)++C[x];
	}
	rep(i,0,m)C[i]=-4*C[i];
	C[0]=1;
	C=ln(C,m+1);
	s64 niv_2=mi(2);
	rep(i,0,m)C[i]=C[i]*niv_2%D;
	C=exp(C,m+1);
	++C[0];
	C=niv(C,m+1);
	rep(i,1,m)printf("%d\n",int((C[i]*2%D+D)%D));
}