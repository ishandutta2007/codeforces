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
int RD(int q){return rand_num()%q;}


int n,m,nw;
int a[N][2];
int cnt[N];
int main()
{
	int q,w,_;
	read(_);
	while(_--)
	{
		read(n),read(m);
		n*=2;
		fo(i,1,n)cnt[i]=1;
		fo(i,1,m)
		{
			read(a[i][0]),read(a[i][1]);
			if(a[i][0]>a[i][1])swap(a[i][0],a[i][1]);
			cnt[a[i][0]]=cnt[a[i][1]]=0;
		}
		fo(i,1,n)cnt[i]+=cnt[i-1];
		int ans=0;

		fo(i,1,m)fo(j,i+1,m)
		{
			if((a[i][0]<a[j][0]&&a[i][1]<a[j][1]&&a[j][0]<a[i][1]) || (a[j][0]<a[i][0]&&a[j][1]<a[i][1]&&a[i][0]<a[j][1]) )++ans;
		}
		fo(i,1,m)
		{
			q=cnt[a[i][1]]-cnt[a[i][0]];
			q=min(q,n-m*2-q);
			ans+=q;
		}
		q=n/2-m;
		ans+=q*(q-1)/2;
		printf("%d\n",ans);
	}	
	return 0;
}