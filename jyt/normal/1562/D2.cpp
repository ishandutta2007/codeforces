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
#define N 300005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,a,b,Sum[N];
char s[N];
std::vector<int>S[N<<2];
int find(int l,int r)
{
	int v=Sum[l-1]+Sum[r]+n*2;
	int p=std::lower_bound(S[v].begin(),S[v].end(),l)-S[v].begin();
	return S[v][p];
}
void clear()
{
	for(int i=1;i<=n*4;i++) S[i].clear();
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d%d%s",&n,&m,s+1);
		for(int i=1;i<=n;i++)
			Sum[i]=Sum[i-1]+((i&1)^(s[i]=='+')?-1:1),S[Sum[i-1]+Sum[i]+n*2].push_back(i);
		for(;m--;)
		{
			scanf("%d%d",&a,&b);
			if(Sum[b]-Sum[a-1]==0) {puts("0");continue;}
			if(b-a&1) printf("2\n%d %d\n",find(a,b-1),b);
			else printf("1\n%d\n",find(a,b));
		}
	}
	return 0;
}