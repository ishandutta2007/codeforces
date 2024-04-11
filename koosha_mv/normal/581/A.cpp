#include<iostream>
using namespace std;
int main()
{
	int n1, n2;
	cin >> n1 >> n2;
	if(n1 > n2)
	{
		int n3 = n1;
		n1 = n2;
		n2 = n3;
	}
	cout << n1 << " " << (n2 - n1) / 2;

}