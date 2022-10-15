#include<bits/stdc++.h>
using namespace std;
int Pre[1001000],Min[1001000];
void Solve()
{
	string S;
	cin>>S;
	for(int i=0;i<S.length();i++)
	{
		Pre[i+1]=Pre[i];
		if(S[i]=='-')
			Pre[i+1]--;
		else	Pre[i+1]++;
		Min[i+1]=max(Min[i],Pre[i+1]*-1);
	}
	long long Ans=0;
	for(int i=0;i<=S.length();i++)
	{
		int Tmp=lower_bound(Min,Min+S.length()+1,i+1)-Min-1;
		Tmp++;
		//cout<<i<<" "<<Tmp<<endl;
		if(Tmp>S.length())
		{
			Ans+=Tmp-1;
			break;
		}
		else	Ans+=Tmp;
	}
	cout<<Ans<<endl;
	return ;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
		Solve();
}