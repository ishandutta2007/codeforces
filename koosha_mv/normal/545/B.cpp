#include<iostream>
using namespace std;
int main()
{
	int t=0;
	string s1,s2,kh="";
	cin>>s1>>s2;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!=s2[i])
		{
			t++;
			if(t%2==0)
			{
				kh+=s1[i];
			}
			else
			{
				kh+=s2[i];
			}
		}
		else
		{
			kh+='0';
		}
	}
	if(t%2==0)
		cout<<kh;
	else
		cout<<"impossible";
}