#include<iostream>
using namespace std;
int main()
{
	int n,n1,n2,n3=0;
	cin >> n >> n1;
	n3=n;
	for(int i=0;i<n;i++)
	{
		cin >> n2;
		if(n2 > n1)
			n3++;
	}
	cout << n3;
}