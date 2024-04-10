#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define NX(q) ((q)&(-q))
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=200500,INF=1e9+7,mo=998244353;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return q?n=-n:n;
}
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rand_num(seed);  // 
uniform_int_distribution<int> dist(0, 1000000000);
int RD(int q){return rand_num()%q;}


int n,m,ans,mx;
int a[N],b[N];
LL jc[N],jcn[N];
LL ksm(LL q,int w)
{
	LL ans=1;
	for(;w;w>>=1,q=q*q%mo)if(w&1)ans=ans*q%mo;
	return ans;
}
LL f[N];
void ADD(int q,LL e)
{
	for(;q<=mx;q+=NX(q))f[q]=(f[q]+e)%mo;
}
LL find(LL q)
{
	LL ans=0;
	for(;q;q-=NX(q))ans=(ans+f[q])%mo;
	return ans;
}

int main()
{
	int q,w,_;
	q=2e5;
	jc[0]=1;fo(i,1,q)jc[i]=jc[i-1]*i%mo;
	jcn[q]=ksm(jc[q],mo-2);fod(i,q-1,0)jcn[i]=jcn[i+1]*(i+1)%mo;
	mx=2e5;

	read(n),read(m);
	fo(i,1,n)read(q),++a[q];
	fo(i,1,m)read(b[i]);

	LL tot=1;
	fo(i,1,mx)if(a[i])
	{
		q=a[i];
		tot=tot*jcn[q]%mo;
		ADD(i,q);
	}

	LL ans=0;
	fo(i,1,m)
	{
		q=b[i];
		if(i>n)
		{
			++ans;
			break;
		}
		ans=(ans+jc[n-i]*tot%mo*find(q-1))%mo;

		if(!a[q])break;
		tot=tot*a[q]%mo;
		ADD(q,-1);
		--a[q];
	}

	cout<<(ans+mo)%mo<<endl;
	return 0;
}