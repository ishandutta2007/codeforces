#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=20000500,INF=1e9+7;
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
int z[N],TI;
int f[N];

LL lak=-1,laans;
LL doit(int x)
{
	if(x==lak)return laans;
	lak=x;
	int ans=0;

	++TI;
	fo(i,1,x)
	{
		int q=0;
		fo(j,1,m)
		{
			q+=i;
			if(z[q]<TI)
			{
				++ans;
				z[q]=TI;
			}
		}
	}

	return laans=ans;
}

int main()
{
	int q,w,_;
	read(n),read(m);

	LL ans=1;
	fo(i,2,n)if(!f[i])
	{
		for(LL q=(LL)i*i;q<=n;q*=i)f[q]=1;

		int cnt=-1;
		for(q=n;q;q/=i)++cnt;

		ans+=doit(cnt);
	}

	cout<<ans<<endl;
	return 0;
}