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
#define N 105
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,A[N],An,Sum;
void clear()
{
	An=Sum=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d%d",&m,&n);
		for(int x=m;x;x/=10) A[++An]=x%10,Sum+=A[An];
		for(;Sum<n;)
			for(int i=2;i<=An;i++) if(A[i]>0) {A[i]--,A[i-1]+=10,Sum+=9;break;}
		for(int i=1;i<=An;i++)
			for(;A[i]>9;A[i]--,n--)
			{
				putchar('1');
				for(int j=i-1;j;j--) putchar('0');
				printf(" ");
			}
		for(int i=An;i;)
		{
			if(!A[i]) {i--;continue;}
			if(n>1)
			{
				printf("1");
				for(int j=i-1;j;j--) putchar('0');
				printf(" "),n--,A[i]--;
			}
			else
			{
				for(int j=i;j;j--) printf("%d",A[j]);
				puts("");break;
			}
		}
	}
	return 0;
}