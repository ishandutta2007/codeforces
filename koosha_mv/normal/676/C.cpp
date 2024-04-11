#include<iostream>
using namespace std;
int main()
{
	int n,k,s1,s2,tb=0,m=0;
	string s;
	cin>>n>>k;
	cin>>s;
	s1=0;
	s2=0;
	if(s[0]=='b')
		tb=1;
	while(s2<s.size() && s1<s.size())
	{
		if(tb<=k)
		{
			m=max(m,s2-s1+1);
			s2++;
			if(s[s2]=='b')
				tb++;
		}
		else
		{
			if(s[s1]=='b')
				tb--;
			s1++;
		}
	}
	s1=0;
	s2=0;
	tb=0;
	if(s[0]=='a')
		tb=1;
	while(s2<s.size() && s1<s.size())
	{
		if(tb<=k)
		{
			m=max(m,s2-s1+1);
			s2++;
			if(s[s2]=='a')
				tb++;
		}
		else
		{
			if(s[s1]=='a')
				tb--;
			s1++;
		}
	}	
	cout<<m;
}