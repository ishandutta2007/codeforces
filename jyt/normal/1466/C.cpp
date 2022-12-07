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
int T,n,mark[N],ans;
char s[N];
void clear()
{
	for(int i=1;i<=n;i++) mark[i]=0;
	ans=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%s",s+1),n=strlen(s+1);
		for(int i=2;i<=n;i++)
		{
			if(s[i]==s[i-1]&&!mark[i-1]) mark[i]=1,ans++;
			if(!mark[i]&&s[i]==s[i-2]&&!mark[i-2]) mark[i]=1,ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}