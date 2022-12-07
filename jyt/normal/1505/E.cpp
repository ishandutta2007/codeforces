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
#define N 9
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,ans;
char s[N][N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int x=1,y=1,p1,p2;x<n||y<m;)
	{
		if(s[x][y]=='*') ans++;
		if(x==n) {y++;continue;}
		if(y==m) {x++;continue;}
		p1=p2=0;
		for(int i=y+1;i<=m&&!p1;i++) if(s[x][i]=='*') p1=i;
		for(int i=x+1;i<=n&&!p2;i++) if(s[i][y]=='*') p2=i;
		if(!p1) {x++;continue;}
		if(!p2) {y++;continue;}
		if(p1-y<=p2-x) y++;
		else x++;
	}
	if(s[n][m]=='*') ans++;
	printf("%d\n",ans);
	return 0;
}