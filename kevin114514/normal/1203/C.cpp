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
long long GCD(long long a,long long b)
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
long long get_n(long long x)
{
	long long res=1;
	for(int i=2;i<=sqrt(x);i++)
	{
		int cnt=1;
		while(x%i==0)
		{
			x/=i;
			cnt++;
		}
		res*=cnt;
	}
	if(x>1)
		res*=2LL;
	return res;
}
int main()
{
	int N;
	cin>>N;
	long long res;
	cin>>res;
	while(--N)
	{
		long long x;
		cin>>x;
		res=GCD(res,x);
	}
	cout<<get_n(res)<<endl;
	return 0;
}