#include<bits/stdc++.h>
using namespace std;
void Solve()
{
	long long A,B,C;
	cin>>A>>B>>C;
	long long Delta=B-A;
	for(long long i=A;i<=B;i++)
	{
		long long Rem=C%i;
		if(Rem+Delta>=i)
		{
			cout<<i<<" "<<A<<" "<<A+i-Rem<<endl;
			return ;
		}
		if(Rem<=Delta&&i<=C)
		{
			cout<<i<<" "<<A+Rem<<" "<<A<<endl;
			return ;
		}
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--)
		Solve();
	return 0;
}