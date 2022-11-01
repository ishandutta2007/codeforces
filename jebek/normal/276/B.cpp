#include<iostream>
#include<conio.h>
#include<string>

using namespace std;
int main()
{
	string s;
	int x=0,a[1000]={0};
	cin>>s;
	for(int i=0;i<s.size()-1;i++)
	{
		for(int j=i+1;j<s.size();j++)
		{
			if((a[i]==0)&&(a[j]==0))
				if(s[i]==s[j])
				{
					a[i]=1;
					a[j]=1;
					x+=2;
				}
		}
	}
	if(x==s.size())
		cout<<"First";
	else if((s.size()-x)%2==0)
		cout<<"Second";
	else
		cout<<"First";
}