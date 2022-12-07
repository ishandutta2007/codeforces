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
#define inf 1e9
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,f[N][2];
char s[N];
void find(int x,int y)
{
	if(!x) return;
	s[x]=y?'B':'R';
	if(f[x][y]==f[x-1][y^1]) find(x-1,y^1);
	else find(x-1,y);
}
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++)
		{
			f[i][0]=f[i][1]=inf;
			if(s[i]!='B') f[i][0]=min(f[i-1][0]+1,f[i-1][1]);
			if(s[i]!='R') f[i][1]=min(f[i-1][0],f[i-1][1]+1);
			// dbg1(i),dbg1(f[i][0]),dbg2(f[i][1]);
		}
		if(f[n][0]<f[n][1]) find(n,0),printf("%s\n",s+1);
		else find(n,1),printf("%s\n",s+1);
	}
	return 0;
}