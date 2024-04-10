#include<bits/stdc++.h>
using namespace std;
long long gcd(long long A,long long B)
{
	return (B?gcd(B,A%B):A);
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long A,M;
		cin>>A>>M;
		long long X=gcd(A,M);
		A/=X;
		M/=X;
		int Po=0;
		long long Ans=M;
		for(int i=2;i<=sqrt(M);i++)
			if(M%i==0)
			{
				while(M%i==0)
					M/=i;
				Ans-=Ans/i;
			}
		if(M>1)
			Ans-=Ans/M;
		cout<<Ans<<endl;
	}
	return 0;
}