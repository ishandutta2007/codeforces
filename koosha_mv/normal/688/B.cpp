#include<iostream>
using namespace std;
int main()
{
	string n;
	cin >> n;
	cout << n;
	for(int i=n.size()-1;i>-1;i--)
		cout << n[i];
}