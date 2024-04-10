#include<bits/stdc++.h>
using namespace std;
char C[3]={'R','D','U'};
int main()
{
	int N,M,K,XXX;
	cin>>N>>M>>K;
	XXX=K;
	int X=4*N*M-N-N-M-M;
	if(K>X)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int CNT=0;
	for(int i=1;i<N;i++)
	{
		int Cnt=0;
		for(int j=1;j<M&&K>3;j++)
		{
			K-=3;
			Cnt++;
		}
		//cout<<Cnt<<" RDU\n";
		if(Cnt)
		CNT++;
		if(Cnt!=M-1&&K)
		{
			//cout<<"1 ";
			//for(int i=0;i<K;i++)
			//	cout<<C[i];
			//puts("");
			CNT++;
			K=0;
		}
		Cnt=min(M-1,K);
		if(Cnt)
		//cout<<Cnt<<" L\n";
		CNT++;
		K-=Cnt;
		if(K)
		{
			//cout<<"1 D\n";
			CNT++;
			K--;
		}
	}
	int Cnt=min(M-1,K);
	K-=Cnt;
	//cout<<Cnt<<" R\n";
	if(Cnt)
	CNT++;
	Cnt=min(M-1,K);
	K-=Cnt;
	//cout<<Cnt<<" L\n";
	if(Cnt)
	CNT++;
	Cnt=min(N-1,K);
	K-=Cnt;
	if(Cnt)
	//cout<<Cnt<<" U\n";
	CNT++;
	
	K=XXX;
	cout<<CNT<<endl;
	if(CNT>3000)
	{
		puts("Denial:Too many operations!");
		return 0;
	}
	for(int i=1;i<N;i++)
	{
		int Cnt=0;
		for(int j=1;j<M&&K>3;j++)
		{
			K-=3;
			Cnt++;
		}
		if(Cnt)
		cout<<Cnt<<" RDU\n";
		if(Cnt!=M-1&&K)
		{
			cout<<"1 ";
			for(int i=0;i<K;i++)
				cout<<C[i];
			puts("");
			K=0;
		}
		Cnt=min(M-1,K);
		if(Cnt)
		cout<<Cnt<<" L\n";
		K-=Cnt;
		if(K)
		{
			cout<<"1 D\n";
			K--;
		}
	}
	Cnt=min(M-1,K);
	K-=Cnt;
	if(Cnt)
	cout<<Cnt<<" R\n";
	Cnt=min(M-1,K);
	K-=Cnt;
	if(Cnt)
	cout<<Cnt<<" L\n";
	Cnt=min(N-1,K);
	K-=Cnt;
	if(Cnt)
	cout<<Cnt<<" U\n";
	return 0;
}