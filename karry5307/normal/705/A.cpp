#include<bits/stdc++.h>
using namespace std;
int num;
int main()
{
	cin>>num;
	for(register int i=0;i<num;i++)
	{
		if(i%2==0)
		{
			cout<<"I hate ";
		}
		else
		{
			cout<<"I love ";
		}
		if(i==num-1)
		{
			cout<<"it";
		}
		else
		{
			cout<<"that ";
		}
	}
}