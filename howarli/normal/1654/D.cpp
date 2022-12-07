#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=200500,mo=998244353;
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


int n,m;
LL ans;
int a[N];
vector<tuple<int,int,int> >B[N];
int Bv[N];

int Ans[N];
int b[N];
void fj(int q,int *a,int &sz,int kd)
{
	for(int i=2;i*i<=q;++i)if(q%i==0)
	{
		for(;q%i==0;q/=i)
		{
			a[++sz]=kd*i;
		}
	}
	if(q>1)
	{
		a[++sz]=kd*q;
	}
}

void dfs(int q,int fa)
{
	int d[50]={0};
	for(auto [w,x,y]:B[q])if(w!=fa)
	{
		int sz=0;
		fj(x,d,sz,1);
		fj(y,d,sz,-1);
		fo(j,1,sz)
		{
			int e=abs(d[j]);
			b[e]+=(d[j]>0?1:-1);
			Ans[e]=min(Ans[e],b[e]);
		}
		dfs(w,q);
		fo(j,1,sz)b[abs(d[j])]-=(d[j]>0?1:-1);
	}
}
LL ksm(LL q,int w)
{
	LL ans=1;
	for(;w;w>>=1,q=q*q%mo)if(w&1)ans=ans*q%mo;
	return ans;
}

void dfs1(int q,int fa,LL t)
{
	ans=(ans+t)%mo;
	for(auto [w,x,y]:B[q])if(w!=fa)
	{
		dfs1(w,q,t*x%mo*ksm(y,mo-2)%mo);
	}
}
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n);
		fo(i,2,n)
		{
			int x,y;
			read(q),read(w);
			read(y),read(x);
			int t=__gcd(x,y);
			x/=t;
			y/=t;
			B[q].push_back(tie(w,x,y));
			B[w].push_back(tie(q,y,x));
			++Bv[w];
		}
		fo(i,0,n+1)Ans[i]=0,b[i]=0;
		
		dfs(1,0);

		LL t=1;
		fo(i,1,n)if(Ans[i])
		{
			t=t*ksm(i,-Ans[i])%mo;
		}

		ans=0;
		dfs1(1,0,t);

		printf("%lld\n",ans);
		fo(i,1,n)B[i].clear();
	}
	
	return 0;
}