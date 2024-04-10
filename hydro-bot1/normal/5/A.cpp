// Hydro submission #6263f2379f31360077dcab8a@1650717239628
#include<bits/stdc++.h>
using namespace std;
int flow=0,now=0;
string s;
int main()
{
	while(getline(cin,s))
	{
		if(s[0]=='+') now++;
		else if(s[0]=='-') now--;
		else
		{
			for(int i=0;i<s.size();i++)
			{
				if(s[i]==':')
				{
					flow+=(s.size()-i-1)*now;
					break;
				}
			}
		}
	}
	
	cout<<flow;
	return 0;
}