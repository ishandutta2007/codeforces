#include<bits/stdc++.h>
using namespace std;
int Next[200200][3];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		for(int i=0;i<=S.length();i++)
			Next[i][0]=Next[i][1]=Next[i][2]=-1;
		for(int i=S.length()-1;i>=0;i--)
			for(int j=0;j<3;j++)
				if(S[i]=='1'+j)
					Next[i][j]=i;
				else	Next[i][j]=Next[i+1][j];
		int Min=S.length()+1;
		int F=-1,L=-1;
		for(int i=0;i<S.length();i++)
		{
			bool OK=true;
			int Max=0;
			for(int j=0;j<3;j++)
				if(Next[i][j]==-1)
					OK=false;
				else	Max=max(Max,Next[i][j]);
			if(OK)
				Min=min(Min,Max-i+1);
		}
		if(Min==S.length()+1)
			puts("0");
		else	cout<<Min<<endl;
	}
	return 0;
}