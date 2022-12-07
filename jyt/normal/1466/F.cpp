#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<unordered_map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 500005
#define mod 1000000007
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,fa[N],ans[N];
struct node{int x,y;}A[N];
int find(int x) {return fa[x]^x?fa[x]=find(fa[x]):x;}
int Pow(int x,int y) {int res=1;for(;y;x=(ll)x*x%mod,y>>=1) if(y&1) res=(ll)res*x%mod;return res;}
class LinearBasis
{
	int v[N];
public:
	void insert(int id)
	{
		if(!v[A[id].x])
		{
			v[A[id].x]=id,ans[++ans[0]]=id;
			if(A[id].y) fa[find(A[id].x)]=find(A[id].y);
			return;
		}
		if(find(A[id].x)==A[id].y) return;
		if(find(A[id].x)>A[id].x)
		{
			if(!A[id].y) A[id].y=find(A[id].x);
			else
			{
				A[id].x=find(A[id].x);
				if(A[id].x>A[id].y) std::swap(A[id].x,A[id].y);
				if(A[id].x==A[id].y) return;
				insert(id);
				return;
			}
		}
		if(!A[id].y) return;
		A[id].x=A[id].y,A[id].y=0,insert(id);
	}
}LB;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) fa[i]=i;
	for(int i=1,a;i<=n;i++)
	{
		scanf("%d",&a);
		if(a==1) scanf("%d",&A[i].x);
		else
		{
			scanf("%d%d",&A[i].x,&A[i].y);
			if(A[i].x>A[i].y) std::swap(A[i].x,A[i].y);
		}
		LB.insert(i);
	}
	printf("%d %d\n",Pow(2,ans[0]),ans[0]);
	for(int i=1;i<=ans[0];i++) printf("%d ",ans[i]);
	return 0;
}