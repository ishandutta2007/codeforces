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
using namespace std;
class PROGRAM
{
	public:
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
};
int A[200200],N,M,K;
int main()
{
	cin>>N>>M>>K;
	for(int i=1;i<=N;i++)
		cin>>A[i];
	int m=M,k=0,i;
	for(i=N;i>=1&&(m||(m==0&&k>=A[i]));i--)
	{
		if(K<A[i])
			break;
		if(k<A[i])
		{
			m--;
			k=K-A[i];
		}
		else	k-=A[i];
	}
	cout<<N-i<<endl;
	return 0;
}