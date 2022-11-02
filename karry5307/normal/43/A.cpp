#include<bits/stdc++.h>
using namespace std;
string str,str1,temp;
int a,a1,cnt;
int main()
{
	cin>>cnt;
	for(register int i=0;i<cnt;i++)
	{
		cin>>temp;
		if(str!=temp)
		{
			if(str1!=temp)
			{
				if(str.empty())
				{
					str=temp;
					a++;
				}
				else
				{
					str1=temp;
					a1++;
				}
			}
			else
			{
				a1++;
			}
		}
		else
		{
			a++;
		}
	}
	if(a>a1)
	{
		cout<<str;
	}
	else
	{
		cout<<str1;
	}
}