#include<iostream>
using namespace std;
int array[101]={0};
int main()
{
	int a,b;
	cin >> a >> b;	
	
	for(int i=0;i<=b;i++)
	{
		array[i]=i;
	}
	for(int i=0;i<a;i++)
	{
		int c,d;
		cin >> c >> d;
		for(int j=c;j<=d;j++)
		{
			array[j]=0;
	 	}
	}
	int q;
	q=0;
	int s;
	s=0;
	for(int i=0;i<=b;i++)
	{
		if (array[i]!=0)
		{
			q++;
		}
	}
	cout<<q<<endl;
	for(int i=0;i<=b;i++)
	{
		if (array[i]!=0)
		{
			if(s==0)
			{
				cout<<array[i];
			}
			else
			{
				cout<<' '<<array[i];
			}
			s+=1;
		}	

	}
}