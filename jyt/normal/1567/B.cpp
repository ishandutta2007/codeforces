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
int T,a,b,Xor[N];
int main()
{
	for(int i=1;i<=N-5;i++) Xor[i]=Xor[i-1]^i;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&a,&b);
		if(Xor[a-1]==b) {printf("%d\n",a);continue;}
		if(b^Xor[a-1]^a) {printf("%d\n",a+1);continue;}
		printf("%d\n",a+2);
	}
	return 0;
}