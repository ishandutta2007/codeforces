#include<iostream>
using namespace std;

int main()
{
	int n,n1,n2,n4=0;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> n1 >> n2;
		if(n2-n1>1)
			n4++;
	}
	cout << n4;
}