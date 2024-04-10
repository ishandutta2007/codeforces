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
#define N 500005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,cnt;
char s[N];
std::map<int,int>mp[N];
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
void clear()
{
	for(int i=0;i<=n;i++) mp[i].clear();
	cnt=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d%s",&n,s+1);
		for(int i=1,a,b;i<=n;i++)
		{
			if(s[i]=='D') cnt++;
			b=gcd(cnt,i),a=cnt/b,b=i/b;
			mp[a][b]++;
			printf("%d ",mp[a][b]);
		}
		puts("");
	}
	return 0;
}