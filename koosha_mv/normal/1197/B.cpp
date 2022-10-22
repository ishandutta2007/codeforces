#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int l=0,k=1,adadghabli,a,s=0;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(l!=0)
		{
		if(k==2)
		{
			if(a>=adadghabli)
			{
				s=1;
				break;
			}
		}
		if(k==1)
		{
			if(a<=adadghabli)
				k=2;
		}
		}
		
		adadghabli=a;
		l++;
	}
	if(s==0)
		cout<<"YES";
	else
		cout<<"NO";
}