#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
typedef long long int ll;
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		string s,t;
		cin>>s>>t;
		int ns=0,nt=0;
		vector<int> as,at;
		FOR(i,0,n)
		{
			if(s[i]!=t[i])
			{
				if(s[i]=='a')
				{
					ns++;
					as.push_back(i+1);
					
				}
				else
				{
					nt++;
					at.push_back(i+1);
				}
			}
		}
		if((nt+ns)%2==0)
		{
			n=(nt+ns)/2+nt%2;
			cout<<n<<'\n';
			int v=ns/2;
			FOR(i,0,v)
			cout<<as[2*i]<<' '<<as[2*i+1]<<'\n';
			v=nt/2;
			FOR(i,0,v)
			cout<<at[2*i]<<' '<<at[2*i+1]<<'\n';
			if(ns%2==1)
			{
				cout<<at[nt-1]<<' '<<at[nt-1]<<'\n';
				cout<<at[nt-1]<<' '<<as[ns-1];
				
			}
		}
		else
		cout<<-1;
		
	}
	return 0;
}