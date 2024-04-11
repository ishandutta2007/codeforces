#include<iostream>
using namespace std;
int main()
{
	string s;
	cin>>s;
	if(s.length()%2==0)
		cout<<(s.length())/2;	
	else
	{
		int t=0;
		for(int i=1;i<s.length();i++)
		{
			if(s[i]=='1')
				t=1;
		}
		if(t==0)
			cout<<(s.length()-1)/2;
		else
			cout<<(s.length()-1)/2+1;
	}
}