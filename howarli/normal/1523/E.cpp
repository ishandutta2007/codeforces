#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=100500,mo=1e9+7;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return q?n=-n:n;
}
int n,m,K;
LL f[N];
LL jc[N],jcn[N];
LL ksm(LL q,int w)
{
	LL ans=1;
	for(;w;w>>=1,q=q*q%mo)if(w&1)ans=ans*q%mo;
	return ans;
}
LL P(int m,int n){return n>m?0:jc[m]*jcn[m-n]%mo;}
int main()
{
	int q,w,_;
	q=1e5+20;
	jc[0]=1;fo(i,1,q)jc[i]=jc[i-1]*i%mo;
	jcn[q]=ksm(jc[q],mo-2);fod(i,q-1,0)jcn[i]=jcn[i+1]*(i+1LL)%mo;

	read(_);
	while(_--)
	{
		read(n),read(K);
		int mx=n/(K-1)+1;
		f[0]=1;
		f[mx+1]=0;
		fo(i,1,mx)
		{
			f[i]=P(n-(i-1)*(K-1),i);
		}

		LL ans=0;
		fo(i,0,mx)
		{
			ans=(ans+(f[i]*(n-i)-f[i+1])%mo*ksm(P(n,i+1),mo-2)%mo*(i+1LL)%mo)%mo;
		}
		printf("%lld\n",(ans%mo+mo)%mo);
	}



	return 0;
}