/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2020-02-08 10:36:15
****************************************************************/
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
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
const int N=410,mod=10007;
int n,f[N][N][N],F[N],m,ans;
struct mat
{
	int a[N][N];
	mat(){ memset(a,0,sizeof(a)); }
	int *operator[](int p){ return a[p]; }
	void print()
	{
		fr(i,1,n) fr(j,1,n) if(a[i][j]) printf("%d %d %d\n",i,j,a[i][j]);
	}
}A;
int &Add(int &a,int b){ return a=(a+b)%mod; }
mat operator*(mat a,mat b)
{
	mat c;
	fr(i,1,n) fr(k,i,n) if(a[i][k]) fr(j,k,n) Add(c[i][j],a[i][k]*b[k][j]);
	return c;
}
mat &operator*=(mat &a,mat b){ return a=a*b; }
mat operator^(mat a,int b)
{
	mat r=a;
	for(b--;b;b>>=1,a*=a) if(b&1) r*=a;
	return r;
}
mat &operator^=(mat &a,int b){ return a=a^b; }
char s[N];
int main()
{
	scanf("%s",s+1); n=strlen(s+1);
	f[1][n][0]=1; m=n+read();
	fr(i,1,n) fd(j,n,i) fr(l,0,n)
		if(s[i]==s[j])
		{
			if(i+1>j-1) Add(F[l],f[i][j][l]);
			else Add(f[i+1][j-1][l],f[i][j][l]);
		}
		else
		{
			Add(f[i+1][j][l+1],f[i][j][l]);
			Add(f[i][j-1][l+1],f[i][j][l]);
		}
//	fr(i,0,n) printf("%d%c",F[i],i==n?'\n':' ');
	int _n=n;
	n=n+(n+1)/2+1;
	fr(i,1,_n-1) A[i][i+1]=1;
	fr(i,2,_n) A[i][i]=24;
	fr(i,1,_n) A[i][n-(_n-i+2)/2]=F[i-1];
	fr(i,_n+1,n-1){ A[i][i+1]=1; A[i][i]=25; }
	A[n][n]=26;
//	A.print();
	ans=(A^(m/2+1))[1][n];
	if(m&1)
	{
		ans=ans*26%mod;
		fr(i,1,_n) if((_n-(i-1))%2==0) A[i][n-(_n-i+2)/2]=f[1][n][i-1];
		Add(ans,(A^(m/2+1))[1][n-1]);
	}
	printf("%d\n",ans);
	return 0;
}