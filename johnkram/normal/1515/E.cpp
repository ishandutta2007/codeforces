#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L 1048576
#define MAXN 200005
char _buf[L],*S,*T,_buf1[L],*S1=_buf1;
inline char gc()
{
	if(S==T)
	{
		T=(S=_buf)+fread(_buf,1,L,stdin);
		if(S==T)return 0;
	}
	return *S++;
}
inline void pc(char c)
{
	if(S1==_buf1+L)
	{
		fwrite(_buf1,1,L,stdout);
		S1=_buf1;
	}
	*S1++=c;
}
void get(int &x)
{
	static char c;
	for(c=gc();(c<'0'||c>'9')&&c!='-';c=gc());
	bool b=0;
	if(c=='-')
	{
		b=1;
		c=gc();
	}
	for(x=c^'0',c=gc();c>='0'&&c<='9';c=gc())x=(x<<3)+(x<<1)+(c^'0');
	if(b)x=-x;
}
void out(int x)
{
	if(x>9)out(x/10);
	pc(x%10^'0');
}
inline int A(int x)
{
	return x<0?-x:x;
}
int n,P,i,j,k,l,f3[405][405],f2[405][405],f1[405][405],f0[405][405],f[405],g[405],I[405],t[405],a[405][405],ans;
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
void work(int *f)
{
	memset(t,0,sizeof(t));
	int i,j;
	for(i=0;i<=n;i++)for(j=0;j<=n;j++)t[j]=(t[j]+(ll)a[i][j]*f[i])%P;
}
int main()
{
	get(n);
	get(P);
	for(i=f[0]=1;i<=n;i++)f[i]=(ll)f[i-1]*i%P;
	for(i=0;i<=n;i++)g[i]=Pow(f[i],P-2);
	for(i=1;i<=n;i++)I[i]=(ll)f[i-1]*g[i]%P;
	for(i=0,t[0]=1;i<=n;i++)
	{
		for(j=i+1;j;j--)t[j]=(t[j-1]+(ll)(P-i)*t[j])%P;
		t[0]=(ll)(P-i)*t[0]%P;
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n+1;j++)a[i][j]=t[j];
		for(j=n;~j;j--)a[i][j]=(a[i][j]+(ll)a[i][j+1]*i)%P;
		for(j=0;j<=n;j++)
		{
			a[i][j]=(ll)a[i][j+1]*g[i]%P*g[n-i]%P;
			if(n-i&1)a[i][j]=(P-a[i][j])%P;
		}
	}
	for(i=0;i<=n;i++)
	{
		f2[0][i]=f2[1][i]=f1[0][i]=1;
		f3[0][i]=i;
		f3[1][i]=i<<1;
	}
	for(i=2;i<n;i++)
	{
		for(k=0;k<i;k++)for(j=0;j<=n;j++)f2[i][j]=(f2[i][j]+(ll)f2[k][j]*f2[i-1-k][j])%P;
		work(f2[i]);
		for(k=n;k;k--)t[k]=(ll)t[k-1]*I[k]%P;
		t[0]=0;
		for(j=0;j<=n;j++)for(f2[i][j]=0,k=n;~k;k--)f2[i][j]=((ll)f2[i][j]*j+t[k])%P;
		for(k=n;k;k--)t[k]=(ll)t[k-1]*I[k]%P;
		t[0]=0;
		for(j=0;j<=n;j++)
		{
			for(f3[i][j]=0,k=n;~k;k--)f3[i][j]=((ll)f3[i][j]*j+t[k])%P;
			f3[i][j]=(ll)f3[i][j]*(i+1)%P;
		}
	}
	for(i=1;i<n;i++)
	{
		for(k=0;k<i;k++)for(j=0;j<=n;j++)f1[i][j]=(f1[i][j]+(ll)f1[k][j]*f3[i-1-k][j])%P;
		for(j=0;j<=n;j++)f1[i][j]=(ll)f1[i][j]*I[i]%P;
	}
	for(k=0;k<i;k++)for(j=0;j<=n;j++)f0[i][j]=(f0[i][j]+(ll)f1[k][j]*f1[i-1-k][j])%P;
	work(f0[i]);
	for(k=i;k;k--)t[k]=(ll)t[k-1]*I[k]%P;
	for(i=1;i<=n;i++)ans=(ans+(ll)t[i]*f[i])%P;
	cout<<ans<<endl;
	fwrite(_buf1,1,S1-_buf1,stdout);
	return 0;
}