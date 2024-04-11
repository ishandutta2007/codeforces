#include<iostream>
using namespace std;
int main()
{
	int n,x=0,y;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>y;
		if(y%2==0)
			cout<<y/2<<endl;
		else
		{
			if(x==0){
				x=1;
				cout<<float(y)/2+0.5<<endl;
			}
			else{
				x=0;
				cout<<float(y)/2-0.5<<endl;
			}
		}
	}
}