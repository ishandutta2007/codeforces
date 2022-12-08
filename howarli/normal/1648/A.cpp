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


int n,m,ans;
vector<int>d[2][N];


LL doit(vector<int> a)
{
	sort(a.begin(),a.end());
	LL ans=0;
	LL sum=0,cnt=0;
	for(auto i:a)
	{
		ans+=i*cnt-sum;
		++cnt;
		sum+=i;
	}
	return ans;
}
int main()
{
	int q,w,_;
	read(n),read(m);
	fo(i,1,n)
	{
		fo(j,1,m)
		{
			read(q);
			d[0][q].push_back(i);
			d[1][q].push_back(j);
		}
	}
	int MX=1e5;
	LL ans=0;
	fo(i,1,MX)
	{
		ans+=doit(d[0][i]);
		ans+=doit(d[1][i]);
	}

	cout<<ans<<endl;
	return 0;
}