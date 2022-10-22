#include<iostream>
using namespace std;
int main()
{
	int n=0,n1=0,n2=0;
	cin >> n ;
	for(int i=0;i<n;i++)
	{
		cin >> n1;
		if(n1==1)
			n2=1;
	}
	if(n2==1)
		cout << "HARD";
	else
		cout << "EASY";
}