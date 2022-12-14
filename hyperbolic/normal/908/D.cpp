#include <stdio.h>
#include <algorithm>
#define MOD 1000000007

long long int inv(long long int k)
{
	long long int t = MOD-2;
	long long int s1 = k;
	long long int s2 = 1;
	while(t)
	{
		if(t%2==1) s2*=s1,s2%=MOD;
		s1*=s1,s1%=MOD,t/=2;
	}
	return s2;
}
typedef std::pair<long long int, long long int> frac;
frac P1,P2,one;
long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}
frac operator+(frac A, frac B)
{
	frac C;
	C.first = (A.first*B.second+A.second*B.first);
	C.second = (A.second*B.second);
	double g = gcd(C.first,C.second);
	C.first/=g, C.second/=g;
	C.first%=MOD, C.second%=MOD;
	return C;
}
frac operator-(frac A, frac B)
{
	frac C;
	C.first = (A.first*B.second-A.second*B.first);
	C.second = (A.second*B.second);
	double g = gcd(C.first,C.second);
	C.first/=g, C.second/=g;
	C.first%=MOD, C.second%=MOD;
	return C;
}
frac operator*(frac A, frac B)
{
	frac C;
	C.first = (A.first*B.first);
	C.second = (A.second*B.second);
	double g = gcd(C.first,C.second);
	C.first/=g, C.second/=g;
	C.first%=MOD, C.second%=MOD;
	return C;
}
frac operator/(frac A, frac B)
{
	frac C;
	C.first = (A.first*B.second);
	C.second = (A.second*B.first);
	double g = gcd(C.first,C.second);
	C.first/=g, C.second/=g;
	C.first%=MOD, C.second%=MOD;
	return C;
}
int a;
frac check[1010][1010];
int check2[1010][1010];
frac func(int s, int t)
{
	if(s>=a) return std::make_pair(s,1);
	if(check2[s][t]) return check[s][t];
	if((a-s)<=t)
	{
		frac T1 = std::make_pair(s+t-1,1);
		T1 = (T1*P2)/(one-P1);
		frac T2 = (P2/(one-P1));
		T2 = (T2/(one-P1));
		check2[s][t] = 1;
		return check[s][t] = T1+T2;
	}
	frac T1 = P1*func(s,t+1);
	frac T2 = P2*func(s+t,t);
	check2[s][t] = 1;
	return check[s][t] = T1+T2;
}
int main()
{
	one = std::make_pair(1,1);
	int b,c;
	scanf("%d%d%d",&a,&b,&c);
	P1 = std::make_pair(b,b+c);
	P2 = std::make_pair(c,b+c);
	frac ans = (P1/(one-P2))*func(0,1);
	printf("%I64d",(ans.first*inv(ans.second))%MOD);
}