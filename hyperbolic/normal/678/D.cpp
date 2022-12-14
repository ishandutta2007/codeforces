#include <stdio.h>
#include <map>
#define MOD 1000000007
struct str{
	long long int A;
	long long int B;
	// Ax + B
};
std::map<long long int,str> M;
int a,b,d;
str func(long long int k)
{
	if(k==1)
	{
		str S;
		S.A = a;
		S.B = b;
		return S;
	}
	if(M.find(k)!=M.end()) return M[k];
	long long int s = k/2;
	
	str s1 = func(k-s);
	str s2 = func(s);
	// C(Ax+B)+D
	
	str S;
	S.A = (s1.A * s2.A)%MOD;
	S.B = (s1.A * s2.B + s1.B)%MOD;
	return M[k]=S;
}
int main()
{
	long long int c;
	scanf("%d%d%I64d%d",&a,&b,&c,&d);
	str S = func(c);
	printf("%I64d",(S.A * d + S.B)%MOD);
}