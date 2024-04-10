#include<bits/stdc++.h>
using namespace std;
int X[100100],P;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		P=0;
		string S;
		cin>>S;
		int Ans=0;
		for(int i=0;i<S.length();i++)
			if(S[i]=='0')
				Ans++;
		Ans=min(Ans,(int)(S.length())-Ans);
		if(Ans%2)
			puts("DA");
		else	puts("NET");
	}
	return 0;
}