#include<bits/stdc++.h>
#define P1 "Ashishgup"
#define P2 "FastestFinger"
using namespace std;
bool isprime(int X)
{
	for(int i=2;i<=sqrt(X);i++)
		if(X%i==0)
			return false;
	return true;
}
void Solve()
{
	int N;
	cin>>N;
	if(N==1)
	{
		puts(P2);
		return ;
	}
	if(N==2)
	{
		puts(P1);
		return ;
	}
	int Exp=0,Lef=N;
	while(Lef%2==0)
	{
		Lef/=2;
		Exp++;
	}
	if(Exp==0)
	{
		puts(P1);
		return ;
	}
	if(Exp==1)
	{
		if(isprime(Lef))
			puts(P2);
		else	puts(P1);
		return ;
	}
	if(Lef==1)
		puts(P2);
	else	puts(P1);
	return ;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
		Solve();
}