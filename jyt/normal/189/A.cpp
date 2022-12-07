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
#define N 4005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,a,b,c,f[N];
int main()
{
	scanf("%d%d%d%d",&n,&a,&b,&c);
	for(int i=1;i<=n;i++)
	{
		f[i]=-1e9;
		if(i>=a) f[i]=max(f[i],f[i-a]+1);
		if(i>=b) f[i]=max(f[i],f[i-b]+1);
		if(i>=c) f[i]=max(f[i],f[i-c]+1);
	}
	printf("%d\n",f[n]);
	return 0;
}