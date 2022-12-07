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

int n,m,ans;
int f[N];
int c[N],zx[N],a1[N];
int g[33][N];
int dep[N];
int Ans[N];
bool z1[N];
priority_queue<int>B[N];
priority_queue<int>d;

void dfs(int q,int w=1)
{
	if(dep[q])
	{
		if(z1[q])dep[0]+=w-dep[q];
		return;
	}
	dep[q]=w;
	z1[q]=1;
	dfs(g[0][q],w+1);
	z1[q]=0;
}
int main()
{
	int q,w,mx=0;
	read(n);
	fo(i,1,n)read(g[0][i]);
	fo(i,1,n)
	{
		read(c[i]),mx=max(mx,c[i]);
		if(c[i]<=n)zx[c[i]]=i;
	}

	fo(i,1,n)a1[i]=INF;
	fo(i,1,n)a1[g[0][i]]=min(a1[g[0][i]],i);
	q=0;
	fo(i,1,n)if(a1[i]==INF)++q;

	m=(mx-n)/(q);

	// printf("m: %d\n",m);

	fo(i,1,n)f[i]=i;
	q=1;
	fo(I,1,30)
	{
		fo(i,1,n)
		{
			g[I][i]=g[I-1][g[I-1][i]];
		}

		if(m&q)
		{
			fo(i,1,n)f[i]=g[I-1][f[i]];
		}
		q<<=1;
	}

	fo(i,1,n)B[f[i]].push(-i);
	fo(i,1,n)
	{
		if(zx[i])
		{
			w=zx[i];
			for(;1;)
			{
				q=-B[w].top();B[w].pop();
				if(!Ans[q])break;
			}
			Ans[q]=i;
			for(;!B[w].empty();)
			{
				q=B[w].top();B[w].pop();
				d.push(q);
			}
		}else{
			q=-d.top();
			d.pop();
			Ans[q]=i;
		}
	}
	fo(i,1,n)printf("%d ",Ans[i]);
	puts("");
	return 0;
}