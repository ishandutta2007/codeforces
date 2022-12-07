#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=100500,M=50005000;
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


int n,m,ans;
int a[N];
// unordered_map<int,int>Hx;
int Hx[M*2];
int main()
{
	int q,w,_;
	read(n);
	fo(i,1,n)read(a[i]);

	// n=1e5;
	// fo(i,1,n)a[i]=rand();

	m=220+1;

	fo(k,-m,m)
	{
		// Hx.clear();
		fo(i,1,n)
		{
			q=++Hx[M+a[i]-i*k];
			ans=max(ans,q);
		}
		fo(i,1,n)
		{
			Hx[M+a[i]-i*k]=0;
		}
	}

	fo(i,1,n)
	{
		// Hx.clear();
		int mx=0;
		fo(j,i+1,n)
		{
			if((LL)m*(j-i)>N)
			{
				// printf("%d\n",j);
				break;
			}
			if((a[i]-a[j])%(j-i)==0 && abs((a[i]-a[j])/(i-j))>m)
			{
				q=++Hx[M+(a[i]-a[j])/(i-j)];
				mx=max(mx,q);
			}
		}

		fo(j,i+1,n)
		{
			if((LL)m*(j-i)>N)
			{
				break;
			}
			if((a[i]-a[j])%(j-i)==0 && abs((a[i]-a[j])/(i-j))>m)
			{
				Hx[M+(a[i]-a[j])/(i-j)]=0;
			}
		}

		ans=max(ans,mx+1);
	}
	printf("%d\n",n-ans);
	
	return 0;
}