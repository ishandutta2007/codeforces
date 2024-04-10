#include<bits/stdc++.h>
using namespace std;
int X[300300];
char C[300300];
int main()
{
	string S;
	cin>>S;
	int P=0,cnt=0;
	char lst=S[0];
	for(int i=0;i<S.length();i++)
		if(S[i]==lst)
			cnt++;
		else
		{
			C[P]=S[i-1];
			X[P++]=cnt;
			cnt=1;
			lst=S[i];
		}
	C[P]=S[S.length()-1];
	X[P++]=cnt;
	if(P%2==0)
	{
		puts("0");
		return 0;
	}
	X[P/2]++;
	if(X[P/2]<3)
	{
		puts("0");
		return 0;
	}
	for(int i=0;i<P/2;i++)
		if(C[i]!=C[P-i-1]||X[i]+X[P-i-1]<3)
		{
			puts("0");
			return 0;
		}
	cout<<X[P/2]<<endl;
	return 0;
}