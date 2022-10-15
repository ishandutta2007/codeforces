#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long long N,K;
		cin>>N>>K;
		long long L1,L2,R1,R2;
		cin>>L1>>R1>>L2>>R2;
		if(R2<R1)
		{
			swap(L1,L2);
			swap(R1,R2);
		}
		if(L2<=L1)
		{
			K-=(R1-L1)*N;
			if(K<=0)
			{
				puts("0");
				continue;
			}
			long long Cost1=R2-L2-R1+L1;
			Cost1*=N;
			if(K<=Cost1)
			{
				cout<<K<<endl;
				continue;
			}
			cout<<Cost1+2*(K-Cost1)<<endl;
		}
		else if(L2<=R1)
		{
			K-=(R1-L2)*N;
			if(K<=0)
			{
				puts("0");
				continue;
			}
			long long Cost1=(R2-L1)-(R1-L2);
			Cost1*=N;
			if(K<=Cost1)
			{
				cout<<K<<endl;
				continue;
			}
			cout<<Cost1+2*(K-Cost1)<<endl;
		}
		else
		{
			long long Useless=L2-R1;
			long long Useful=R2-L1;
			long long Ans=1e18;
			for(long long i=1;i<=N;i++)
			{
				long long Already=Useful*(i-1);
				long long NowUse=K-Already;
				if(NowUse<=Useful)
				{
					Ans=min(Ans,max(NowUse,0ll)+Useful*(i-1)+Useless*i);
					//cout<<Ans<<" ";
					continue;
				}
				else
				{
					Ans=min(Ans,(K-Useful*i)*2+Useful*i+Useless*i);
					//cout<<Ans<<" ";
				}
			}
			cout<<Ans<<endl;
		}
	}
	return 0;
}