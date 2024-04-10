#include<bits/stdc++.h>
using namespace std;
int Npos[100100][26];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S,T;
		cin>>S>>T;
		for(int i=0;i<26;i++)
		{
			int Po=-1;
			for(int j=S.length()-1;j>=0;j--)
			{
				if(S[j]==i+'a')
					Po=j;
				Npos[j][i]=Po;
			}
		}
		int Ans=1,Po=0;
		bool Impo=false;
		for(int i=0;i<T.length();i++)
		{
			if(Npos[0][T[i]-'a']==-1)
			{
				puts("-1");
				Impo=true;
				break;
			}
			if(Npos[Po][T[i]-'a']==-1)
			{
				Ans++;
				Po=Npos[0][T[i]-'a']+1;
			}
			else	Po=Npos[Po][T[i]-'a']+1;
			if(Po==S.length()&&i!=T.length()-1)
				Ans++,
				Po=0;
		}
		if(!Impo)
			cout<<Ans<<endl;
	}
	return 0;
}