#include<iostream>
using namespace std;
int main()
{
	int n1=0,n2;
	cin >> n2;
	n1+=n2/100;
	n2=n2%100;
	n1+=n2/20;
	n2=n2%20;
	n1+=n2/10;
	n2=n2%10;
	n1+=n2/5;
	n2=n2%5;
	n1+=n2/1;
	n2=n2%1;
	cout << n1;
}