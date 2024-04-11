#include<iostream>
using namespace std;
int main()
{
	int t=0;
	string s1,s2,s="";
	cin>>s1>>s2;
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]<s2[i])
		{
			t=1;
			break;
		}
		s+=s2[i];
	}
	if(t==1)
		cout<<-1;
	else
		cout<<s;
}