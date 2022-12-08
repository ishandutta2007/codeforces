#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=1000500,INF=1e9+7;
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
int a[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
LL doit(int s)
{
	LL t1=0,t0=-1e18;
	int i;
	for(i=s;i+m<=n;i+=m)
	{
		tie(t0,t1)=tie(max(t1-a[i],t0+a[i]),max(t1+a[i],t0-a[i]));
	}
	return max(t0-a[i],t1+a[i]);
}
int main()
{
	int q,w,m1,_;
	read(_);
	while(_--)
	{
		read(n),read(m1);
		fo(i,1,n)read(a[i]);
		m=0;
		fo(i,1,m1)
		{
			read(q);
			m=gcd(m,q);
		}

		LL ans=0,ans1=0;

		fo(i,1,m)
		{
			ans+=doit(i);
			a[i]=-a[i];
			ans1+=doit(i);
		}

		cout<<max(ans,ans1)<<endl;
	}
	
	return 0;
}