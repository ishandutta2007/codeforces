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
#define N 30
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,f[N][N],ans;
char s[N];
int main()
{
	scanf("%d",&n);
	for(int i=1,a,b;i<=n;i++)
	{
		scanf("%s",s+1),m=strlen(s+1),a=s[1]-97,b=s[m]-97;
		for(int j=0;j<26;j++) if(f[j][a]) f[j][b]=max(f[j][b],f[j][a]+m);
		f[a][b]=max(f[a][b],m);
	}
	for(int i=0;i<26;i++) ans=max(ans,f[i][i]);
	printf("%d\n",ans);
	return 0;
}