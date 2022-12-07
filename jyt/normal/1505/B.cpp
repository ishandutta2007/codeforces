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
int n,num,ans;
bool Judge(int x,int y)
{
	if(x==1) return y==1;
	int mul=x;
	for(;mul<y;mul*=x);
	return mul==y;
}
int main()
{
	scanf("%d",&n);
	for(;;)
	{
		ans=0;
		for(num=n;num;num/=10) ans+=num%10;
		if(Judge(ans,n)) return printf("%d\n",ans),0;
		n=ans;
	}
	return 0;
}