#include<bits/stdc++.h>
using namespace std;
int A[100100],B[100100];
bool OK[100100];
int Min[22];
void Solve()
{
	memset(OK,false,sizeof(OK));
	int N;
	cin>>N;
	string S,T;
	cin>>S>>T;
	for(int i=0;i<N;i++)
	{
		A[i]=S[i]-'a';
		B[i]=T[i]-'a';
		if(A[i]>B[i])
		{
			puts("-1");
			return ;
		}
		if(A[i]==B[i])
			OK[i]=true;
	}
	int Cnt=0;
	while(true)
	{
		for(int i=0;i<22;i++)
			Min[i]=1000;
		int Mini=100;
		bool Alr=true;
		for(int i=0;i<N;i++)
			if(!OK[i])
			{
				Alr=false;
				Mini=min(Mini,A[i]);
				Min[A[i]]=min(B[i],Min[A[i]]);
			}
		if(Alr)
			break;
		Cnt++;
		for(int i=0;i<N;i++)
			if(A[i]==Mini&&!OK[i])
			{
				A[i]=Min[Mini];
				if(A[i]==B[i])
					OK[i]=true;
			}
	}
	cout<<Cnt<<endl;
	return ;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
		Solve();
	return 0;
}