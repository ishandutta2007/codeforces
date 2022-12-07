#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<bitset>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 3005
#define M 2500000
#define inf 1e9
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,A[N],B[N],Sum;
std::bitset<N>E[N];
class Flow
{
	int last[N],lev[N],cur[N];
	struct road{int to,f,nex;}e[M];
	bool bfs()
	{
		std::queue<int>q;
		for(int i=S;i<=T;i++) lev[i]=0,cur[i]=last[i];
		for(lev[S]=1,q.push(S);!q.empty();)
		{
			int top=q.front();q.pop();
			if(top==T) return 1;
			for(int k=last[top];k;k=e[k].nex)
				if(!lev[e[k].to]&&e[k].f) lev[e[k].to]=lev[top]+1,q.push(e[k].to);
		}
		return 0;
	}
	int dfs(int x,int Max)
	{
		if(x==T||!Max) return Max;
		int res=0,flow;
		for(int &k=cur[x];k;k=e[k].nex)
			if(lev[e[k].to]==lev[x]+1&&e[k].f)
			{
				flow=dfs(e[k].to,min(Max-res,e[k].f));
				e[k].f-=flow,e[k^1].f+=flow,res+=flow;
				if(res==Max) break;
			}
		return res;
	}
public:
	int S,T,ecnt;
	void adde(int u,int v,int w)
	{
		e[++ecnt]={v,w,last[u]},last[u]=ecnt;
		e[++ecnt]={u,0,last[v]},last[v]=ecnt;
	}
	int Maxflow() {int res=0;while(bfs()) res+=dfs(S,inf);return res;}
}F;
int main()
{
	scanf("%d",&n),F.ecnt=1,F.T=n+1;
	for(int i=1;i<=n;i++) scanf("%d",&A[i]),E[i][i]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&B[i]),Sum+=B[i]>0?B[i]:0;
		B[i]>0?F.adde(0,i,B[i]):F.adde(i,n+1,-B[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j;j--)
			if(A[i]%A[j]==0)
			{
				if(!E[i][j]) F.adde(i,j,inf);
				E[i]|=E[j];
			}
	}
	printf("%d\n",Sum-F.Maxflow());
	return 0;
}