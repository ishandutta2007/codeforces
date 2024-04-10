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
#define PI 3.14159265358979323846265
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
int main()
{
	int K,N,T;
	cin>>N>>K>>T>>T;
	while(T--)
	{
		int oper;
		cin>>oper;
		if(oper==1)
		{
			N++;
			int pos;
			cin>>pos;
			if(pos<=K)
				K++;
		}
		else
		{
			int pos;
			cin>>pos;
			if(pos>=K)
				N=pos;
			else
			{
				N-=pos;
				K-=pos;
			}
		}
		cout<<N<<" "<<K<<endl;
	}
	return 0;
}