#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=200500,INF=1e9+7;
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
int la[N];
bool z[N],z1[N];
int nx[N],zx[N],g[N];
vector<int>B[N];
void link(int q,int w)
{
	B[q].push_back(w);
	B[w].push_back(q);
}
int main()
{
	int q,w,_;
	read(n);
	fo(i,1,n)read(a[i]),la[a[i]]=i;

	fo(i,1,n)if(!z[a[i]])
	{
		z[a[i]]=1;
		nx[i]=la[a[i]];
	}

	int mx=0;
	fo(i,1,n)if(nx[i])
	{
		q=nx[i];
		mx=0;
		fo(j,i+1,q-1)if(nx[mx]<nx[j])mx=j;
		if(nx[mx]<q)mx=0;
		fo(j,i+1,q-1)if(j!=mx)nx[j]=0;
		i=max(i,mx-1);
	}

	mx=0;
	fo(i,1,n)if(nx[i])
	{
		mx=nx[i];
	}else if(mx>i)++ans;



	printf("%d\n",ans);
	
	return 0;
}