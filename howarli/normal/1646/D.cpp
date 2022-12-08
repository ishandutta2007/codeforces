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


int n,m;
int ans;
vector<int>B[N];
int Bv[N];
void link(int q,int w)
{
	++Bv[q];++Bv[w];
	B[q].push_back(w);
	B[w].push_back(q);
}
struct Val
{
	int v;
	int sum;
}f[N],g[N];

void dfs(int q,int fa)
{
	f[q].v=1;
	f[q].sum=Bv[q];

	g[q].sum=1;
	for(auto w:B[q])if(w!=fa)
	{
		dfs(w,q);
		f[q].v+=g[w].v;	
		f[q].sum+=g[w].sum;

		if(f[w].v>g[w].v || (f[w].v==g[w].v && f[w].sum<g[w].sum))
		{
			g[q].v+=f[w].v;
			g[q].sum+=f[w].sum;
		}else{
			g[q].v+=g[w].v;
			g[q].sum+=g[w].sum;
		}
	}
}

int Ans[N];
void dfs1(int q,int fa,int kd)
{
	if(kd)Ans[q]=Bv[q];
	else Ans[q]=1;

	for(auto w:B[q])if(w!=fa)
	{
		int nw;
		if(kd)nw=0;
		else{
			if(f[w].v>g[w].v || (f[w].v==g[w].v && f[w].sum<g[w].sum))nw=1;
			else nw=0;
		}
		dfs1(w,q,nw);
	}
}

int main()
{
	int q,w,_;
	read(n);
	fo(i,2,n)read(q),read(w),link(q,w);
	if(n==2)
	{
		printf("%d %d\n",2,2);
		printf("1 1\n");
		return 0;
	}
	
	dfs(1,0);

	if(f[1].v<g[1].v || (f[1].v==g[1].v && f[1].sum>g[1].sum))
	{
		dfs1(1,0,0);
		ans=0;
		fo(i,1,n)ans+=Ans[i];
		printf("%d %d\n",g[1].v,ans);

	}else{
		dfs1(1,0,1);
		ans=0;
		fo(i,1,n)ans+=Ans[i];
		printf("%d %d\n",f[1].v,ans);
	}

	fo(i,1,n)printf("%d ",Ans[i]);

	return 0;
}