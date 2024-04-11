using namespace std;
#include<iostream>
int main()
{
	float n,m;
	cin >> n >> m;
	int k=0;
	while(n<=m)
	{
		n=n*1.5;
		k++;
	}
	cout << k;
}