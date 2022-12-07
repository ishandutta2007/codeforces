#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=100500,INF=1e9+7;
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
map<LL,int>Hx;

bool ss(LL q)
{
	if(Hx[q])
	{
		--Hx[q];
		return 1;
	}
	if(q==1)return 0;
	LL t=q/2;
	if(ss(t) && ss(q-t))return 1;
	return 0;
}
int main()
{
	int q,w,_;
	read(_);
	int __=_;
	while(_--)
	{
		read(n);
		LL sum=0;
		fo(i,1,n)
		{
			read(q);
			sum+=q;
			++Hx[q];
		}

		bool OK=1;
		OK= ss(sum);
		if(OK)puts("YES");
		else puts("NO");
		Hx.clear();
	}

	
	return 0;
}