#include<iostream>
using namespace std;
int main()
{
	float n1,n2,n3=0;
	cin >> n1;
	for(int i=0;i<n1;i++)
	{
		cin >> n2;
		n3+=n2;
	}
	cout << n3 /n1;

}