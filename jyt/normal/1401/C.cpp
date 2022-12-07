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
int T,n,A[N],B[N],G,flag;
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int main()
{
	for(scanf("%d",&T);T--;G=flag=0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]),B[i]=A[i];
		std::sort(B+1,B+1+n);
		for(int i=1;i<=n;i++) if(A[i]^B[i]) G=gcd(G,B[i]);
		puts(G%B[1]?"NO":"YES");
	}
	return 0;
}