#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
#define i64 long long
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
#include<array>
#define u64 unsigned long long
#define C std::array<u64,5>
const C g={0,-1ull};
C operator+(C a,C b){ fr(i,0,4) a[i]+=b[i]; return a; }
C operator-(C a,C b){ fr(i,0,4) a[i]-=b[i]; return a; }
C operator*(C a,u64 b){ fr(i,0,4) a[i]*=b; return a; }
C operator*(C a,C b)
{
	C c={0};
	fr(i,0,4) fr(j,0,4) c[i+j>=5?i+j-5:i+j]+=a[i]*b[j];
	return c;
}
const int N=100010;
int p[10]={1,10,100,1000,10000};
int q;
C a[N];
C w[200];
void dft(C *a,int op)
{
	C A[10];
	fr(i,0,9){ A[i]=a[i]; a[i]={0}; }
	fr(i,0,9) fr(j,0,9) a[i]=a[i]+A[j]*w[100+op*i*j];
}
C power(C a,u64 b)
{
	C r={1};
	for(;b;b>>=1,a=a*a) if(b&1) r=r*a;
	return r;
}
int main()
{
	q=read();
	w[0]={1}; fr(i,1,199) w[i]=w[i-1]*g;
	fr(i,1,q) a[read()][0]++;
/*	fr(j,0,4) fr(i,0,9) printf("%I64u%c",a[i][j],i==9?'\n':' ');
	dft(a,1);
	fr(j,0,4) fr(i,0,9) printf("%I64u%c",a[i][j],i==9?'\n':' ');
	dft(a,-1);
	fr(j,0,4) fr(i,0,9) printf("%I64u%c",a[i][j],i==9?'\n':' ');
	return 0;*/
//	fr(i,0,9) fr(j,0,4) printf("%I64u%c",a[i][j],j==4?'\n':' ');
	fr(i,0,4) fr(j,0,99999) if(j/p[i]%10==0)
	{
		C f[10];
		fr(k,0,9) f[k]=a[j+k*p[i]];
		dft(f,1);
		fr(k,0,9) a[j+k*p[i]]=f[k];
	}
//	fr(i,0,9) fr(j,0,4) printf("%I64u%c",a[i][j],j==4?'\n':' ');
	fr(i,0,99999) a[i]=power(a[i],q);
	fr(i,0,4) fr(j,0,99999) if(j/p[i]%10==0)
	{
		C f[10];
		fr(k,0,9) f[k]=a[j+k*p[i]];
		dft(f,-1);
		fr(k,0,9) a[j+k*p[i]]=f[k];
	}
//	fr(i,0,9) fr(j,0,4) printf("%I64d%c",a[i][j],j==4?'\n':' ');
	u64 i5=1;
	fr(i,1,63) if(((5*i5)>>i)&1) i5|=1ull<<i;
	fr(i,0,q-1) printf("%llu\n",(((a[i][0]-a[i][4])*i5*i5*i5*i5*i5)>>5)&((1ull<<58)-1));
	return 0;
}