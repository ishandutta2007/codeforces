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
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,a,b,flag;
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d%d",&n,&a,&b);
		if(a==1)
		{
			puts((n-1)%b!=0?"No":"Yes");
		}
		else
		{
			flag=0;ll mul=1;
			for(;mul<=n&&!flag;mul*=a) if((n-mul)%b==0) flag=1;
			puts(flag?"Yes":"No");
		}
	}
	return 0;
}