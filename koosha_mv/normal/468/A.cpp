using namespace std;
#include<iostream>
int main()
{
	int n;
	cin >> n;
	if(n>=4)
	{
		cout<<"YES"<<endl;
		if(n%2==0)
		{
			cout<<"1 * 2 = 2"<<endl;
			cout<<"2 * 3 = 6"<<endl;
			cout<<"6 * 4 = 24"<<endl;
		
		for(int i=5;i<n;i+=2)
		{
			cout<<i+1<<" - "<<i<<" = 1"<<endl;
		}
		for(int i=0;i<(n-4)/2;i++)
		{
			cout<<"24 * 1 = 24"<<endl;
		}
		}
		else
		{
			cout<<"4 * 5 = 20"<<endl;
			cout<<"2 + 3 = 5"<<endl;
			cout<<"20 + 5 = 25"<<endl;
			cout<<"25 - 1 = 24"<<endl;
		
		for(int i=6;i<n;i+=2)
		{
			cout<<i+1<<" - "<<i<<" = 1"<<endl;
		}
		for(int i=0;i<(n-5)/2;i++)
		{
			cout<<"24 * 1 = 24"<<endl;
		}
		}
		
	}
	else
		cout<<"NO";

	
}