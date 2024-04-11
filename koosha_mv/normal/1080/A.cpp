#include<iostream>
using namespace std;
int main()
{
	int n,k;
	k=0;
	cin >> n >> k;
	cout << (((n*2)+(k-1))/k)+(((n*5)+(k-1))/k)+(((n*8)+(k-1))/k);
}