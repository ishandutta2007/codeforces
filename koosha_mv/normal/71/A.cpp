#include<iostream>
#include<string>
using namespace std;
int main()
{
	int a;
	string c[100];

	cin >> a;
	for(int i=0;i<a;i++)
	{
		cin >> c[i];

	}
	for(int i=0;i<a;i++)
	{
		if (c[i].size()<=10)
			cout << c[i]<<endl;
		else
		{
			cout << c[i][0] << c[i].size()-2 << c[i][c[i].size()-1]<<endl;
		}
	}
	
}