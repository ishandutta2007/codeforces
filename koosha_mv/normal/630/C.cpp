#include<iostream>
using namespace std;
int main()
{
	int n;
	long long k=0;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		long long o=1;
		for(int j=0;j<i;j++)
			o=o*2;
		k+=o;
	}
	cout << k;
}