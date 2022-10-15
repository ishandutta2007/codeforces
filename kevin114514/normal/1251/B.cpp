#include<bits/stdc++.h>
using namespace std;
int main()
{
	int Q;
	cin>>Q;
	while(Q--)
	{
		int N;
		cin>>N;
		int w=0;
		int ans=0;
		bool ok=false;
		for(int i=0;i<N;i++)
		{
			string S;
			cin>>S;
			ans+=S.length();
			if(S.length()%2==1)
				ok=true;
			for(int i=0;i<S.length();i++)
				if(S[i]=='0')
					w++;
		}
		w%=2;
		ans%=2;
		if(ans||w==ans||ok)
			cout<<N<<endl;
		else	cout<<N-1<<endl;
	}
	return 0;
}