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
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 100005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m1,m2,a,b,fa[N][2],ansn,ans[N][2];
std::queue<int>Q1,Q2;
int find(int x,int y) {return fa[x][y]^x?fa[x][y]=find(fa[x][y],y):x;}
void merge(int x,int y,int z)
{
	int f1=find(x,z),f2=find(y,z);
	if(f1^f2) fa[f1][z]=f2;
}
int main()
{
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=n;i++) fa[i][0]=fa[i][1]=i;
	for(int i=1;i<=m1;i++) scanf("%d%d",&a,&b),merge(a,b,0);
	for(int i=1;i<=m2;i++) scanf("%d%d",&a,&b),merge(a,b,1);
	for(int i=1;i<=n;i++)
		if(find(1,0)!=find(i,0)&&find(1,1)!=find(i,1))
		{
			ans[++ansn][0]=1,ans[ansn][1]=i;
			merge(1,i,0),merge(1,i,1);
		}
	for(int i=1;i<=n;i++)
	{
		if(find(i,0)==find(1,0)&&find(i,1)!=find(1,1)) Q1.push(i);
		if(find(i,0)!=find(1,0)&&find(i,1)==find(1,1)) Q2.push(i);
	}
	for(int top1,top2;;)
	{
		for(;!Q1.empty()&&find(top1=Q1.front(),1)==find(1,1);Q1.pop());
		for(;!Q2.empty()&&find(top2=Q2.front(),0)==find(1,0);Q2.pop());
		if(Q1.empty()||Q2.empty()) break;
		ans[++ansn][0]=top1,ans[ansn][1]=top2;
		merge(top1,top2,0),merge(top1,top2,1);
	}
	printf("%d\n",ansn);
	for(int i=1;i<=ansn;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}