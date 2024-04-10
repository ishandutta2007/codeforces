#include<iostream>
#include<algorithm>
#include<string>
#include<functional>
#include<utility>
#include<ctime>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<deque>
#include<map>
#include<cstring>
#include<stack>
#include<cctype>
#include<cstdio>
#include<bitset>
#ifdef LOCAL
	#define enu(i,n) for(int i=0;i<n;i++)
	#define tri(x) x*(x+1)/2;
	#define sqrsum(x) x*(x+1)*(2*x+1)/6;
	#define sqrsum_range(a,b) sqrsum(b)-sqrsum(a-1);
#endif
#define FOR(i,a,b) for(int i=a,_b=b;i<_b;i++)
#define REP(i,a,b) FOR(i,a,b+1)
#define ll_max 9223372036854775807LL
#define ll_min -9223372036854775808LL
#define int_max 2147483647
#define int_min -2147483648
#define PI 3.141592653589793238462653383
#define eps 0.00000001
#define elif else if
using namespace std;
void fast()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	return ;
}
bool isprime(int x)
{
	if(x<2)
		return false;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return false;
	return true;
}
int GCD(int a,int b)
{
	return (b?GCD(b,a%b):a);
}
struct Tm
{
	int h,m,s;
	bool add()
	{
		s++;
		if(s==60)
			m++,
			s=0;
		if(m==60)
			h++,
			m=0;
		return (h<100);
	}
	void print()
	{
		printf("%02d:%02d:%02d",h,m,s);
		return ;
	}
	void println()
	{
		print();
		puts("");
	}
};
bool dp[220][220];
int main()
{
	string S,T;
	cin>>S>>T;
	int N=S.length();
	for(int i=N;i;i--)
		REP(j,0,N-i)
		{
			memset(dp,0,sizeof(dp));
			string U=S.substr(0,j)+S.substr(j+i);
			REP(k,0,U.length())
				dp[k][0]=true;
			REP(k,1,U.length())
				REP(l,1,T.length())
					if(U[k-1]==T[l-1])
						dp[k][l]=dp[k-1][l]|dp[k-1][l-1];
					else	dp[k][l]=dp[k-1][l];
			if(dp[U.length()][T.length()])
			{
				cout<<i<<endl;
				return 0;
			}
		}
	puts("0");
	return 0;
}